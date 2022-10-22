#include "gm_debug.h"

extern u8 joy1Pattern;
extern NUContData joy1Data;
extern u16 joy1ButtonPrev,joy1ButtonDown,joy1ButtonUp;

volatile extern int gameMode;
extern int gameSubmode;

//gm_play.c
extern int levelId;
extern int warpId;

/////////////////////
//PROCESS FUNCTIONS//
/////////////////////
s8 cursorPos;
s8 viewIdx;
s16 viewAnim,viewFrame;
float eyeRad,eyeLat,eyeLong;

typedef struct {
	char name[16];
	Gfx * gfx;
} TTestView;
TTestView testViewLevelTable[] = {
	{"lev_maptest",	gfx_lev_maptest},
	{"lev_objtest",	gfx_lev_objtest},
	{"lev_intro"  , gfx_lev_intro  },
	{"lev_a1"     , gfx_lev_a1     },
	{"lev_a2"     , gfx_lev_a2     },
	{"lev_b1"     , gfx_lev_b1     },
	{"lev_b2"     , gfx_lev_b2     },
	{"lev_b3"     , gfx_lev_b3     },
	{"lev_c1"     , gfx_lev_c1     },
	{"lev_c2"     , gfx_lev_c2     },
	{"lev_c3"     , gfx_lev_c3     },
	{"lev_d1"     , gfx_lev_d1     },
	{"lev_d2"     , gfx_lev_d2     },
	{"lev_e1"     , gfx_lev_e1     },
	{"lev_ending" , gfx_lev_ending },
	{"lev_tr"     , gfx_lev_tr     },
};
TTestView testViewCharacterTable[] = {
	{"chr_slime",	gfx_chr_slime},
	{"chr_ghost",	gfx_chr_ghost},
	{"chr_zombie",	gfx_chr_zombie},
};
TTestView testViewObjectTable[] = {
	{"obj_button1",	gfx_obj_button1},
	{"obj_button2",	gfx_obj_button2},
	{"obj_gate1",	gfx_obj_gate1},
	{"obj_gate2",	gfx_obj_gate2},
	{"obj_fence",	gfx_obj_fence},
	{"obj_gap",		gfx_obj_gap},
	{"obj_rock",	gfx_obj_rock},
	{"obj_key1",	gfx_obj_key1},
	{"obj_key2",	gfx_obj_key2},
	{"obj_gem1",	gfx_obj_gem1},
	{"obj_gem2",	gfx_obj_gem2},
	{"obj_gem3",	gfx_obj_gem3},
	{"obj_gem4",	gfx_obj_gem4},
	{"obj_gmet1",	gfx_obj_gmet1},
	{"obj_gmet2",	gfx_obj_gmet2},
	{"obj_gpearl",	gfx_obj_gpearl},
	{"obj_tunnel1",	gfx_obj_tunnel1},
	{"obj_tunnel2",	gfx_obj_tunnel2},
	{"obj_tunnel3",	gfx_obj_tunnel3},
};
char * testViewName;
char * testViewNameAnim;
Gfx * testViewGfx;
#define TEST_VIEW_LEV_SIZE (sizeof(testViewLevelTable    )/sizeof(TTestView))
#define TEST_VIEW_CHR_SIZE (sizeof(testViewCharacterTable)/sizeof(TTestView))
#define TEST_VIEW_OBJ_SIZE (sizeof(testViewObjectTable   )/sizeof(TTestView))

