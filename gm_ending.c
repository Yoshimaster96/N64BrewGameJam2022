#include "gm_ending.h"

extern u8 joy1Pattern;
extern NUContData joy1Data;
extern u16 joy1ButtonPrev,joy1ButtonDown,joy1ButtonUp;

volatile extern int gameMode;
extern int gameSubmode;

//gm_play.c
extern int frenzyMode;
extern u8 frenzyFlags[7];

/////////////////////
//PROCESS FUNCTIONS//
/////////////////////
Gfx * scrEndingGfx = NULL;
int animScrEndingTime;
float animScrEndingScl;

const Gfx * endingTreasureGfxTable[7] = {
	gfx_obj_gem1,
	gfx_obj_gem2,
	gfx_obj_gem3,
	gfx_obj_gem4,
	gfx_obj_gmet1,
	gfx_obj_gmet2,
	gfx_obj_gpearl,
};
const float endingTreasurePosXTable[7] = {
	-1152.f,
	 -768.f,
	 -384.f,
	    0.f,
	  384.f,
	  768.f,
	 1152.f,
};
const float endingTreasureAnimOffsTable[7] = {
	2.0f,2.5f,3.0f,3.5f,4.0f,4.5f,5.0f,
};
float endingTreasurePosY[7];

//Animation curve process
float animcurve_scr_ending_scl(float t) {
	float dt;
	float a,b;
	if(t<0.f) return 0.f;
	  else if(t<0.5f) {
		return t*t*t*t;
	} else if (t<4.5f) {
		dt = t-0.5f;
		a = exp(-4.f*dt);
		b = sin(16.f*dt);
		return (a*b*0.5f)+1.f;
	} else return 1.f;
}
float animcurve_scr_ending_pos_y(float t) {
	float dt;
	if(t<0.f) return 4096.f;
	  else if(t<0.500000f) {
		dt = t-0.0000000f;
		return 4096.f-(16384.f*dt*dt);
	} else if(t<0.750000f) {
		dt = t-0.6250000f;
		return  256.f-(16384.f*dt*dt);
	} else if(t<0.812500f) {
		dt = t-0.7812500f;
		return   16.f-(16384.f*dt*dt);
	} else if(t<0.828125f) {
		dt = t-0.8203125f;
		return    1.f-(16384.f*dt*dt);
	} else return 0.f;
}

//Main ending process
void gm_ending_proc() {
	int i;
	float t;
	switch(gameSubmode) {
		//Init
		case 0: {
			//Load banks
			bank_load(3);
			//Load screen graphics
			scrEndingGfx = gfx_scr_ending;
			//Init animation
			animScrEndingTime = 0;
			animScrEndingScl = 0.f;
			for(i=0; i<7; i++) {
				endingTreasurePosY[i] = 4096.f;
			}
			gameSubmode = 1;
			break;
		}
		//Main loop
		case 1: {
			//Update animation
			t = ((float)animScrEndingTime)/60.f;
			animScrEndingScl = animcurve_scr_ending_scl(t);
			for(i=0; i<7; i++) {
				endingTreasurePosY[i] = animcurve_scr_ending_pos_y(t-endingTreasureAnimOffsTable[i]);
			}
			animScrEndingTime++;
			//Check for back to title
			if(t>10.f) {
				scrEndingGfx = NULL;
				gameMode = 0;
				gameSubmode = 0;
				nuGfxFuncRemove();
			}
			break;
		}
	}
}

/////////////////////
//DISPLAY FUNCTIONS//
/////////////////////
void gm_ending_disp_scr() {
	//Calculate model matrix
	guTranslate    (&dynPtr->mLevelPos,0.f,0.f,0.f);
	graphics_rotate(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale        (&dynPtr->mLevelScl,animScrEndingScl,animScrEndingScl,animScrEndingScl);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw screen
	if(scrEndingGfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(scrEndingGfx));
}
void gm_ending_disp_objs() {
	int i;
	for(i=0; i<7; i++) {
		//Calculate model matrix
		guTranslate    (&dynPtr->mObjPos[i],endingTreasurePosXTable[i],endingTreasurePosY[i]-1024.f,0.f);
		graphics_rotate(&dynPtr->mObjRot[i],0.f,0.f,0.f);
		guScale        (&dynPtr->mObjScl[i],1.f,1.f,1.f);
		gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mObjPos[i]),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
		gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mObjRot[i]),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
		gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mObjScl[i]),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
		//Draw object
		if(endingTreasureGfxTable[i]!=NULL && frenzyFlags[i]) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(endingTreasureGfxTable[i]));
	}
}

//Main ending display
void gm_ending_disp() {
	float eye[3];
	float center[3];
	float up[3];
	//Setup camera position
	eye[0] = 0.f;
	eye[1] = 0.f;
	eye[2] = 3072.f;
	center[0] = 0.f;
	center[1] = 0.f;
	center[2] = 0.f;
	up[0] = 0.f;
	up[1] = 1.f;
	up[2] = 0.f;
	//Init display
	graphics_init();
	graphics_clear();
	graphics_setup();
	graphics_view(eye,center,up);
	//Draw ending screen
	gm_ending_disp_scr();
	//Draw objects
	gm_ending_disp_objs();
	//End display
	graphics_end(NU_SC_SWAPBUFFER);
}
