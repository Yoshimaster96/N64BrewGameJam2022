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

#endif