#ifndef GRAPHICS_H
#define GRAPHICS_H

//Includes
#include <ultra64.h>
#include <nusys.h>
#include <math.h>

//Defines
#define SCREEN_HT	240
#define SCREEN_WD	320
#define GFX_GLIST_LEN	0x1000
#define GFX_GTASK_NUM	2
#define OBJ_MAX		0x40

//Structs
typedef struct {
	Mtx mProj;
	Mtx mModel;
	Mtx mView;
	
	Mtx mLevelPos;
	Mtx mLevelRot;
	Mtx mLevelScl;
	
	Mtx mObjPos[OBJ_MAX];
	Mtx mObjRot[OBJ_MAX];
	Mtx mObjScl[OBJ_MAX];
} TDynamic;

//Variables
extern Gfx dlBuf[GFX_GTASK_NUM][GFX_GLIST_LEN];
extern Gfx * dlPtr;
extern TDynamic dynBuf[GFX_GTASK_NUM];
extern TDynamic * dynPtr;
extern u8 bufferId;

//Functions
void graphics_init();
void graphics_clear();
void graphics_view(float* camEye,float* camCenter,float* camUp);
void graphics_rotate(Mtx * m,float x,float y,float z);
void graphics_end();

#endif
