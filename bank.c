#include "bank.h"

//Bank data
extern char _gm_titleSegmentRomStart[],		_gm_titleSegmentRomEnd[],	_gm_titleSegmentStart[];
extern char _gm_playSegmentRomStart[],		_gm_playSegmentRomEnd[],	_gm_playSegmentStart[];
extern char _gm_overSegmentRomStart[],		_gm_overSegmentRomEnd[],	_gm_overSegmentStart[];
extern char _gm_endingSegmentRomStart[],	_gm_endingSegmentRomEnd[],	_gm_endingSegmentStart[];
extern char _lev_maptestSegmentRomStart[],	_lev_maptestSegmentRomEnd[],	_lev_maptestSegmentStart[];
extern char _lev_objtestSegmentRomStart[],	_lev_objtestSegmentRomEnd[],	_lev_objtestSegmentStart[];
typedef struct {
	char * dest;
	char * start;
	char * end;
	u8 slot;
} TSegment;
const TSegment segmentData[] = {
	{	_gm_titleSegmentStart,		_gm_titleSegmentRomStart,	_gm_titleSegmentRomEnd,		0},
	{	_gm_playSegmentStart,		_gm_playSegmentRomStart,	_gm_playSegmentRomEnd,		0},
	{	_gm_overSegmentStart,		_gm_overSegmentRomStart,	_gm_overSegmentRomEnd,		0},
	{	_gm_endingSegmentStart,		_gm_endingSegmentRomStart,	_gm_endingSegmentRomEnd,	0},
	{	_lev_maptestSegmentStart,	_lev_maptestSegmentRomStart,	_lev_maptestSegmentRomEnd,	1},
	{	_lev_objtestSegmentStart,	_lev_objtestSegmentRomStart,	_lev_objtestSegmentRomEnd,	1},
};
u8 loadedSegments[2] = {0xFF,0xFF};
OSIoMesg mqDmaBuf[2];
OSMesgQueue mqDma;

void bank_init() {
	//Init PI
	osCreatePiManager(OS_MESG_PRI_NORMAL,&mqDma,(OSMesg*)mqDmaBuf,2);
	osCreateMesgQueue(&mqDma,(OSMesg*)mqDmaBuf,2);
}
void bank_load(int idx) {
	u32 dest,src,size;
	int slot;
	//Check if loaded already
	slot = segmentData[idx].slot;
	if(loadedSegments[slot]!=idx) {
		//Copy data
		dest = (u32)segmentData[idx].dest;
		src  = (u32)segmentData[idx].start;
		size = (u32)segmentData[idx].end-src;
		if(size!=0) {
			osInvalDCache((void*)dest,size);
			osPiStartDma(mqDmaBuf,OS_MESG_PRI_NORMAL,OS_READ,src,(void*)dest,size,&mqDma);
			osRecvMesg(&mqDma,NULL,OS_MESG_BLOCK);
		}
		//Mark as loaded
		loadedSegments[slot] = idx;
	}
}
