#ifndef LEVEL_STRUCTS_H
#define LEVEL_STRUCTS_H

//Structs
typedef struct {
	//Actor info
	u8 id;
	u8 param;
	//Transform
	float pos[3];
} TLevelObject;

#endif