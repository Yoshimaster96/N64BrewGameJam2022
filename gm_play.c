#include "gm_play.h"

extern u8 joy1Pattern;
extern NUContData joy1Data;
extern u16 joy1ButtonPrev,joy1ButtonDown,joy1ButtonUp;

extern int gameMode;
extern int gameSubmode;

/////////////////////
//PROCESS FUNCTIONS//
/////////////////////
//Objects
typedef struct {
	//Actor info
	u8 id;
	u8 param;
	u8 mode;
	u8 state;
	s32 tempsI[8];
	float tempsF[8];
	//Transform
	float pos[3];
	float rot[3];
	float scl[3];
	//Movement
	float vel[3];
	//Graphics
	Gfx * gfx;
} TObject;
TObject objects[OBJ_MAX];
TObject * playerObject;
//Level
typedef struct {
	u8 next[2];
	//Graphics
	Gfx * gfx;
	//Collision
	s16 colBaseX,colBaseZ;
	s16 colSizeX,colSizeZ;
	s16 * colData;
	//Objects
	TLevelObject * objs;
} TLevel;
const TLevel levelTable[] = {
	{ 0, 0,gfx_lev_maptest,-0x0800,-0x0800,12,12,col_lev_maptest,obj_lev_maptest},
	//lev_objtest
	//lev_demo
	//lev_tutorial
	//lev_a1
	//lev_a2
	//lev_b1
	//lev_b2
	//lev_b3
	//lev_c1
	//lev_c2
	//lev_midpoint
};
int levelId = 0;
u8 levelNext[2];
Gfx * levelGfx;
s16 levelColBaseX,levelColBaseZ;
s16 levelColSizeX,levelColSizeZ;
s16 * levelColData;

//Map collision
const float slopeNormalTable[8][3] = {
	{ 0.000000f,0.f, 0.000000f},
	{ 0.000000f,0.f, 0.000000f},
	{ 0.000000f,0.f, 0.000000f},
	{ 0.000000f,0.f, 0.000000f},
	{ 0.000000f,0.f, 0.785398f},
	{-0.785398f,0.f, 0.000000f},
	{ 0.000000f,0.f,-0.785398f},
	{ 0.785398f,0.f, 0.000000f},
};
s16 map_get_height(s16 x,s16 z,float * nrm) {
	int idx;
	s16 h,hd;
	//Check bounds
	h = 0x7F00;
	if(x>=levelColBaseX &&
	   z>=levelColBaseZ &&
	   x<(levelColBaseX+(levelColSizeX<<8)) &&
	   z<(levelColBaseZ+(levelColSizeZ<<8))) {
		//Get base height
		idx = ((x-levelColBaseX)>>8) + (((z-levelColBaseZ)>>8)*levelColSizeX);
		h = levelColData[idx]&0xFF00;
		//Handle slope
		//The following bitfields are used to indicate the slope:
		//Bit 2: Slope flag
		//Bit 1: Slope direction flag
		//Bit 0: Slope axis flag
		//Thus the following values are valid:
		//0x00: No slope
		//0x01
		//0x02
		//0x03
		//0x04: Slope right
		//0x05: Slope down
		//0x06: Slope left
		//0x07: Slope up
		if(levelColData[idx]&4) {
			if(levelColData[idx]&1) {
				hd = z&0xFF;
			} else {
				hd = x&0xFF;
			}
			if(levelColData[idx]&2) {
				hd ^= 0xFF;
			}
			h |= hd;
		}
		//Return normal if requested
		if(nrm!=NULL) {
			nrm[0] = slopeNormalTable[levelColData[idx]&7][0];
			nrm[2] = slopeNormalTable[levelColData[idx]&7][2];
		}
	}
	return h;
}
void map_collide(int idx) {
	s16 sx,sz;
	s16 sy0,sy1;
	s16 syw0,syw1;
	//Get height at center
	sx = (s16)objects[idx].pos[0];
	sz = (s16)objects[idx].pos[2];
	sy0 = (s16)objects[idx].pos[1];
	sy1 = map_get_height(sx,sz,objects[idx].rot);
	//Check falling state
	if((sy1-sy0)<-24) {
		//Floor below
		objects[idx].vel[1] -= 2.f;
		objects[idx].rot[0] = 0.f;
		objects[idx].rot[2] = 0.f;
	} else if((sy1-sy0)>24) {
		//Floor above
		objects[idx].vel[1] = 0.f;
	} else {
		//Floor OK
		objects[idx].pos[1] = (float)sy1;
		sy0 = sy1;
		objects[idx].vel[1] = 0.f;
	}
	//Check wall collisions
	//Check right
	if((sx&0xFF)>0xA0) {
		syw0 = map_get_height((sx&~0xFF)+0x0FF,sz,NULL);
		syw1 = map_get_height((sx&~0xFF)+0x100,sz,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sx &= ~0xFF;
			sx |= 0xA0;
			objects[idx].pos[0] = (float)sx;
			if(objects[idx].vel[0]>0.f) objects[idx].vel[0] = 0.f;
		}
	//Check left
	} else if((sx&0xFF)<0x60) {
		syw0 = map_get_height((sx&~0xFF)-0,sz,NULL);
		syw1 = map_get_height((sx&~0xFF)-1,sz,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sx &= ~0xFF;
			sx |= 0x60;
			objects[idx].pos[0] = (float)sx;
			if(objects[idx].vel[0]<0.f) objects[idx].vel[0] = 0.f;
		}
	}
	//Check bottom
	if((sz&0xFF)>0xA0) {
		syw0 = map_get_height(sx,(sz&~0xFF)+0x0FF,NULL);
		syw1 = map_get_height(sx,(sz&~0xFF)+0x100,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sz &= ~0xFF;
			sz |= 0xA0;
			objects[idx].pos[2] = (float)sz;
			if(objects[idx].vel[2]>0.f) objects[idx].vel[2] = 0.f;
		}
	//Check top
	} else if((sz&0xFF)<0x60) {
		syw0 = map_get_height(sx,(sz&~0xFF)-0,NULL);
		syw1 = map_get_height(sx,(sz&~0xFF)-1,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sz &= ~0xFF;
			sz |= 0x60;
			objects[idx].pos[2] = (float)sz;
			if(objects[idx].vel[2]<0.f) objects[idx].vel[2] = 0.f;
		}
	}
}

