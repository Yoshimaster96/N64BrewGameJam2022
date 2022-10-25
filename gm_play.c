#include "gm_play.h"

extern u8 joy1Pattern;
extern NUContData joy1Data;
extern u16 joy1ButtonPrev,joy1ButtonDown,joy1ButtonUp;

volatile extern int gameMode;
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
	//Transform
	float pos[3];
	float rot[3];
	float scl[3];
	//Movement
	float vel[3];
	u8 onGround;
	//Graphics
	Gfx * gfx;
	//Animation
	u16 animId,animFrame;
	u16 pathId,pathFrame;
	//Processing
	float homePos[3];
} TObject;
TObject objects[OBJ_MAX];
TObject * playerObject;
TObject * heldObject;
int frenzyMode;
u8 frenzyFlags[7];
u8 animTaskTimer;
//Level
typedef struct {
	//Graphics
	Gfx * gfx;
	//Collision
	s16 colBaseX,colBaseZ;
	s16 colSizeX,colSizeZ;
	s16 * colData;
	//Objects
	TLevelObject * objs;
	//Paths
	TLevelPath * paths;
} TLevel;
const TLevel levelTable[] = {
	{gfx_lev_maptest,-0x0800,-0x0800,12,12,col_lev_maptest,obj_lev_maptest,NULL           },
	{gfx_lev_objtest,-0x0800,-0x0800,16,16,col_lev_objtest,obj_lev_objtest,pat_lev_objtest},
	{gfx_lev_intro  ,-0x0700,-0x1200,17,26,col_lev_intro  ,obj_lev_intro  ,NULL           },
	{gfx_lev_a1     ,-0x0300,-0x0600, 9,11,col_lev_a1     ,obj_lev_a1     ,pat_lev_a1     },
	{gfx_lev_a2     ,-0x0300,-0x0600, 9,11,col_lev_a2     ,obj_lev_a2     ,pat_lev_a2     },
	{gfx_lev_b1     ,-0x0300,-0x0F00, 9,20,col_lev_b1     ,obj_lev_b1     ,NULL           },
	{gfx_lev_b2     ,-0x0300,-0x0A00, 9,15,col_lev_b2     ,obj_lev_b2     ,NULL           },
	{gfx_lev_b3     ,-0x0200,-0x0B00, 7,16,col_lev_b3     ,obj_lev_b3     ,NULL           },
	{gfx_lev_c1     ,-0x0200,-0x0A00, 7,15,col_lev_c1     ,obj_lev_c1     ,NULL           },
	{gfx_lev_c2     ,-0x0300,-0x0700, 9,12,col_lev_c2     ,obj_lev_c2     ,NULL           },
	{gfx_lev_c3     ,-0x0400,-0x0600,11,11,col_lev_c3     ,obj_lev_c3     ,NULL           },
	{gfx_lev_d1     ,-0x0300,-0x0900,10,14,col_lev_d1     ,obj_lev_d1     ,pat_lev_d1     },
	{gfx_lev_d2     ,-0x0300,-0x0700, 9,12,col_lev_d2     ,obj_lev_d2     ,pat_lev_d2     },
	{gfx_lev_e1     ,-0x0500,-0x0F00,13,20,col_lev_e1     ,obj_lev_e1     ,NULL           },
	{gfx_lev_ending ,-0x0800,-0x0B00,19,16,col_lev_ending ,obj_lev_ending ,NULL           },
	{gfx_lev_tr     ,-0x0300,-0x0400, 9, 9,col_lev_tr     ,obj_lev_tr     ,NULL           },
};
int levelId = 0;
int warpId = 0;
Gfx * levelGfx;
s16 levelColBaseX,levelColBaseZ;
s16 levelColSizeX,levelColSizeZ;
s16 * levelColData;
TLevelObject * levelObjects;
TLevelPath * levelPaths;

