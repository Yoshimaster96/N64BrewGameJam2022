#include "gm_over.h"

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
Gfx * scrOverGfx;
int animScrOverTime;
float animScrOverPosY;

//Animation curve process
float animcurve_scr_over_pos_y(float t) {
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

//Main gameover process
void gm_over_proc() {
	float t;
	switch(gameSubmode) {
		//Init
		case 0: {
			//Load banks
			bank_load(2);
			//Load screen graphics
			scrOverGfx = gfx_scr_over;
			//Init animation
			animScrOverTime = 0;
			animScrOverPosY = 4096.f;
			gameSubmode = 1;
			break;
		}
		//Main loop
		case 1: {
			//Update animation
			t = ((float)animScrOverTime)/60.f;
			animScrOverPosY = animcurve_scr_over_pos_y(t/2.f);
			animScrOverTime++;
			//Check for back to title
			if(t>6.f) {
				scrOverGfx = NULL;
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
void gm_over_disp_scr() {
	//Calculate model matrix
	guTranslate    (&dynPtr->mLevelPos,0.f,animScrOverPosY,0.f);
	graphics_rotate(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale        (&dynPtr->mLevelScl,1.f,1.f,1.f);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw screen
	if(scrOverGfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(scrOverGfx));
}

//Main gameover display
void gm_over_disp() {
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
	//Draw gameover screen
	gm_over_disp_scr();
	//End display
	graphics_end(NU_SC_SWAPBUFFER);
}
