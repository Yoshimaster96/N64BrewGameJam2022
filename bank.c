#include "bank.h"

//Bank data
extern char _gm_titleSegmentRomStart[],		_gm_titleSegmentRomEnd[],		_gm_titleSegmentStart[];
extern char _gm_playSegmentRomStart[],		_gm_playSegmentRomEnd[],		_gm_playSegmentStart[];
extern char _gm_overSegmentRomStart[],		_gm_overSegmentRomEnd[],		_gm_overSegmentStart[];
extern char _gm_endingSegmentRomStart[],	_gm_endingSegmentRomEnd[],		_gm_endingSegmentStart[];
extern char _lev_maptestSegmentRomStart[],	_lev_maptestSegmentRomEnd[],	_lev_maptestSegmentStart[];
extern char _lev_objtestSegmentRomStart[],	_lev_objtestSegmentRomEnd[],	_lev_objtestSegmentStart[];
extern char _lev_introSegmentRomStart[],	_lev_introSegmentRomEnd[],		_lev_introSegmentStart[];
extern char _lev_a1SegmentRomStart[],		_lev_a1SegmentRomEnd[],			_lev_a1SegmentStart[];
extern char _lev_a2SegmentRomStart[],		_lev_a2SegmentRomEnd[],			_lev_a2SegmentStart[];
extern char _lev_b1SegmentRomStart[],		_lev_b1SegmentRomEnd[],			_lev_b1SegmentStart[];
extern char _lev_b2SegmentRomStart[],		_lev_b2SegmentRomEnd[],			_lev_b2SegmentStart[];
extern char _lev_b3SegmentRomStart[],		_lev_b3SegmentRomEnd[],			_lev_b3SegmentStart[];
extern char _lev_c1SegmentRomStart[],		_lev_c1SegmentRomEnd[],			_lev_c1SegmentStart[];
extern char _lev_c2SegmentRomStart[],		_lev_c2SegmentRomEnd[],			_lev_c2SegmentStart[];
extern char _lev_c3SegmentRomStart[],		_lev_c3SegmentRomEnd[],			_lev_c3SegmentStart[];
extern char _lev_d1SegmentRomStart[],		_lev_d1SegmentRomEnd[],			_lev_d1SegmentStart[];
extern char _lev_d2SegmentRomStart[],		_lev_d2SegmentRomEnd[],			_lev_d2SegmentStart[];
extern char _lev_e1SegmentRomStart[],		_lev_e1SegmentRomEnd[],			_lev_e1SegmentStart[];
extern char _lev_endingSegmentRomStart[],	_lev_endingSegmentRomEnd[],		_lev_endingSegmentStart[];
extern char _lev_trSegmentRomStart[],		_lev_trSegmentRomEnd[],			_lev_trSegmentStart[];
typedef struct {
	char * dest;
	char * start;
	char * end;
	u8 slot;
} TSegment;
const TSegment segmentData[] = {
	{	_gm_titleSegmentStart,		_gm_titleSegmentRomStart,		_gm_titleSegmentRomEnd,		0},
	{	_gm_playSegmentStart,		_gm_playSegmentRomStart,		_gm_playSegmentRomEnd,		1},
	{	_gm_overSegmentStart,		_gm_overSegmentRomStart,		_gm_overSegmentRomEnd,		0},
	{	_gm_endingSegmentStart,		_gm_endingSegmentRomStart,		_gm_endingSegmentRomEnd,	0},
	{	_lev_maptestSegmentStart,	_lev_maptestSegmentRomStart,	_lev_maptestSegmentRomEnd,	2},
	{	_lev_objtestSegmentStart,	_lev_objtestSegmentRomStart,	_lev_objtestSegmentRomEnd,	2},
	{	_lev_introSegmentStart,		_lev_introSegmentRomStart,		_lev_introSegmentRomEnd,	2},
	{	_lev_a1SegmentStart,		_lev_a1SegmentRomStart,			_lev_a1SegmentRomEnd,		2},
	{	_lev_a2SegmentStart,		_lev_a2SegmentRomStart,			_lev_a2SegmentRomEnd,		2},
	{	_lev_b1SegmentStart,		_lev_b1SegmentRomStart,			_lev_b1SegmentRomEnd,		2},
	{	_lev_b2SegmentStart,		_lev_b2SegmentRomStart,			_lev_b2SegmentRomEnd,		2},
	{	_lev_b3SegmentStart,		_lev_b3SegmentRomStart,			_lev_b3SegmentRomEnd,		2},
	{	_lev_c1SegmentStart,		_lev_c1SegmentRomStart,			_lev_c1SegmentRomEnd,		2},
	{	_lev_c2SegmentStart,		_lev_c2SegmentRomStart,			_lev_c2SegmentRomEnd,		2},
	{	_lev_c3SegmentStart,		_lev_c3SegmentRomStart,			_lev_c3SegmentRomEnd,		2},
	{	_lev_d1SegmentStart,		_lev_d1SegmentRomStart,			_lev_d1SegmentRomEnd,		2},
	{	_lev_d2SegmentStart,		_lev_d2SegmentRomStart,			_lev_d2SegmentRomEnd,		2},
	{	_lev_e1SegmentStart,		_lev_e1SegmentRomStart,			_lev_e1SegmentRomEnd,		2},
	{	_lev_endingSegmentStart,	_lev_endingSegmentRomStart,		_lev_endingSegmentRomEnd,	2},
	{	_lev_trSegmentStart,		_lev_trSegmentRomStart,			_lev_trSegmentRomEnd,		2},
};
u8 loadedSegments[3] = {0xFF,0xFF,0xFF};
OSIoMesg mqDmaBuf[3];
OSMesgQueue mqDma;

void bank_init() {
	//Init PI
	osCreatePiManager(OS_MESG_PRI_NORMAL,&mqDma,(OSMesg*)mqDmaBuf,4);
	osCreateMesgQueue(&mqDma,(OSMesg*)mqDmaBuf,4);
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
