#include "gm_title.h"

extern u8 joy1Pattern;
extern NUContData joy1Data;
extern u16 joy1ButtonPrev,joy1ButtonDown,joy1ButtonUp;

volatile extern int gameMode;
extern int gameSubmode;

//gm_play.c
extern int levelId;
extern int warpId;
extern int frenzyMode;
extern u8 frenzyFlags[7];

/////////////////////
//PROCESS FUNCTIONS//
/////////////////////
Gfx * scrTitleGfx = NULL;

//Main title process
void gm_title_proc() {
	switch(gameSubmode) {
		int i;
		//Init
		case 0: {
			//Load banks
			bank_load(0);
			//Load screen graphics
			scrTitleGfx = gfx_scr_title;
			gameSubmode = 1;
			break;
		}
		//Main loop
		case 1: {
			//Check for START press
			if(joy1ButtonDown&START_BUTTON) {
				//Init game state
				levelId = 2;
				warpId = 0;
				frenzyMode = 0;
				for(i=0; i<7; i++) {
					frenzyFlags[i] = 0;
				}
				scrTitleGfx = NULL;
				gameMode = 1;
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
void gm_title_disp_scr() {
	//Calculate model matrix
	guTranslate    (&dynPtr->mLevelPos,0.f,0.f,0.f);
	graphics_rotate(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale        (&dynPtr->mLevelScl,1.f,1.f,1.f);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw screen
	if(scrTitleGfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(scrTitleGfx));
}

//Main title display
void gm_title_disp() {
	float eye[3];
	float center[3];
	float up[3];
	//Setup camera position
	eye[0] = 0.f;
	eye[1] = 0.f;
	eye[2] = 2048.f;
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
	//Draw title screen
	gm_title_disp_scr();
	//End display
	graphics_end(NU_SC_SWAPBUFFER);
}
