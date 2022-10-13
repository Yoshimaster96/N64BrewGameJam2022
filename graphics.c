#include "graphics.h"

////////////
//GRAPHICS//
////////////
const Vp vp = {
	SCREEN_WD*2,SCREEN_HT*2,G_MAXZ/2,0,
	SCREEN_WD*2,SCREEN_HT*2,G_MAXZ/2,0,
};
Lights1 lights = gdSPDefLights1(0x00,0x33,0x66,
	0xFF,0xCC,0x99,
	64,90,64);
const Gfx gfxInit[] = {
	//Init RSP state
	gsSPViewport(&vp),
	gsSPClearGeometryMode(0xFFFFFFFF),
	gsSPTexture(0,0,0,0,G_OFF),
	gsSPSetLights1(lights),
	gsSPFogPosition(996,1000),
	//Init RDP state
	gsDPSetRenderMode(G_RM_OPA_SURF,G_RM_OPA_SURF2),
	gsDPSetColorDither(G_CD_BAYER),
	gsDPSetFogColor(0x00,0x00,0x00,0xFF),
	gsDPSetScissor(G_SC_NON_INTERLACE,0,0,SCREEN_WD-1,SCREEN_HT-1),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx dlBuf[GFX_GTASK_NUM][GFX_GLIST_LEN];
Gfx * dlPtr;
TDynamic dynBuf[GFX_GTASK_NUM];
TDynamic * dynPtr;
u8 bufferId = 0;

//Init display
void graphics_init() {
	dlPtr = &dlBuf[bufferId][0];
	dynPtr = &dynBuf[bufferId];
	gSPSegment(dlPtr++,0x00,0);
	gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(gfxInit));
}
//Clear buffers
void graphics_clear() {
	gDPSetDepthImage(dlPtr++,OS_K0_TO_PHYSICAL(nuGfxZBuffer));
	gDPPipeSync(dlPtr++);
	gDPSetCycleType(dlPtr++,G_CYC_FILL);
	gDPSetColorImage(dlPtr++,G_IM_FMT_RGBA,G_IM_SIZ_16b,SCREEN_WD,
		OS_K0_TO_PHYSICAL(nuGfxZBuffer));
	gDPSetFillColor(dlPtr++,GPACK_ZDZ(G_MAXFBZ,0)<<16 | GPACK_ZDZ(G_MAXFBZ,0));
	gDPFillRectangle(dlPtr++,0,0,SCREEN_WD-1,SCREEN_HT-1);
	gDPPipeSync(dlPtr++);
	gDPSetColorImage(dlPtr++,G_IM_FMT_RGBA,G_IM_SIZ_16b,SCREEN_WD,
		osVirtualToPhysical(nuGfxCfb_ptr));
	gDPSetFillColor(dlPtr++,GPACK_RGBA5551(0x00,0x00,0x00,1)<<16 | GPACK_RGBA5551(0x00,0x00,0x00,1));
	gDPFillRectangle(dlPtr++,0,0,SCREEN_WD-1,SCREEN_HT-1);
	gDPPipeSync(dlPtr++);
}
//Setup render settings
void graphics_setup() {
	gDPSetCycleType(dlPtr++,G_CYC_1CYCLE);
	gSPClearGeometryMode(dlPtr++,0xFFFFFFFF);
	gSPSetGeometryMode(dlPtr++,G_LIGHTING|G_ZBUFFER|G_SHADE|G_SHADING_SMOOTH|G_CULL_BACK);
	gDPSetRenderMode(dlPtr++,G_RM_AA_ZB_OPA_SURF,G_RM_AA_ZB_OPA_SURF2);
	gDPSetColorDither(dlPtr++,G_CD_BAYER);
	gDPSetCombineMode(dlPtr++,G_CC_MODULATERGBA,G_CC_MODULATERGBA);
	gDPSetTexturePersp(dlPtr++,G_TP_PERSP);
	gDPSetTextureLOD(dlPtr++,G_TL_TILE);
	gDPSetTextureFilter(dlPtr++,G_TF_POINT);
	gDPSetTextureConvert(dlPtr++,G_TC_FILT);
	gDPSetTextureLUT(dlPtr++,G_TT_NONE);
	gSPTexture(dlPtr++,0x8000,0x8000,0,G_TX_RENDERTILE,G_ON);
}
//Setup view matrix
void graphics_view(float* camEye,float* camCenter,float* camUp) {
	u16 norm;
	LookAt lookat;
	//Calculate matrix
	guPerspective(&dynPtr->mProj,&norm,
		45,(float)SCREEN_WD/(float)SCREEN_HT,10,10000,1.0);
	guLookAtReflect(&dynPtr->mView,&lookat,
		camEye   [0],camEye   [1],camEye   [2],
		camCenter[0],camCenter[1],camCenter[2],
		camUp    [0],camUp    [1],camUp    [2]);
	gSPPerspNormalize(dlPtr++,norm);
	gSPLookAt(dlPtr++,&lookat);
	gSPMatrix(dlPtr++,&dynPtr->mProj,G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,&dynPtr->mView,G_MTX_PROJECTION|G_MTX_MUL |G_MTX_NOPUSH);
}
//Setup rotate matrix
void graphics_rotate(Mtx* m,float x,float y,float z) {
	float mf[4][4];
	float sx,cx;
	float sy,cy;
	float sz,cz;
	//Calculate sin/cos
	sx = sin(x);
	cx = cos(x);
	sy = sin(y);
	cy = cos(y);
	sz = sin(z);
	cz = cos(z);
	//Calculate matrix
	guMtxIdentF(mf);
	mf[0][0] = (cy*cz)-(sx*sy*sz);
	mf[0][1] = (cy*sz)+(cz*sx*sy);
	mf[0][2] = -cx*sy;
	mf[1][0] = -cx*sz;
	mf[1][1] = cx*cz;
	mf[1][2] = sx;
	mf[2][0] = (cz*sy)+(cy*sx*sz);
	mf[2][1] = (sy*sz)-(cy*cz*sx);
	mf[2][2] = cx*cy;
	guMtxF2L(mf,m);
}
//End display
void graphics_end(u32 flag) {
	gDPFullSync(dlPtr++);
	gSPEndDisplayList(dlPtr++);
	//assert((dlPtr-dlBuf[bufferId])<GFX_GLIST_LEN);
	nuGfxTaskStart(&dlBuf[bufferId][0],(s32)(dlPtr-dlBuf[bufferId])*sizeof(Gfx),NU_GFX_UCODE_F3DEX,flag);
	if(flag==NU_SC_SWAPBUFFER) {
		bufferId++;
		bufferId %= GFX_GTASK_NUM;
	}
}
//End display (debug console)
void graphics_end_deb_con(u32 flag) {
	nuDebConDisp(flag);
	if(flag==NU_SC_SWAPBUFFER) {
		bufferId++;
		bufferId %= GFX_GTASK_NUM;
	}
}