typedef struct {
	TAnimVertex ** frames;
	u16 frameCount;
	u16 animSpeed;
} TAnim;
TAnim charAnimSlimeTable[] = {
	{act_chr_slime_idle,	 8,0x0020},
	{act_chr_slime_move,	 8,0x0040},
	{act_chr_slime_idle_s,	 8,0x0020},
	{act_chr_slime_move_s,	 8,0x0040},
	{act_chr_slime_swallow,	11,0x0080},
	{act_chr_slime_spit,	11,0x0080},
};
TAnim charAnimGhostTable[] = {
	{act_chr_ghost_idle,	 8,0x0020},
	{act_chr_ghost_move,	 8,0x0040},
	{act_chr_ghost_chase,	 8,0x0060},
};
TAnim charAnimZombieTable[] = {
	{act_chr_zombie_idle,	 8,0x0020},
	{act_chr_zombie_move,	 8,0x0040},
	{act_chr_zombie_chase,	 8,0x0060},
};
typedef struct {
	TAnim * anims;
	int nAnims;
	Vtx * vSrc;
	Gfx * gSrc;
	Vtx * vDst;
	Gfx * gDst;
	u16 nVtx;
	u16 nGfx;
} TCharacter;
TCharacter charAnimTable[] = {
	{charAnimSlimeTable ,6,vtx_chr_slime ,gfx_chr_slime ,animVtxBuf_slime ,animGfxBuf_slime ,VTX_BUF_SLIME_SIZE ,GFX_BUF_SLIME_SIZE },
	{NULL               ,0,NULL          ,NULL          ,NULL             ,NULL             ,0                  ,0                  },
	{charAnimGhostTable ,3,vtx_chr_ghost ,gfx_chr_ghost ,animVtxBuf_ghost ,animGfxBuf_ghost ,VTX_BUF_GHOST_SIZE ,GFX_BUF_GHOST_SIZE },
	{charAnimZombieTable,3,vtx_chr_zombie,gfx_chr_zombie,animVtxBuf_zombie,animGfxBuf_zombie,VTX_BUF_ZOMBIE_SIZE,GFX_BUF_ZOMBIE_SIZE},
};

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
		objects[idx].onGround = 0;
	}
	else if((sy1-sy0)>24) {
		//Floor above
		objects[idx].vel[1] = 0.f;
		objects[idx].onGround = 1;
	}
	else {
		//Floor OK
		objects[idx].pos[1] = (float)sy1;
		sy0 = sy1;
		objects[idx].vel[1] = 0.f;
		objects[idx].onGround = 1;
	}
	//Check wall collisions
	//Check right
	if((sx&0xFF)>0xA0 && objects[idx].vel[0]>-2.f) {
		//Bottom right
		syw0 = map_get_height((sx&~0xFF)+0x0FF,sz+0x48,NULL);
		syw1 = map_get_height((sx&~0xFF)+0x100,sz+0x48,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sx &= ~0xFF;
			sx |= 0xA0;
			objects[idx].pos[0] = (float)sx;
			objects[idx].vel[0] = 0.f;
		}
		//Top right
		syw0 = map_get_height((sx&~0xFF)+0x0FF,sz-0x48,NULL);
		syw1 = map_get_height((sx&~0xFF)+0x100,sz-0x48,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sx &= ~0xFF;
			sx |= 0xA0;
			objects[idx].pos[0] = (float)sx;
			objects[idx].vel[0] = 0.f;
		}
	}
	//Check left
	if((sx&0xFF)<0x60 && objects[idx].vel[0]<2.f) {
		//Bottom left
		syw0 = map_get_height((sx&~0xFF)-0,sz+0x48,NULL);
		syw1 = map_get_height((sx&~0xFF)-1,sz+0x48,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sx &= ~0xFF;
			sx |= 0x60;
			objects[idx].pos[0] = (float)sx;
			objects[idx].vel[0] = 0.f;
		}
		//Top left
		syw0 = map_get_height((sx&~0xFF)-0,sz-0x48,NULL);
		syw1 = map_get_height((sx&~0xFF)-1,sz-0x48,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sx &= ~0xFF;
			sx |= 0x60;
			objects[idx].pos[0] = (float)sx;
			objects[idx].vel[0] = 0.f;
		}
	}
	//Check bottom
	if((sz&0xFF)>0xA0 && objects[idx].vel[2]>-2.f) {
		//Right bottom
		syw0 = map_get_height(sx+0x48,(sz&~0xFF)+0x0FF,NULL);
		syw1 = map_get_height(sx+0x48,(sz&~0xFF)+0x100,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sz &= ~0xFF;
			sz |= 0xA0;
			objects[idx].pos[2] = (float)sz;
			objects[idx].vel[2] = 0.f;
		}
		//Left bottom
		syw0 = map_get_height(sx-0x48,(sz&~0xFF)+0x0FF,NULL);
		syw1 = map_get_height(sx-0x48,(sz&~0xFF)+0x100,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sz &= ~0xFF;
			sz |= 0xA0;
			objects[idx].pos[2] = (float)sz;
			objects[idx].vel[2] = 0.f;
		}
	}
	//Check top
	if((sz&0xFF)<0x60 && objects[idx].vel[2]<2.f) {
		//Right top
		syw0 = map_get_height(sx+0x48,(sz&~0xFF)-0,NULL);
		syw1 = map_get_height(sx+0x48,(sz&~0xFF)-1,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sz &= ~0xFF;
			sz |= 0x60;
			objects[idx].pos[2] = (float)sz;
			objects[idx].vel[2] = 0.f;
		}
		//Left top
		syw0 = map_get_height(sx-0x48,(sz&~0xFF)-0,NULL);
		syw1 = map_get_height(sx-0x48,(sz&~0xFF)-1,NULL);
		if((syw1-syw0)>24 && (syw1-sy0)>24) {
			sz &= ~0xFF;
			sz |= 0x60;
			objects[idx].pos[2] = (float)sz;
			objects[idx].vel[2] = 0.f;
		}
	}
}
//Create animation frame buffer
void char_proc_anim(int idx) {
	int viewIdx,viewAnim;
	Vtx * vSrc,* vDst;
	Gfx * gSrc,* gDst;
	int nVtx,nGfx;
	TAnimVertex * frame;
	int i;
	u32 dv;
	float di[3];
	float dia[3];
	//Get animation info
	viewIdx = objects[idx].id;
	viewAnim = objects[idx].animId;
	i = (bufferId+((objects[idx].param&7)*GFX_GTASK_NUM));
	nVtx = charAnimTable[viewIdx].nVtx;
	nGfx = charAnimTable[viewIdx].nGfx;
	vSrc = charAnimTable[viewIdx].vSrc;
	vDst = &charAnimTable[viewIdx].vDst[i*nVtx];
	gSrc = charAnimTable[viewIdx].gSrc;
	gDst = &charAnimTable[viewIdx].gDst[i*nGfx];
	frame = charAnimTable[viewIdx].anims[viewAnim].frames[objects[idx].animFrame>>8];
	//Early out if offscreen
	di[0] = playerObject->pos[0] - objects[idx].pos[0];
	dia[0] = fabs(di[0]);
	di[1] = playerObject->pos[1] - objects[idx].pos[1];
	dia[1] = fabs(di[1]);
	di[2] = playerObject->pos[2] - objects[idx].pos[2];
	dia[2] = fabs(di[2]);
	if(dia[0]<1280.f && dia[2]<1024.f) {
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
		//Set as output
		objects[idx].gfx = gDst;
	}
	//Update animation timer
	objects[idx].animFrame += charAnimTable[viewIdx].anims[viewAnim].animSpeed;
	i = charAnimTable[viewIdx].anims[viewAnim].frameCount<<8;
	if(objects[idx].animFrame>=i) objects[idx].animFrame -= i;
}
//Path evaluate
void path_evaluate(int idx) {
	int i;
	float di,d2;
	float x0,z0;
	float dt;
	TLevelPath * path;
	//Get path data
	path = &levelPaths[objects[idx].pathId];
	//Find segment with point
	for(i=0; i<(path->nPoints-1); i++) {
		if(objects[idx].pathFrame>=path->points[i+0].t &&
		   objects[idx].pathFrame<=path->points[i+1].t) {
			//Calculate interpolation factor
			di = ((float)objects[idx].pathFrame)-((float)path->points[i].t);
			d2 = ((float)path->points[i+1].t)-((float)path->points[i+0].t);
			dt = di/d2;
			//Get previous position
			x0 = objects[idx].pos[0];
			z0 = objects[idx].pos[2];
			//Set new position
			objects[idx].pos[0] = (1.f-dt)*path->points[i+0].pos[0] + dt*path->points[i+1].pos[0];
			objects[idx].pos[1] = (1.f-dt)*path->points[i+0].pos[1] + dt*path->points[i+1].pos[1];
			objects[idx].pos[2] = (1.f-dt)*path->points[i+0].pos[2] + dt*path->points[i+1].pos[2];
			//Set rotation
			di = objects[idx].pos[0] - x0;
			d2  = di*di;
			di = objects[idx].pos[2] - z0;
			d2 += di*di;
			if(d2>4.f) {
				objects[idx].rot[1] = atan2(objects[idx].pos[0]-x0,objects[idx].pos[2]-z0);
			}
			break;
		}
	}
}

