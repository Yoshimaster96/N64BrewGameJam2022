#include "graphics.h"

////////////
//GRAPHICS//
////////////
const Vp vp = {
	SCREEN_WD*2,SCREEN_HT*2,G_MAXZ/2,0,
	SCREEN_WD*2,SCREEN_HT*2,G_MAXZ/2,0,
};
Lights1 lights = gdSPDefLights1(0x51,0x51,0x51,
	0xFF,0xFF,0xFF,
	1,1,1);
const Gfx gfxInit[] = {
	//Init RSP state
	gsSPViewport(&vp),
	gsSPClearGeometryMode(G_ZBUFFER|G_SHADE|G_SHADING_SMOOTH|G_CULL_BOTH|G_FOG|G_LIGHTING),
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
	gDPSetFillColor(dlPtr++,GPACK_ZDZ(G_MAXFBZ,0)<<16 | GPACK_ZDZ(G_MAXFBZ,0)<<16);
	gDPFillRectangle(dlPtr++,0,0,SCREEN_WD-1,SCREEN_HT-1);
	gDPPipeSync(dlPtr++);
	gDPSetColorImage(dlPtr++,G_IM_FMT_RGBA,G_IM_SIZ_16b,SCREEN_WD,
		osVirtualToPhysical(nuGfxCfb_ptr));
	gDPSetFillColor(dlPtr++,GPACK_RGBA5551(0x00,0x00,0x00,1)<<16 | GPACK_RGBA5551(0x00,0x00,0x00,1)<<16);
	gDPFillRectangle(dlPtr++,0,0,SCREEN_WD-1,SCREEN_HT-1);
	gDPPipeSync(dlPtr++);
}
//Setup view matrix
void graphics_view(float* camEye,float* camCenter,float* camUp) {
	u16 norm;
	LookAt lookat;
	//Calculate matrix
	guPerspective(&dynPtr->mProj,&norm,
		33,(float)SCREEN_WD/(float)SCREEN_HT,10,10000,1.0);
	guLookAtReflect(&dynPtr->mView,&lookat,
		camEye[0],camEye[1],camEye[2],
		camCenter[0],camCenter[1],camCenter[2],
		camUp[0],camUp[1],camUp[2]);
	gSPPerspNormalize(dlPtr++,norm);
	gSPLookAt(dlPtr++,&lookat);
	gSPMatrix(dlPtr++,&dynPtr->mProj,G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,&dynPtr->mView,G_MTX_PROJECTION|G_MTX_MUL |G_MTX_NOPUSH);
}
//End display
void graphics_end() {
    gDPFullSync(dlPtr++);
    gSPEndDisplayList(dlPtr++);
	//assert((dlPtr-dlBuf[bufferId])<GFX_GLIST_LEN);
	nuGfxTaskStart(&dlBuf[bufferId][0],(s32)(dlPtr-dlBuf[bufferId])*sizeof(Gfx),NU_GFX_UCODE_F3DEX,NU_SC_SWAPBUFFER);
	bufferId++;
	bufferId %= GFX_GTASK_NUM;
}