typedef struct {
	char name[16];
	TAnimVertex ** frames;
	u16 frameCount;
	u16 animSpeed;
} TTestAnim;
TTestAnim testAnimSlimeTable[] = {
	{"act_idle",	act_chr_slime_idle,		 8,0x0020},
	{"act_move",	act_chr_slime_move,		 8,0x0040},
	{"act_idle_s",	act_chr_slime_idle_s,	 8,0x0020},
	{"act_move_s",	act_chr_slime_move_s,	 8,0x0040},
	{"act_swallow",	act_chr_slime_swallow,	11,0x0080},
	{"act_spit",	act_chr_slime_spit,		11,0x0080},
};
TTestAnim testAnimGhostTable[] = {
	{"act_idle",	act_chr_ghost_idle,		 8,0x0020},
	{"act_move",	act_chr_ghost_move,		 8,0x0040},
	{"act_chase",	act_chr_ghost_chase,	 8,0x0060},
};
TTestAnim testAnimZombieTable[] = {
	{"act_idle",	act_chr_zombie_idle,	 8,0x0020},
	{"act_move",	act_chr_zombie_move,	 8,0x0040},
	{"act_chase",	act_chr_zombie_chase,	 8,0x0060},
};
typedef struct {
	char name[16];
	TTestAnim * anims;
	int nAnims;
	Vtx * vSrc;
	Gfx * gSrc;
	Vtx * vDst;
	Gfx * gDst;
	u16 nVtx;
	u16 nGfx;
} TTestCharacter;
TTestCharacter testAnimTable[] = {
	{"chr_slime", testAnimSlimeTable ,6,vtx_chr_slime ,gfx_chr_slime ,animVtxBuf_slime ,animGfxBuf_slime ,VTX_BUF_SLIME_SIZE ,GFX_BUF_SLIME_SIZE },
	{"chr_ghost", testAnimGhostTable ,3,vtx_chr_ghost ,gfx_chr_ghost ,animVtxBuf_ghost ,animGfxBuf_ghost ,VTX_BUF_GHOST_SIZE ,GFX_BUF_GHOST_SIZE },
	{"chr_zombie",testAnimZombieTable,3,vtx_chr_zombie,gfx_chr_zombie,animVtxBuf_zombie,animGfxBuf_zombie,VTX_BUF_ZOMBIE_SIZE,GFX_BUF_ZOMBIE_SIZE},
};

//Create animation frame buffer
void gm_debug_proc_anim() {
	Vtx * vSrc,* vDst;
	Gfx * gSrc,* gDst;
	int nVtx,nGfx;
	TAnimVertex * frame;
	int i;
	u32 dv;
	//Get animation info
	nVtx = testAnimTable[viewIdx].nVtx;
	nGfx = testAnimTable[viewIdx].nGfx;
	vSrc = testAnimTable[viewIdx].vSrc;
	vDst = &testAnimTable[viewIdx].vDst[bufferId*nVtx];
	gSrc = testAnimTable[viewIdx].gSrc;
	gDst = &testAnimTable[viewIdx].gDst[bufferId*nGfx];
	frame = testAnimTable[viewIdx].anims[viewAnim].frames[viewFrame>>8];
	//Copy buffers
	memcpy(vDst,vSrc,nVtx*sizeof(Vtx));
	memcpy(gDst,gSrc,nGfx*sizeof(Gfx));
	//Offset vertex positions/normals
	for(i=0; i<nVtx; i++) {
		vDst[i].n.ob[0] += frame[i].dob[0];
		vDst[i].n.ob[1] += frame[i].dob[1];
		vDst[i].n.ob[2] += frame[i].dob[2];
		vDst[i].n.n[0] = frame[i].n[0];
		vDst[i].n.n[1] = frame[i].n[1];
		vDst[i].n.n[2] = frame[i].n[2];
	}
	//Adjust vertex load addresses
	for(i=0; i<nGfx; i++) {
		if(gDst[i].words.w0>>24 == G_VTX) {
			dv = ((u32)vDst)-((u32)vSrc);
			gDst[i].words.w1 += dv;
		}
	}
	//Update animation timer
	viewFrame += testAnimTable[viewIdx].anims[viewAnim].animSpeed;
	i = testAnimTable[viewIdx].anims[viewAnim].frameCount<<8;
	if(viewFrame>=i) viewFrame -= i;
	//Set as output
	testViewGfx = gDst;
}

//Eye control
void gm_debug_proc_eye(float dr) {
	s8 sx,sy;
	//Calculate stick position
	sx = joy1Data.stick_x;
	if(sx<-64) sx = -64;
	if(sx> 64) sx =  64;
	sy = joy1Data.stick_y;
	if(sy<-64) sy = -64;
	if(sy> 64) sy =  64;
	//Update radius
	if(joy1Data.button&U_CBUTTONS) {
		eyeRad -= dr;
		if(eyeRad<256.f) eyeRad = 256.f;
	}
	if(joy1Data.button&D_CBUTTONS) {
		eyeRad += dr;
		if(eyeRad>65536.f) eyeRad = 65536.f;
	}
	//Update latitude
	eyeLat += ((float)sx)*3.834952e-4f;	//pi/8192
	if(eyeLat<-3.141593f) eyeLat += 6.283185f;
	if(eyeLat> 3.141593f) eyeLat -= 6.283185f;
	//Update longitude
	eyeLong += ((float)sy)*3.834952e-4f;	//pi/8192
	if(eyeLong<-1.570796f) eyeLong = -1.570796f;
	if(eyeLong> 1.570796f) eyeLong =  1.570796f;
}

