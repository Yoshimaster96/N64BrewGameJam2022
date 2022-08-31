#include "gm_play.h"

//TEST TEST TEST
const Vtx testVtx[] = {
	{ 0, 4, 0,0,0,0,0xFF,0x00,0x00,0xFF},
	{-4,-4, 0,0,0,0,0x00,0xFF,0x00,0xFF},
	{ 4,-4, 0,0,0,0,0x00,0x00,0xFF,0xFF},
};

void gm_play_disp_level() {
	//Calculate model matrix
	guTranslate(&dynPtr->mLevelPos,0.f,0.f,0.f);
	guRotateRPY(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale(&dynPtr->mLevelScl,1.f,1.f,1.f);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw level
	//TODO
	//TEST TEST TEST
	gSPVertex(dlPtr++,&testVtx[0],4,0);
	gDPPipeSync(dlPtr++);
	gDPSetCycleType(dlPtr++,G_CYC_1CYCLE);
	gDPSetRenderMode(dlPtr++,G_RM_AA_OPA_SURF,G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode(dlPtr++,0xFFFFFFFF);
	gSPSetGeometryMode(dlPtr++,G_SHADE|G_SHADING_SMOOTH);
	gSP1Triangle(dlPtr++,0,1,2,0);
}
void gm_play_disp_objs() {
	int i;
	for(i=0; i<OBJ_MAX; i++) {
		//Calculate model matrix
		//TODO
		//Draw object
		//TODO
	}
}

//////////////////////
//EXTERNAL FUNCTIONS//
//////////////////////
//Main gameplay display
void gm_play_disp() {
	float eye[3];
	float center[3];
	float up[3];
	//Setup camera position
	eye[0] = 0.f;
	eye[1] = 0.f;
	eye[2] = 16.f;
	center[0] = 0.f;
	center[1] = 0.f;
	center[2] = 0.f;
	up[0] = 0.f;
	up[1] = 1.f;
	up[2] = 0.f;
	//Init display
	graphics_init();
	graphics_clear();
	graphics_view(eye,center,up);
	//Draw level
	gm_play_disp_level();
	//Draw objects
	gm_play_disp_objs();
	//End display
	graphics_end();
}
//Main gameplay process
void gm_play_proc() {
	//TODO
}
