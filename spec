#include <nusys.h>

////////////
//SEGMENTS//
////////////
//Common data
beginseg
	name "code"
	flags BOOT OBJECT
	entry nuBoot
	address NU_SPEC_BOOT_ADDR
	stack NU_SPEC_BOOT_STACK
	include "codesegment.o"
	include "$(ROOT)/usr/lib/PR/rspboot.o"
	include "$(ROOT)/usr/lib/PR/n_aspMain.o"
	include "$(ROOT)/usr/lib/PR/gspF3DEX2.fifo.o"
	include "$(ROOT)/usr/lib/PR/gspL3DEX2.fifo.o"
	include "$(ROOT)/usr/lib/PR/gspF3DEX2.Rej.fifo.o"
	include "$(ROOT)/usr/lib/PR/gspF3DEX2.NoN.fifo.o"
	include "$(ROOT)/usr/lib/PR/gspF3DLX2.Rej.fifo.o"
	include "$(ROOT)/usr/lib/PR/gspS2DEX2.fifo.o"
endseg
/*beginseg
	name "bgm"
	flags RAW
	include "data/sound/bgm.sbk"
endseg
beginseg
	name "bgmbank"
	flags RAW
	include "data/sound/bgm.ctl" 
endseg
beginseg
	name "bgmtable"
	flags RAW
	include "data/sound/bgm.tbl" 
endseg
beginseg
	name "sebank"
	flags RAW
	include "data/sound/se.ctl" 
endseg
beginseg
	name "setable"
	flags RAW
	include "data/sound/se.tbl" 
endseg*/

////////
//WAVE//
////////
beginwave
	name "main"
	include "code"
	//include "bgm"
	//include "bgmbank"
	//include "bgmtable"
	//include "sebank"
	//include "setable"
endwave