//Objects process
//Player (slime)
const float playerRotTable[4] = {
	 0.000000f,
	 1.570796f,
	 3.141593f,
	-1.570796f,
};
void proc_obj_player(int idx) {
	int i;
	float di,d2;
	s8 sx,sy;
	float tx,tz;
	float v2;
	//Init
	if(objects[idx].mode==0) {
		playerObject = &objects[idx];
		objects[idx].gfx = gfx_chr_slime;
		objects[idx].rot[1] = playerRotTable[objects[idx].param&3];
		objects[idx].mode = 1;
		objects[idx].animId = 0;
		objects[idx].animFrame = 0;
		//Clear parameter for animation!
		objects[idx].param = 0;
	}
	//State 0x00: Normal
	//State 0x02: Normal (carrying)
	if(objects[idx].state==0 ||
	   objects[idx].state==2) {
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
		v2  = objects[idx].vel[0]*objects[idx].vel[0];
		v2 += objects[idx].vel[2]*objects[idx].vel[2];
		if(v2>4.f) {
			objects[idx].rot[1] = atan2(objects[idx].vel[0],objects[idx].vel[2]);
			if(objects[idx].animId!=(objects[idx].state+1)) {
				objects[idx].animId = (objects[idx].state+1);
				objects[idx].animFrame = 0;
			}
		} else {
			if(objects[idx].animId!=(objects[idx].state+0)) {
				objects[idx].animId = (objects[idx].state+0);
				objects[idx].animFrame = 0;
			}
		}
		//Swallow/spit object
		if(joy1ButtonDown&Z_TRIG) {
			if(objects[idx].state==0) {
				//Try to swallow object
				objects[idx].state = 1;
				objects[idx].animId = 4;
				objects[idx].animFrame = 0;
				//Clear held object
				heldObject = NULL;
			}
			else if(objects[idx].state==2) {
				//Spit object
				objects[idx].state = 3;
				objects[idx].animId = 5;
				objects[idx].animFrame = 0;
			}
			//Slow down player
			playerObject->vel[0] *= 0.5f;
			playerObject->vel[2] *= 0.5f;
		}
		//Animate player
		char_proc_anim(idx);
		//Apply velocity
		objects[idx].pos[0] += objects[idx].vel[0];
		objects[idx].pos[1] += objects[idx].vel[1];
		objects[idx].pos[2] += objects[idx].vel[2];
		//Do map collision
		map_collide(idx);
	}
	//State 0x01: Swallowing
	else if(objects[idx].state==1) {
		//Check to grab object
		if(objects[idx].animFrame==0x0400) {
			//Calculate target position
			tx = objects[idx].pos[0]+(192.f*sin(objects[idx].rot[1]));
			tz = objects[idx].pos[2]+(192.f*cos(objects[idx].rot[1]));
			//Find object at position
			for(i=0; i<OBJ_MAX; i++) {
				if(objects[i].id==0x08 ||
				   objects[i].id==0x09 ||
				   objects[i].id==0x0A) {
					di = objects[i].pos[0] - tx;
					d2  = di*di;
					di = objects[i].pos[1] - objects[idx].pos[1];
					d2 += di*di;
					di = objects[i].pos[2] - tz;
					d2 += di*di;
					if(d2<(96.f*96.f)) {
						heldObject = &objects[i];
						heldObject->state = 1;
						break;
					}
				}
			}
			if(heldObject==NULL) objects[idx].animId = 5;
		}
		//End animation
		if(objects[idx].animFrame==0x0A00) {
			if(heldObject!=NULL) {
				objects[idx].state = 2;
				objects[idx].animId = 1;
				objects[idx].animFrame = 0;
			} else {
				objects[idx].state = 0;
				objects[idx].animId = 0;
				objects[idx].animFrame = 0;
			}
		}
		//Animate player
		char_proc_anim(idx);
	}
	//State 0x03: Spitting
	else if(objects[idx].state==3) {
		//Release object
		if(objects[idx].animFrame==0x0400) {
			//Calculate target position
			heldObject->pos[0] = objects[idx].pos[0]+(256.f*sin(objects[idx].rot[1]));
			heldObject->pos[1] = objects[idx].pos[1]+24.f;
			heldObject->pos[2] = objects[idx].pos[2]+(256.f*cos(objects[idx].rot[1]));
			heldObject->rot[1] = objects[idx].rot[1];
			heldObject->vel[0] = 32.f*sin(objects[idx].rot[1]);
			heldObject->vel[1] = 16.f;
			heldObject->vel[2] = 32.f*cos(objects[idx].rot[1]);
			heldObject->state = 3;
			heldObject = NULL;
		}
		//End animation
		if(objects[idx].animFrame==0x0A00) {
			objects[idx].state = 0;
			objects[idx].animId = 0;
			objects[idx].animFrame = 0;
		}
		//Animate player
		char_proc_anim(idx);
	}
	//State 0x06: In tunnel
	else if(objects[idx].state==6) {
		//Move player along tunnel
		path_evaluate(idx);
		objects[idx].pathFrame++;
		//Check if at end
		if(objects[idx].pathFrame>=levelPaths[objects[idx].pathId].length) {
			objects[idx].state = 0;
			objects[idx].animId = 0;
			objects[idx].animFrame = 0;
		}
	}
	//State 0x05: Tunnel entering
	else if(objects[idx].state==5) {
		//Clear graphics
		objects[idx].gfx = NULL;
		//Clear velocity
		objects[idx].vel[0] = 0.f;
		objects[idx].vel[1] = 0.f;
		objects[idx].vel[2] = 0.f;
		//Set next state
		objects[idx].state = 6;
	}
	//State 0x07: Tunnel exiting
	else if(objects[idx].state==7) {
		//Set next state
		objects[idx].state = 0;
	}
	//State 0x09: Death
	else if(objects[idx].state==9) {
		//Set game mode
		gameMode = 2;
		gameSubmode = 0;
		nuGfxFuncRemove();
	}
	//State 0x08: Death init
	else if(objects[idx].state==8) {
		//Set next state
		objects[idx].state = 9;
	}
	//State 0x0B: Win
	else if(objects[idx].state==11) {
		//Set game mode
		gameMode = 3;
		gameSubmode = 0;
		nuGfxFuncRemove();
	}
	//State 0x0A: Win init
	else if(objects[idx].state==10) {
		//Set next state
		objects[idx].state = 11;
	}
}
//Ghost
const float enemyMoveSpeedTable[8] = {
	4.0f,4.5f,
	5.0f,5.5f,
	6.0f,6.5f,
	7.0f,7.5f,
};
void proc_obj_enemy_sub(int idx,Gfx* gfx) {
	int i;
	float di[3];
	float d,d2;
	float tx,tz;
	//State 0x00: Idle
	if(objects[idx].state==0) {
		//Path follow type
		if(objects[idx].param&0x80) {
			//Init path
			objects[idx].pathId = objects[idx].param&0xF;
			objects[idx].pathFrame = 0;
			//Set next state
			objects[idx].animId = 1;
			objects[idx].animFrame = 0;
			objects[idx].state = 1;
		}
		//Chasing type
		else {
			objects[idx].pathFrame++;
			if(objects[idx].pathFrame>=objects[idx].pathId) {
				//Set random timer
				objects[idx].pathId = 0x0040+(rand()&0x003F);
				objects[idx].pathFrame = 0;
				//Get random float from 0 to 1
				i = 0x3F800000|((rand()&0x7FFF)<<8);
				d = *(float*)&i;
				d -= 1.f;
				//Set random direction
				d = (d*6.283185f)-3.141596f;
				objects[idx].rot[1] = d;
				objects[idx].vel[0] = enemyMoveSpeedTable[frenzyMode]*sin(d);
				objects[idx].vel[2] = enemyMoveSpeedTable[frenzyMode]*cos(d);
				//Set animation
				objects[idx].animId = 1;
				objects[idx].animFrame = 0;
				//Set next state
				objects[idx].state = 1;
			}
		}
	}
	//State 0x01: Moving
	else if(objects[idx].state==1) {
		//Path follow type
		if(objects[idx].param&0x80) {
			//Move along path
			path_evaluate(idx);
			objects[idx].pathFrame++;
			//Check if at end
			if(objects[idx].pathFrame>=levelPaths[objects[idx].pathId].length) {
				objects[idx].pathFrame = 0;
			}
		}
		//Chasing type
		else {
			objects[idx].pathFrame++;
			if(objects[idx].pathFrame>=objects[idx].pathId) {
				//Set random timer
				objects[idx].pathId = 0x0040+(rand()&0x003F);
				objects[idx].pathFrame = 0;
				//Set random direction
				objects[idx].vel[0] = 0.f;
				objects[idx].vel[2] = 0.f;
				//Set animation
				objects[idx].animId = 0;
				objects[idx].animFrame = 0;
				//Set next state
				objects[idx].state = 0;
			}
		}
	}
	//State 0x02: Chasing
	else if(objects[idx].state==2) {
		tx = playerObject->pos[0] - objects[idx].pos[0];
		d2  = tx*tx;
		tz = playerObject->pos[2] - objects[idx].pos[2];
		d2 += tz*tz;
		if(d2>4.0) {
			d = atan2(tx,tz);
			objects[idx].rot[1] = d;
			objects[idx].vel[0] = 2.f*enemyMoveSpeedTable[frenzyMode]*sin(d);
			objects[idx].vel[2] = 2.f*enemyMoveSpeedTable[frenzyMode]*cos(d);
		}
	}
	//State 0x03: Dead
	else if(objects[idx].state==3) {
		objects[idx].pathFrame++;
		if(objects[idx].pathFrame>=0x0100) {
			//Reset position
			objects[idx].pos[0] = objects[idx].homePos[0];
			objects[idx].pos[1] = objects[idx].homePos[1];
			objects[idx].pos[2] = objects[idx].homePos[2];
			//Reset random timer
			objects[idx].pathId = 0;
			objects[idx].pathFrame = 0;
			//Reset animation
			objects[idx].gfx = gfx;
			objects[idx].animId = 0;
			objects[idx].animFrame = 0;
			//Set next state
			objects[idx].state = 0;
		}
	}
	if(objects[idx].state!=3) {
		//Check player/object collision
		for(i=0; i<OBJ_MAX; i++) {
			if(objects[i].id==0x00 ||
			   objects[i].id==0x02 ||
			   objects[i].id==0x03 ||
			   objects[i].id==0x08 ||
			   objects[i].id==0x09 ||
			   objects[i].id==0x0A) {
				if(i==idx) continue;
				di[0] = objects[i].pos[0] - objects[idx].pos[0];
				d2  = di[0]*di[0];
				di[1] = objects[i].pos[1] - objects[idx].pos[1];
				d2 += di[1]*di[1];
				di[2] = objects[i].pos[2] - objects[idx].pos[2];
				d2 += di[2]*di[2];
				if(d2<(192.f*192.f)) {
					//Check for player
					if(objects[i].id==0x00 && playerObject->state<=3) {
						//Kill player
						playerObject->state = 8;
					}
					//Check for other enemy
					else if(objects[i].id==0x02 ||
					        objects[i].id==0x03) {
						//Eject enemy
						d = sqrt(d2);
						objects[i].pos[0] = objects[idx].pos[0] + di[0]*192.f/d;
						objects[i].pos[1] = objects[idx].pos[1] + di[1]*192.f/d;
						objects[i].pos[2] = objects[idx].pos[2] + di[2]*192.f/d;
					}
					//Check for object
					else if(objects[i].state==3) {
						//Kill enemy
						objects[idx].gfx = NULL;
						objects[idx].state = 3;
						objects[idx].pathFrame = 0;
					}
				}
			}
		}
		//Check to chase player
		if((objects[idx].param&0x80)==0) {
			di[0] = playerObject->pos[0] - objects[idx].pos[0];
			d2  = di[0]*di[0];
			di[1] = playerObject->pos[1] - objects[idx].pos[1];
			d2 += di[1]*di[1];
			di[2] = playerObject->pos[2] - objects[idx].pos[2];
			d2 += di[2]*di[2];
			if(d2<(1024.f*1024.f)) {
				//Set chase state
				if(objects[idx].state<2) {
					//Set animation
					objects[idx].animId = 2;
					objects[idx].animFrame = 0;
					//Set next state
					objects[idx].state = 2;
				}
			} else {
				//Clear chase state
				if(objects[idx].state>=2) {
					//Set random timer
					objects[idx].pathId = 0;
					objects[idx].pathFrame = 0;
					//Set animation
					objects[idx].animId = 0;
					objects[idx].animFrame = 0;
					//Set next state
					objects[idx].state = 0;
				}
			}
		}
		//Animate character
		if(objects[idx].state!=3) char_proc_anim(idx);
		//Apply velocity
		objects[idx].pos[0] += objects[idx].vel[0];
		objects[idx].pos[1] += objects[idx].vel[1];
		objects[idx].pos[2] += objects[idx].vel[2];
		//Do map collision
		map_collide(idx);
	}
}
void proc_obj_ghost(int idx) {
	//Init
	if(objects[idx].mode==0) {
		//Frenzy mode check
		if((objects[idx].param&0x80)==0 && ((objects[idx].param>>4)&7)>frenzyMode) {
			objects[idx].id = 0xFF;
			return;
		}
		objects[idx].gfx = gfx_chr_ghost;
		objects[idx].mode = 1;
		objects[idx].animId = 0;
		objects[idx].animFrame = 0;
	}
	proc_obj_enemy_sub(idx,gfx_chr_ghost);
}
//Zombie
void proc_obj_zombie(int idx) {
	//Init
	if(objects[idx].mode==0) {
		//Frenzy mode check
		if((objects[idx].param&0x80)==0 && ((objects[idx].param>>4)&7)>frenzyMode) {
			objects[idx].id = 0xFF;
			return;
		}
		objects[idx].gfx = gfx_chr_zombie;
		objects[idx].mode = 1;
		objects[idx].animId = 0;
		objects[idx].animFrame = 0;
	}
	proc_obj_enemy_sub(idx,gfx_chr_zombie);
}
//Button
const Gfx * buttonGfxTable[2] = {
	gfx_obj_button1,
	gfx_obj_button2,
};
void proc_obj_button(int idx) {
	int i,j,flag;
	float di,d2;
	//Init
	if(objects[idx].mode==0) {
		objects[idx].gfx = buttonGfxTable[objects[idx].param>>7];
		objects[idx].mode = 1;
	}
	//State 0x00: Normal
	if(objects[idx].state==0) {
		for(i=0; i<OBJ_MAX; i++) {
			//Check player/object collision
			if(objects[i].id==0x00 ||
			   objects[i].id==0x08 ||
			   objects[i].id==0x09 ||
			   objects[i].id==0x0A) {
				di = objects[i].pos[0] - objects[idx].pos[0];
				d2  = di*di;
				di = objects[i].pos[1] - objects[idx].pos[1];
				d2 += di*di;
				di = objects[i].pos[2] - objects[idx].pos[2];
				d2 += di*di;
				if(d2<(192.f*192.f)) {
					//Slow down player
					if(objects[i].id==0x00) {
						objects[i].vel[0] *= 0.5f;
						objects[i].vel[2] *= 0.5f;
					}
					//Find associated gates
					for(j=0; j<OBJ_MAX; j++) {
						if(objects[j].id   ==0x05 &&
						   (objects[j].param&0x3F)==(objects[idx].param&0x3F)) {
							//Open gate
							if(objects[j].state!=2) objects[j].state = 1;
						}
					}
					//Set button state
					objects[idx].state = 1;
					objects[idx].scl[1] = 0.5f;
				}
			}
		}
	}
	//State 0x01: Pressed
	else if(objects[idx].state==1) {
		if(objects[idx].param&0x80) {
			flag = 0;
			for(i=0; i<OBJ_MAX; i++) {
				//Check player/object collision
				if(objects[i].id==0x00 ||
				   objects[i].id==0x08 ||
				   objects[i].id==0x09 ||
				   objects[i].id==0x0A) {
					di = objects[i].pos[0] - objects[idx].pos[0];
					d2  = di*di;
					di = objects[i].pos[1] - objects[idx].pos[1];
					d2 += di*di;
					di = objects[i].pos[2] - objects[idx].pos[2];
					d2 += di*di;
					if(d2<(192.f*192.f)) {
						//Set flag
						flag = 1;
					}
				}
			}
			//Check if no collision
			if(flag==0) {
				//Find associated gates
				for(j=0; j<OBJ_MAX; j++) {
					if(objects[j].id   ==0x05 &&
					   (objects[j].param&0x3F)==(objects[idx].param&0x3F)) {
						//Close gate
						if(objects[j].state!=0) objects[j].state = 3;
					}
				}
				//Set button state
				objects[idx].state = 0;
				objects[idx].scl[1] = 1.f;
			}
		}
	}
}
//Gate
const Gfx * gateGfxTable[2] = {
	gfx_obj_gate1,
	gfx_obj_gate2,
};
const float gateRotTable[2] = {
	 0.000000f,
	 1.570796f,
};
const u16 gateCheckFlagsTable[2] = {
	0x070C,0x070D
};
void proc_obj_barrier_sub(int idx,u16 checkFlags,float height) {
	int i;
	float di[3];
	for(i=0; i<OBJ_MAX; i++) {
		//Check character/object collision
		if((objects[i].id==0x00 && objects[i].state==2) || checkFlags&(1<<objects[i].id)) {
			di[0] = objects[i].pos[0] - objects[idx].pos[0];
			di[1] = objects[i].pos[1] - objects[idx].pos[1];
			di[2] = objects[i].pos[2] - objects[idx].pos[2];
			//Horizontal Z
			if(objects[idx].param&0x40) {
				if(di[2]>(-512.f-96.f) && di[2]<(512.f+96.f) && di[1]>-192.f && di[1]<height) {
					if(di[0]>0.f && di[0]<192.f) {
						objects[i].pos[0] = objects[idx].pos[0]+192.f;
					}
					else if(di[0]<0.f && di[0]>-192.f) {
						objects[i].pos[0] = objects[idx].pos[0]-192.f;
					}
				}
			}
			//Horizontal X
			else {
				if(di[0]>(-512.f-96.f) && di[0]<(512.f+96.f) && di[1]>-192.f && di[1]<height) {
					if(di[2]>0.f && di[2]<192.f) {
						objects[i].pos[2] = objects[idx].pos[2]+192.f;
					}
					else if(di[2]<0.f && di[2]>-192.f) {
						objects[i].pos[2] = objects[idx].pos[2]-192.f;
					}
				}
			}
		}
	}
}
void proc_obj_gate(int idx) {
	//Init
	if(objects[idx].mode==0) {
		objects[idx].gfx = gateGfxTable[objects[idx].param>>7];
		objects[idx].rot[1] = gateRotTable[(objects[idx].param>>6)&1];
		objects[idx].mode = 1;
	}
	//State 0x00: Normal
	if(objects[idx].state==0) {
		//Nothing
	}
	//State 0x02: Open
	if(objects[idx].state==2) {
		//Nothing
	}
	//State 0x01: Opening
	else if(objects[idx].state==1) {
		//Animate gate
		objects[idx].pos[1] += 16.f;
		objects[idx].pathFrame++;
		if(objects[idx].pathFrame==(512/16)) objects[idx].state = 2;
	}
	//State 0x03: Closing
	else if(objects[idx].state==3) {
		//Animate gate
		objects[idx].pos[1] -= 16.f;
		objects[idx].pathFrame--;
		if(objects[idx].pathFrame==0) objects[idx].state = 0;
	}
	proc_obj_barrier_sub(idx,gateCheckFlagsTable[objects[idx].param>>7],768.f);
}
//Fence
void proc_obj_fence(int idx) {
	//Init
	if(objects[idx].mode==0) {
		objects[idx].gfx = gfx_obj_fence;
		objects[idx].rot[1] = gateRotTable[(objects[idx].param>>6)&1];
		objects[idx].mode = 1;
	}
	proc_obj_barrier_sub(idx,0x070C,256.f);
}
//Gap
void proc_obj_gap(int idx) {
	//Init
	if(objects[idx].mode==0) {
		//objects[idx].gfx = gfx_obj_gap;
		objects[idx].gfx = NULL;
		objects[idx].rot[1] = gateRotTable[(objects[idx].param>>6)&1];
		objects[idx].mode = 1;
	}
	proc_obj_barrier_sub(idx,0x000D,256.f);
}
//Rock
void proc_obj_carryable_sub(int idx,Gfx* gfx) {
	int i;
	float di[3];
	float d,d2;
	//Init
	if(objects[idx].mode==0) {
		//Check for treasure
		if(objects[idx].param&0x80 && frenzyFlags[objects[idx].param&0x7F]) {
			objects[idx].id = 0xFF;
			return;
		}
		objects[idx].gfx = gfx;
		objects[idx].mode = 1;
	}
	//State 0x00: Normal
	if(objects[idx].state==0) {
		for(i=0; i<OBJ_MAX; i++) {
			//Check character/object collision
			if(objects[i].id==0x00 ||
			   objects[i].id==0x02 ||
			   objects[i].id==0x03 ||
			   objects[i].id==0x08 ||
			   objects[i].id==0x09 ||
			   objects[i].id==0x0A) {
				if(i==idx) continue;
				di[0] = objects[i].pos[0] - objects[idx].pos[0];
				d2  = di[0]*di[0];
				di[1] = objects[i].pos[1] - objects[idx].pos[1];
				d2 += di[1]*di[1];
				di[2] = objects[i].pos[2] - objects[idx].pos[2];
				d2 += di[2]*di[2];
				if(d2<(192.f*192.f)) {
					//Eject character/object
					d = sqrt(d2);
					objects[i].pos[0] = objects[idx].pos[0] + di[0]*192.f/d;
					objects[i].pos[1] = objects[idx].pos[1] + di[1]*192.f/d;
					objects[i].pos[2] = objects[idx].pos[2] + di[2]*192.f/d;
				}
			}
		}
	}
	//State 0x02: Carried
	else if(objects[idx].state==2) {
		//Check for treasure
		if(objects[idx].param&0x80 && playerObject->state==2) {
			playerObject->state = 0;
			playerObject->animId = 0;
			playerObject->animFrame = 0;
			heldObject = NULL;
			frenzyMode++;
			frenzyFlags[objects[idx].param&0x7F] = 1;
			//Set next state
			objects[idx].state = 4;
		}
	}
	//State 0x01: Carried begin (swallowing)
	else if(objects[idx].state==1) {
		//Clear graphics
		objects[idx].gfx = NULL;
		//Set next state
		objects[idx].state = 2;
	}
	//State 0x03: Carried end (spitting)
	else if(objects[idx].state==3) {
		//Set graphics
		objects[idx].gfx = gfx;
		//Apply velocity
		objects[idx].pos[0] += objects[idx].vel[0];
		objects[idx].pos[1] += objects[idx].vel[1];
		objects[idx].pos[2] += objects[idx].vel[2];
		//Do map collision
		map_collide(idx);
		//Set next state
		if(objects[idx].onGround) objects[idx].state = 0;
	}
	//State 0x04: Dead
	else if(objects[idx].state==4) {
		//Nothing
	}
}
void proc_obj_rock(int idx) {
	proc_obj_carryable_sub(idx,gfx_obj_rock);
}
//Key
const Gfx * keyGfxTable[2] = {
	gfx_obj_key1,
	gfx_obj_key2,
};
void proc_obj_key(int idx) {
	proc_obj_carryable_sub(idx,keyGfxTable[objects[idx].param&0x7F]);
}
//Gem
const Gfx * gemGfxTable[7] = {
	gfx_obj_gem1,
	gfx_obj_gem2,
	gfx_obj_gem3,
	gfx_obj_gem4,
	gfx_obj_gmet1,
	gfx_obj_gmet2,
	gfx_obj_gpearl,
};
void proc_obj_gem(int idx) {
	proc_obj_carryable_sub(idx,gemGfxTable[objects[idx].param&0x7F]);
}
//Tunnel
const Gfx * tunnelGfxTable[3] = {
	gfx_obj_tunnel1,
	gfx_obj_tunnel2,
	gfx_obj_tunnel3,
};
const float tunnelRotTable[4] = {
	 0.000000f,
	 1.570796f,
	 3.141593f,
	-1.570796f,
};
void proc_obj_tunnel(int idx) {
	float di[3];
	float dia[3];
	//Init
	if(objects[idx].mode==0) {
		objects[idx].gfx = tunnelGfxTable[(objects[idx].param>>2)&3];
		objects[idx].rot[1] = tunnelRotTable[objects[idx].param&3];
		objects[idx].mode = 1;
	}
	//Check player collision
	if(playerObject->state==0) {
		di[0] = playerObject->pos[0] - objects[idx].pos[0];
		dia[0] = fabs(di[0]);
		di[1] = playerObject->pos[1] - objects[idx].pos[1];
		dia[1] = fabs(di[1]);
		di[2] = playerObject->pos[2] - objects[idx].pos[2];
		dia[2] = fabs(di[2]);
		if(dia[0]<256.f && dia[1]<256.f && dia[2]<256.f) {
			//Check if entering
			if(dia[0]>dia[1] && dia[0]>dia[2]) {
				//Check if entering X
				if(((objects[idx].param&0xF)==0x01 && joy1Data.stick_x<0) ||
				   ((objects[idx].param&0xF)==0x03 && joy1Data.stick_x>0)) {
					playerObject->state = 5;
					playerObject->pathId = objects[idx].param>>4;
					playerObject->pathFrame = 0;
				}
			}
			else if(dia[1]>dia[2]) {
				//Nothing
			}
			else {
				//Check if entering Z
				if(((objects[idx].param&0xF)==0x00 && joy1Data.stick_y>0) ||
				   ((objects[idx].param&0xF)==0x02 && joy1Data.stick_y<0)) {
					playerObject->state = 5;
					playerObject->pathId = objects[idx].param>>4;
					playerObject->pathFrame = 0;
				}
			}
		}
	}
}
void proc_obj_warp(int idx) {
	float di[3];
	float dia[3];
	//Init
	if(objects[idx].mode==0) {
		objects[idx].gfx = NULL;
		objects[idx].mode = 1;
	}
	//Check player collision
	if(playerObject->state==0) {
		di[0] = playerObject->pos[0] - objects[idx].pos[0];
		dia[0] = fabs(di[0]);
		di[1] = playerObject->pos[1] - objects[idx].pos[1];
		dia[1] = fabs(di[1]);
		di[2] = playerObject->pos[2] - objects[idx].pos[2];
		dia[2] = fabs(di[2]);
		if(dia[0]<256.f && dia[1]<256.f && dia[2]<256.f) {
			//Warp player
			levelId = objects[idx].param&0x3F;
			warpId = objects[idx].param>>6;
			gameSubmode = 0;
		}
	}
}
void proc_obj_goal(int idx) {
	float di[3];
	float dia[3];
	//Init
	if(objects[idx].mode==0) {
		objects[idx].gfx = NULL;
		objects[idx].mode = 1;
	}
	//Check player collision
	if(playerObject->state==0 && frenzyMode!=0) {
		di[0] = playerObject->pos[0] - objects[idx].pos[0];
		dia[0] = fabs(di[0]);
		di[1] = playerObject->pos[1] - objects[idx].pos[1];
		dia[1] = fabs(di[1]);
		di[2] = playerObject->pos[2] - objects[idx].pos[2];
		dia[2] = fabs(di[2]);
		if(dia[0]<256.f && dia[1]<256.f && dia[2]<256.f) {
			//Win player
			playerObject->state = 10;
		}
	}
}
void (*procObjFuncs[16])(int idx) = {
	proc_obj_player,	//0x00: Player (slime)
	NULL,				//0x01: (DUMMY FOR ALIGNMENT)
	proc_obj_ghost,		//0x02: Ghost
	proc_obj_zombie,	//0x03: Zombie
	proc_obj_button,	//0x04: Button
	proc_obj_gate,		//0x05: Gate
	proc_obj_fence,		//0x06: Fence
	proc_obj_gap,		//0x07: Gap
	proc_obj_rock,		//0x08: Rock
	proc_obj_key,		//0x09: Key
	proc_obj_gem,		//0x0A: Gem
	NULL,				//0x0B: (DUMMY FOR ALIGNMENT)
	proc_obj_tunnel,	//0x0C: Tunnel
	proc_obj_warp,		//0x0D: Warp
	NULL,				//0x0E: (DUMMY FOR ALIGNMENT)
	proc_obj_goal,		//0x0F: Goal
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
			//Load banks
			bank_load(levelId+4);
			//Load level
			levelGfx = levelTable[levelId].gfx;
			levelColBaseX = levelTable[levelId].colBaseX;
			levelColBaseZ = levelTable[levelId].colBaseZ;
			levelColSizeX = levelTable[levelId].colSizeX;
			levelColSizeZ = levelTable[levelId].colSizeZ;
			levelColData = levelTable[levelId].colData;
			levelObjects = levelTable[levelId].objs;
			levelPaths = levelTable[levelId].paths;
			//Clear objects
			for(i=0; i<OBJ_MAX; i++) {
				objects[i].id    = 0xFF;
				objects[i].param = 0x00;
				objects[i].mode  = 0x00;
				objects[i].state = 0x00;
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
				objects[i].onGround = 1;
				objects[i].gfx = NULL;
				objects[i].animId = 0;
				objects[i].animFrame = 0;
				objects[i].pathId = 0;
				objects[i].pathFrame = 0;
				objects[i].homePos[0] = 0.f;
				objects[i].homePos[1] = 0.f;
				objects[i].homePos[2] = 0.f;
			}
			playerObject = NULL;
			heldObject = NULL;
			animTaskTimer = 0;
			//Load objects
			i = 0;
			j = 0;
			while(1) {
				objects[j].id     = levelTable[levelId].objs[i].id;
				if(objects[j].id==0xFF) break;
				if(objects[j].id==0x00) {
					//Check warp ID
					if(warpId!=(levelTable[levelId].objs[i].param>>2)) {
						i++;
						continue;
					}
					//Set player object
					playerObject = &objects[j];
				}
				objects[j].param  = levelTable[levelId].objs[i].param;
				objects[j].homePos[0] = levelTable[levelId].objs[i].pos[0];
				objects[j].homePos[1] = levelTable[levelId].objs[i].pos[1];
				objects[j].homePos[2] = levelTable[levelId].objs[i].pos[2];
				objects[j].pos[0] = levelTable[levelId].objs[i].pos[0];
				objects[j].pos[1] = levelTable[levelId].objs[i].pos[1];
				objects[j].pos[2] = levelTable[levelId].objs[i].pos[2];
				i++;
				j++;
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
			animTaskTimer++;
			break;
		}
	}
}

