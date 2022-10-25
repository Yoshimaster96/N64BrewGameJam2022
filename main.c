#include "main.h"

/////////
//INPUT//
/////////
u8 joy1Pattern;
NUContData joy1Data;
u16 joy1ButtonPrev,joy1ButtonDown,joy1ButtonUp;

void update_input() {
	//Update input
	if(joy1Pattern&1) {
		//Save previous buttons
		joy1ButtonPrev = joy1Data.button;
		//Get new buttons
		nuContDataGetEx(&joy1Data,0);
		//Get button up/down status
		joy1ButtonDown	= joy1Data.button&(~joy1ButtonPrev) ;
		joy1ButtonUp	= joy1ButtonPrev &(~joy1Data.button);
	}
}

//////////////
//GAME MODES//
//////////////
volatile int gameMode = 0;
int gameSubmode = 0;

void gm_title(int pendingGfx) {
	//Update graphics
	if(pendingGfx<2) {
		gm_title_disp();
		update_input();
		gm_title_proc();
	}
}
void gm_play(int pendingGfx) {
	//Update graphics
	if(pendingGfx<2) {
		gm_play_disp();
		update_input();
		gm_play_proc();
	}
}
void gm_over(int pendingGfx) {
	//Update graphics
	if(pendingGfx<2) {
		gm_over_disp();
		update_input();
		gm_over_proc();
	}
}
void gm_ending(int pendingGfx) {
	//Update graphics
	if(pendingGfx<2) {
		gm_ending_disp();
		update_input();
		gm_ending_proc();
	}
}
void gm_debug(int pendingGfx) {
	//Update graphics
	if(pendingGfx<2) {
		gm_debug_disp();
		update_input();
		gm_debug_proc();
	}
}

////////////////
//MAIN PROGRAM//
////////////////
//Entry point
void mainproc() {
	//Init banks
	bank_init();
	bank_load(1);
	//Init GFX
	nuGfxInit();
	//Init controller
	joy1Pattern = nuContInit();
	//Init audio
	nuAuInit();
	/*nuAuSeqPlayerBankSet(_bgmbankSegmentRomStart,
		_bgmbankSegmentRomEnd-_bgmbankSegmentRomStart,
		_bgmtableSegmentRomStart);
	nuAuSndPlayerBankSet(_sebankSegmentRomStart,
		_sebankSegmentRomEnd-_sebankSegmentRomStart,
		_setableSegmentRomStart);
	nuAuSeqPlayerSeqSet(_bgmSegmentRomStart);*/
	//Main game loop
	while(1) {
		//Init current stage
		switch(gameMode) {
			//Title
			case 0: {
				gameMode = -1;
				//nuAuSeqPlayerSetNo(0,0);
				//nuAuSeqPlayerPlay(0);
				nuGfxFuncSet((NUGfxFunc)gm_title);
				nuGfxDisplayOn();
				break;
			}
			//Main gameplay
			case 1: {
				gameMode = -1;
				//nuAuSeqPlayerSetNo(1,0);
				//nuAuSeqPlayerPlay(0);
				nuGfxFuncSet((NUGfxFunc)gm_play);
				nuGfxDisplayOn();
				break;
			}
			//Game over
			case 2: {
				gameMode = -1;
				//nuAuSeqPlayerSetNo(2,0);
				//nuAuSeqPlayerPlay(0);
				nuGfxFuncSet((NUGfxFunc)gm_over);
				nuGfxDisplayOn();
				break;
			}
			//Ending
			case 3: {
				gameMode = -1;
				//nuAuSeqPlayerSetNo(3,0);
				//nuAuSeqPlayerPlay(0);
				nuGfxFuncSet((NUGfxFunc)gm_ending);
				nuGfxDisplayOn();
				break;
			}
			//Debug
			case 4: {
				gameMode = -1;
				//nuAuSeqPlayerStop(0);
				nuGfxFuncSet((NUGfxFunc)gm_debug);
				nuGfxDisplayOn();
				break;
			}
		}
		//Wait for next stage
		while(gameMode == -1);
		nuGfxDisplayOff();
	}
}
