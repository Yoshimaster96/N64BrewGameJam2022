#include "gm_title.h"

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

//Main ending process
void gm_ending_proc() {
	switch(gameSubmode) {
		//Init
		case 0: {
			//TODO
			break;
		}
		//Main loop
		case 1: {
			//TODO
			break;
		}
	}
}

/////////////////////
//DISPLAY FUNCTIONS//
/////////////////////
void gm_ending_disp_scr() {
	//TODO
}

//Main ending display
void gm_ending_disp() {
	float eye[3];
	float center[3];
	float up[3];
	//Setup camera position
	eye[0] = 0.f;
	eye[1] = 0.f;
	eye[2] = 1.f;
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
	//End display
	graphics_end(NU_SC_SWAPBUFFER);
}
