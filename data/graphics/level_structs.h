#ifndef LEVEL_STRUCTS_H
#define LEVEL_STRUCTS_H

//Includes
#include <ultra64.h>
#include <nusys.h>

//Structs
typedef struct {
	//Actor info
	u8 id;
	u8 param;
	//Transform
	float pos[3];
} TLevelObject;
typedef struct {
	//Point info
	u16 t;
	//Transform
	float pos[3];
} TLevelPathPoint;
typedef struct {
	//Path info
	u32 nPoints;
	u16 length;
	TLevelPathPoint * points;
} TLevelPath;

#endif