//Main debug process
void gm_debug_proc() {
	switch(gameSubmode) {
		//Init
		case 0: {
			//Init menu
			levelId = 0;
			warpId = 0;
			cursorPos = 0;
			testViewName = NULL;
			testViewGfx  = NULL;
			gameSubmode = 1;
			break;
		}
		//Main loop
		case 1: {
			//Move cursor up/down
			if(joy1ButtonDown&U_JPAD) {
				cursorPos--;
				if(cursorPos<0) cursorPos = 4;
			}
			if(joy1ButtonDown&D_JPAD) {
				cursorPos++;
				if(cursorPos>4) cursorPos = 0;
			}
			//Select level
			if(cursorPos==0) {
				if(joy1ButtonDown&L_TRIG) {
					levelId--;
					if(levelId<0) levelId = TEST_VIEW_LEV_SIZE-1;
				}
				if(joy1ButtonDown&R_TRIG) {
					levelId++;
					if(levelId>(TEST_VIEW_LEV_SIZE-1)) levelId = 0;
				}
			}
			//Select menu item
			if(joy1ButtonDown&A_BUTTON) {
				if(cursorPos==0) {
					gameMode = 1;
					gameSubmode = 0;
					nuGfxFuncRemove();
				} else {
					gameSubmode = cursorPos<<1;
				}
			}
			break;
		}
		//TEST view level init
		case 2: {
			//Load bank
			bank_load(4);
			//Init view
			viewIdx = 0;
			eyeRad  = 4096.f;
			eyeLat  = 0.f;
			eyeLong = 0.f;
			testViewName = testViewLevelTable[0].name;
			testViewGfx  = testViewLevelTable[0].gfx;
			gameSubmode = 3;
			break;
		}
		//TEST view level main
		case 3: {
			//Control camera
			gm_debug_proc_eye(16.f);
			//Select level
			if(joy1ButtonDown&L_TRIG) {
				viewIdx--;
				if(viewIdx<0) viewIdx = TEST_VIEW_LEV_SIZE-1;
				testViewName = testViewLevelTable[viewIdx].name;
				testViewGfx  = testViewLevelTable[viewIdx].gfx;
				//Load bank
				bank_load(viewIdx+4);
			}
			if(joy1ButtonDown&R_TRIG) {
				viewIdx++;
				if(viewIdx>(TEST_VIEW_LEV_SIZE-1)) viewIdx = 0;
				testViewName = testViewLevelTable[viewIdx].name;
				testViewGfx  = testViewLevelTable[viewIdx].gfx;
				//Load bank
				bank_load(viewIdx+4);
			}
			//Go back
			if(joy1ButtonDown&B_BUTTON) {
				gameSubmode = 0;
			}
			break;
		}
		//TEST view character init
		case 4: {
			//Init view
			viewIdx = 0;
			viewAnim = 0;
			viewFrame = 0;
			eyeRad  = 1024.f;
			eyeLat  = 0.f;
			eyeLong = 0.f;
			cursorPos = 0;
			testViewName = testAnimTable[0].name;
			testViewNameAnim = testAnimTable[0].anims[0].name;
			testViewGfx  = testAnimTable[0].gSrc;
			gameSubmode = 5;
			break;
		}
		//TEST view character main
		case 5: {
			//Control camera
			gm_debug_proc_eye(4.f);
			//Process animation
			gm_debug_proc_anim();
			//Move cursor up/down
			if(joy1ButtonDown&U_JPAD) {
				cursorPos--;
				if(cursorPos<0) cursorPos = 1;
			}
			if(joy1ButtonDown&D_JPAD) {
				cursorPos++;
				if(cursorPos>1) cursorPos = 0;
			}
			//Select character/animation
			if(cursorPos==0) {
				//Select character
				if(joy1ButtonDown&L_TRIG) {
					viewIdx--;
					viewAnim = 0;
					viewFrame = 0;
					if(viewIdx<0) viewIdx = TEST_VIEW_CHR_SIZE-1;
					testViewName = testAnimTable[viewIdx].name;
					testViewNameAnim = testAnimTable[viewIdx].anims[0].name;
					testViewGfx  = testAnimTable[viewIdx].gSrc;
				}
				if(joy1ButtonDown&R_TRIG) {
					viewIdx++;
					viewAnim = 0;
					viewFrame = 0;
					if(viewIdx>(TEST_VIEW_CHR_SIZE-1)) viewIdx = 0;
					testViewName = testAnimTable[viewIdx].name;
					testViewNameAnim = testAnimTable[viewIdx].anims[0].name;
					testViewGfx  = testAnimTable[viewIdx].gSrc;
				}
			}
			else if(cursorPos==1) {
				//Select animation
				if(joy1ButtonDown&L_TRIG) {
					viewAnim--;
					viewFrame = 0;
					if(viewAnim<0) viewAnim = testAnimTable[viewIdx].nAnims-1;
					testViewNameAnim = testAnimTable[viewIdx].anims[viewAnim].name;
					testViewGfx  = testAnimTable[viewIdx].gSrc;
				}
				if(joy1ButtonDown&R_TRIG) {
					viewAnim++;
					viewFrame = 0;
					if(viewAnim>(testAnimTable[viewIdx].nAnims-1)) viewAnim = 0;
					testViewName = testAnimTable[viewIdx].name;
					testViewNameAnim = testAnimTable[viewIdx].anims[viewAnim].name;
					testViewGfx  = testAnimTable[viewIdx].gSrc;
				}
			}
			//Go back
			if(joy1ButtonDown&B_BUTTON) {
				gameSubmode = 0;
			}
			break;
		}
		//TEST view object init
		case 6: {
			//Init view
			viewIdx = 0;
			eyeRad  = 1024.f;
			eyeLat  = 0.f;
			eyeLong = 0.f;
			testViewName = testViewObjectTable[0].name;
			testViewGfx  = testViewObjectTable[0].gfx;
			gameSubmode = 7;
			break;
		}
		//TEST view object main
		case 7: {
			//Control camera
			gm_debug_proc_eye(4.f);
			//Select object
			if(joy1ButtonDown&L_TRIG) {
				viewIdx--;
				if(viewIdx<0) viewIdx = TEST_VIEW_OBJ_SIZE-1;
				testViewName = testViewObjectTable[viewIdx].name;
				testViewGfx  = testViewObjectTable[viewIdx].gfx;
			}
			if(joy1ButtonDown&R_TRIG) {
				viewIdx++;
				if(viewIdx>(TEST_VIEW_OBJ_SIZE-1)) viewIdx = 0;
				testViewName = testViewObjectTable[viewIdx].name;
				testViewGfx  = testViewObjectTable[viewIdx].gfx;
			}
			//Go back
			if(joy1ButtonDown&B_BUTTON) {
				gameSubmode = 0;
			}
			break;
		}
		//TEST sound test
		case 8: {
			//Init
			cursorPos = 0;
			testViewName = NULL;
			testViewGfx  = NULL;
			//TODO
			gameSubmode = 9;
			break;
		}
		//TEST sound test
		case 9: {
			//TODO
			//Go back
			if(joy1ButtonDown&B_BUTTON) {
				gameSubmode = 0;
			}
			break;
		}
	}
}