//Objects process
void proc_obj_player(int idx) {
	s8 sx,sy;
	float tx,tz;
	float v2;
	//Init
	if(objects[idx].mode==0) {
		playerObject = &objects[idx];
		objects[idx].gfx = gfx_player_test;
		objects[idx].mode = 1;
	}
	//Calculate target velocity
	sx = joy1Data.stick_x;
	if(sx<-64) sx = -64;
	if(sx> 64) sx =  64;
	sy = joy1Data.stick_y;
	if(sy<-64) sy = -64;
	if(sy> 64) sy =  64;
	tx =  ((float)sx)/4.f;
	tz = -((float)sy)/4.f;
	//Interpolate velocity
	objects[idx].vel[0] = 0.875f*objects[idx].vel[0] + 0.125f*tx;
	objects[idx].vel[2] = 0.875f*objects[idx].vel[2] + 0.125f*tz;
	//Calculate facing direction
	v2 = objects[idx].vel[0]*objects[idx].vel[0] + objects[idx].vel[2]*objects[idx].vel[2];
	if(v2>0.001f) {
		objects[idx].rot[1] = atan2(objects[idx].vel[0],objects[idx].vel[2]);
	}
	//Apply velocity
	objects[idx].pos[0] += objects[idx].vel[0];
	objects[idx].pos[1] += objects[idx].vel[1];
	objects[idx].pos[2] += objects[idx].vel[2];
	//Do map collision
	map_collide(idx);
}
void proc_obj_ghost(int idx) {
	//TODO
}
void proc_obj_zombie(int idx) {
	//TODO
}
void proc_obj_button(int idx) {
	//TODO
}
void proc_obj_gate(int idx) {
	//TODO
}
void proc_obj_tunnel(int idx) {
	//TODO
}
void proc_obj_fence(int idx) {
	//TODO
}
void proc_obj_rock(int idx) {
	//TODO
}
void proc_obj_key(int idx) {
	//TODO
}
void proc_obj_gem(int idx) {
	//TODO
}
void (*procObjFuncs[12])(int idx) = {
	proc_obj_player,	//0x00: Player (slime)
	NULL,				//0x01: (DUMMY FOR ALIGNMENT)
	proc_obj_ghost,		//0x02: Ghost
	proc_obj_zombie,	//0x03: Zombie
	proc_obj_button,	//0x04: Button
	proc_obj_gate,		//0x05: Gate
	proc_obj_tunnel,	//0x06: Tunnel
	proc_obj_fence,		//0x07: Fence
	proc_obj_rock,		//0x08: Rock
	proc_obj_key,		//0x09: Key
	proc_obj_gem,		//0x0A: Gem
	NULL,				//0x0B: (DUMMY FOR ALIGNMENT)
};
void gm_play_proc_objs() {
	int i;
	for(i=0; i<OBJ_MAX; i++) {
		if(objects[i].id!=0xFF) {
			procObjFuncs[objects[i].id](i);
		}
	}
}