/////////////////////
//DISPLAY FUNCTIONS//
/////////////////////
void gm_play_disp_level() {
	//Calculate model matrix
	guTranslate    (&dynPtr->mLevelPos,0.f,0.f,0.f);
	graphics_rotate(&dynPtr->mLevelRot,0.f,0.f,0.f);
	guScale        (&dynPtr->mLevelScl,1.f,1.f,1.f);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelPos),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelRot),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	gSPMatrix(dlPtr++,OS_K0_TO_PHYSICAL(&dynPtr->mLevelScl),G_MTX_MODELVIEW|G_MTX_MUL |G_MTX_NOPUSH);
	//Draw level
	if(levelGfx!=NULL) gSPDisplayList(dlPtr++,OS_K0_TO_PHYSICAL(levelGfx));
}
void gm_play_disp_objs() {
	int i;
	for(i=0; i<OBJ_MAX; i++) {
		//Calculate model matrix
		guTranslate    (&dynPtr->mObjPos[i],objects[i].pos[0],objects[i].pos[1],objects[i].pos[2]);
		graphics_rotate(&dynPtr->mObjRot[i],objects[i].rot[0],objects[i].rot[1],objects[i].rot[2]);
		guScale        (&dynPtr->mObjScl[i],objects[i].scl[0],objects[i].scl[1],objects[i].scl[2]);
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
	eye[1] = 2048.f;
	eye[2] = 0.f;
	center[0] = 0.f;
	center[1] = 0.f;
	center[2] = 0.f;
	up[0] =  0.f;
	up[1] =  0.f;
	up[2] = -1.f;
	//Focus on player
	if(playerObject!=NULL) {
		eye[0] = playerObject->pos[0];
		eye[1] = playerObject->pos[1]+2048.f;
		eye[2] = playerObject->pos[2];
		center[0] = playerObject->pos[0];
		center[1] = playerObject->pos[1];
		center[2] = playerObject->pos[2];
	}
	//Init display
	graphics_init();
	graphics_clear();
	graphics_setup();
	graphics_view(eye,center,up);
	//Draw level
	gm_play_disp_level();
	//Draw objects
	gm_play_disp_objs();
	//End display
	graphics_end(NU_SC_SWAPBUFFER);
}