/////////////////////
//DISPLAY FUNCTIONS//
/////////////////////
void gm_debug_disp_test_view() {
	//Calculate model matrix
	guTranslate    (&dynPtr->mLevelPos,0.f,0.f,0.f);
	graphics_rotate(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale        (&dynPtr->mLevelScl,1.f,1.f,1.f);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw model
	if(testViewGfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(testViewGfx));
}
void gm_debug_disp_menu_eye(int y) {
#if 0
#else
	char strBuf[80];
#endif
	//Heading
	nuDebConTextPos(NU_DEB_CON_WINDOW0,1,y+0);
	nuDebConCPuts  (NU_DEB_CON_WINDOW0,"EYE POSITION");
	//Draw eye position text
#if 0
	nuDebConTextPos(NU_DEB_CON_WINDOW0,3,y+2);
	nuDebConPrintf (NU_DEB_CON_WINDOW0,"RADIUS: % 9.2f",eyeRad);
	nuDebConTextPos(NU_DEB_CON_WINDOW0,3,y+3);
	nuDebConPrintf (NU_DEB_CON_WINDOW0,"LAT   : % 9.6f",eyeLat);
	nuDebConTextPos(NU_DEB_CON_WINDOW0,3,y+4);
	nuDebConPrintf (NU_DEB_CON_WINDOW0,"LONG  : % 9.6f",eyeLong);
#else
	nuDebConTextPos(NU_DEB_CON_WINDOW0,3,y+2);
	sprintf(strBuf,"RADIUS: % 9.2f",eyeRad);
	nuDebConCPuts  (NU_DEB_CON_WINDOW0,strBuf);
	nuDebConTextPos(NU_DEB_CON_WINDOW0,3,y+3);
	sprintf(strBuf,"LAT   : % 9.6f",eyeLat);
	nuDebConCPuts  (NU_DEB_CON_WINDOW0,strBuf);
	nuDebConTextPos(NU_DEB_CON_WINDOW0,3,y+4);
	sprintf(strBuf,"LONG  : % 9.6f",eyeLong);
	nuDebConCPuts  (NU_DEB_CON_WINDOW0,strBuf);
#endif
}
void gm_debug_disp_menu() {
	//Clear menu
	nuDebConClear(NU_DEB_CON_WINDOW0);
	//Draw menu
	switch(gameSubmode) {
		//Main menu
		case 0:
		case 1: {
			//Heading
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,1);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"DEBUG MENU");
			//Menu items
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,3);
			nuDebConPrintf (NU_DEB_CON_WINDOW0,"GOTO LEVEL: %02u",levelId);
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,4);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"VIEW LEVEL");
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,5);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"VIEW CHARACTER");
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,6);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"VIEW OBJECT");
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,7);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"SOUND TEST");
			//Cursor
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,3+cursorPos);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"*");
			break;
		}
		//TEST view level
		case 2:
		case 3: {
			//Heading
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,1);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"VIEW LEVEL");
			//Level name
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,3);
			if(testViewName!=NULL) nuDebConPrintf (NU_DEB_CON_WINDOW0,"LEVEL NAME: %s",testViewName);
			//Eye position
			gm_debug_disp_menu_eye(5);
			break;
		}
		//TEST view character
		case 4:
		case 5: {
			//Heading
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,1);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"VIEW CHARACTER");
			//Character name
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,3);
			if(testViewName!=NULL) nuDebConPrintf (NU_DEB_CON_WINDOW0,"CHARACTER NAME: %s",testViewName);
			//Animation name
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,4);
			if(testViewNameAnim!=NULL) nuDebConPrintf (NU_DEB_CON_WINDOW0,"ANIMATION NAME: %s",testViewNameAnim);
			//Cursor
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,3+cursorPos);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"*");
			//Eye position
			gm_debug_disp_menu_eye(6);
			break;
		}
		//TEST view object
		case 6:
		case 7: {
			//Heading
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,1);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"VIEW OBJECT");
			//Object name
			nuDebConTextPos(NU_DEB_CON_WINDOW0,3,3);
			if(testViewName!=NULL) nuDebConPrintf (NU_DEB_CON_WINDOW0,"OBJECT NAME: %s",testViewName);
			//Eye position
			gm_debug_disp_menu_eye(5);
			break;
		}
		//TEST sound test
		case 8:
		case 9: {
			//Heading
			nuDebConTextPos(NU_DEB_CON_WINDOW0,1,1);
			nuDebConCPuts  (NU_DEB_CON_WINDOW0,"SOUND TEST");
			//Menu items
			//TODO
			break;
		}
	}
}

//Main debug display
void gm_debug_disp() {
	float eye[3];
	float center[3];
	float up[3];
	//Setup camera position
	eye[0] = eyeRad*sin(eyeLat)*cos(eyeLong);
	eye[1] = eyeRad*sin(eyeLong);
	eye[2] = eyeRad*cos(eyeLat)*cos(eyeLong);
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
	//Draw test view
	gm_debug_disp_test_view();
	//End display
	graphics_end(NU_SC_NOSWAPBUFFER);
	//Draw menu
	gm_debug_disp_menu();
	//End display (debug console)
	graphics_end_deb_con(NU_SC_SWAPBUFFER);
}