//Main gameplay process
void gm_play_proc() {
	int i,j;
	switch(gameSubmode) {
		//Init
		case 0: {
			//Load level
			levelNext[0] = levelTable[levelId].next[0];
			levelNext[1] = levelTable[levelId].next[1];
			levelGfx = levelTable[levelId].gfx;
			levelColBaseX = levelTable[levelId].colBaseX;
			levelColBaseZ = levelTable[levelId].colBaseZ;
			levelColSizeX = levelTable[levelId].colSizeX;
			levelColSizeZ = levelTable[levelId].colSizeZ;
			levelColData = levelTable[levelId].colData;
			//Clear objects
			for(i=0; i<OBJ_MAX; i++) {
				objects[i].id    = 0xFF;
				objects[i].param = 0x00;
				objects[i].mode  = 0x00;
				objects[i].state = 0x00;
				for(j=0; j<8; j++) {
					objects[i].tempsI[j] = 0;
					objects[i].tempsF[j] = 0.f;
				}
				objects[i].pos[0] = 0.f;
				objects[i].pos[1] = 0.f;
				objects[i].pos[2] = 0.f;
				objects[i].rot[0] = 0.f;
				objects[i].rot[1] = 0.f;
				objects[i].rot[2] = 0.f;
				objects[i].scl[0] = 1.f;
				objects[i].scl[1] = 1.f;
				objects[i].scl[2] = 1.f;
				objects[i].vel[0] = 0.f;
				objects[i].vel[1] = 0.f;
				objects[i].vel[2] = 0.f;
				objects[i].gfx = NULL;
			}
			//Load objects
			i = 0;
			while(1) {
				objects[i].id     = levelTable[levelId].objs[i].id;
				if(objects[i].id==0xFF) break;
				if(objects[i].id==0x00) playerObject = &objects[i];
				objects[i].param  = levelTable[levelId].objs[i].param;
				objects[i].pos[0] = levelTable[levelId].objs[i].pos[0];
				objects[i].pos[1] = levelTable[levelId].objs[i].pos[1];
				objects[i].pos[2] = levelTable[levelId].objs[i].pos[2];
				i++;
			}
			gameSubmode = 1;
			break;
		}
		//Main loop
		case 1: {
			//Handle pause
			//TODO
			//Process objects
			gm_play_proc_objs();
			break;
		}
	}
}

/////////////////////
//DISPLAY FUNCTIONS//
/////////////////////
void gu_rotate_yxz(Mtx * m,float x,float y,float z) {
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

void gm_play_disp_level() {
	//Calculate model matrix
	guTranslate  (&dynPtr->mLevelPos,0.f,0.f,0.f);
	gu_rotate_yxz(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale      (&dynPtr->mLevelScl,1.f,1.f,1.f);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw level
	gDPSetCycleType(dlPtr++,G_CYC_1CYCLE);
	gSPClearGeometryMode(dlPtr++,0xFFFFFFFF);
	gSPSetGeometryMode(dlPtr++,G_LIGHTING|G_ZBUFFER|G_SHADE|G_SHADING_SMOOTH|G_CULL_BACK);
	gDPSetRenderMode(dlPtr++,G_RM_ZB_OPA_SURF,G_RM_ZB_OPA_SURF2);
	gDPSetColorDither(dlPtr++,G_CD_BAYER);
	gDPSetCombineMode(dlPtr++,G_CC_MODULATERGBA,G_CC_MODULATERGBA);
	gDPSetTexturePersp(dlPtr++,G_TP_PERSP);
	gDPSetTextureLOD(dlPtr++,G_TL_TILE);
	gDPSetTextureFilter(dlPtr++,G_TF_POINT);
	gDPSetTextureConvert(dlPtr++,G_TC_FILT);
	gDPSetTextureLUT(dlPtr++,G_TT_NONE);
	gSPTexture(dlPtr++,0xFFFF,0xFFFF,0,G_TX_RENDERTILE,G_ON);
	if(levelGfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(levelGfx));
}
void gm_play_disp_objs() {
	int i;
	for(i=0; i<OBJ_MAX; i++) {
		//Calculate model matrix
		guTranslate  (&dynPtr->mObjPos[i],objects[i].pos[0],objects[i].pos[1],objects[i].pos[2]);
		gu_rotate_yxz(&dynPtr->mObjRot[i],objects[i].rot[0],objects[i].rot[1],objects[i].rot[2]);
		guScale      (&dynPtr->mObjScl[i],objects[i].scl[0],objects[i].scl[1],objects[i].scl[2]);
		gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mObjPos[i]),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
		gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mObjRot[i]),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
		gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mObjScl[i]),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
		//Draw object
		if(objects[i].gfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(objects[i].gfx));
	}
}

//Main gameplay display
void gm_play_disp() {
	float eye[3];
	float center[3];
	float up[3];
	//Setup camera position
	eye[0] = 0.f;
	eye[1] = 4096.f;
	eye[2] = 0.f;
	center[0] = 0.f;
	center[1] = 0.f;
	center[2] = 0.f;
	up[0] = 0.f;
	up[1] = 0.f;
	up[2] = -1.f;
	//Focus on player
	if(playerObject!=NULL) {
		eye[0] = playerObject->pos[0];
		eye[2] = playerObject->pos[2];
		center[0] = playerObject->pos[0];
		center[2] = playerObject->pos[2];
	}
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
