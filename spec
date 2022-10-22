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

//Common and mode graphics
beginseg
	name "gm_title"
	flags OBJECT
	address 0x80180000
	include "data/graphics/scr_title.o"
endseg
beginseg
	name "gm_play"
	flags OBJECT
	address 0x80200000
	include "data/graphics/chr_slime.o"
	include "data/graphics/chr_ghost.o"
	include "data/graphics/chr_zombie.o"
	include "data/graphics/tex_chr_eye.o"
	include "data/graphics/tex_lev_common.o"
	include "data/graphics/obj_button.o"
	include "data/graphics/obj_gate.o"
	include "data/graphics/obj_fence.o"
	include "data/graphics/obj_gap.o"
	include "data/graphics/obj_rock.o"
	include "data/graphics/obj_key.o"
	include "data/graphics/obj_gem.o"
	include "data/graphics/obj_tunnel.o"
	include "data/graphics/act_chr_slime_idle.o"
	include "data/graphics/act_chr_slime_move.o"
	include "data/graphics/act_chr_slime_idle_s.o"
	include "data/graphics/act_chr_slime_move_s.o"
	include "data/graphics/act_chr_slime_swallow.o"
	include "data/graphics/act_chr_slime_spit.o"
	include "data/graphics/act_chr_ghost_idle.o"
	include "data/graphics/act_chr_ghost_move.o"
	include "data/graphics/act_chr_ghost_chase.o"
	include "data/graphics/act_chr_zombie_idle.o"
	include "data/graphics/act_chr_zombie_move.o"
	include "data/graphics/act_chr_zombie_chase.o"
endseg
beginseg
	name "gm_over"
	flags OBJECT
	address 0x80180000
	include "data/graphics/scr_over.o"
endseg
beginseg
	name "gm_ending"
	flags OBJECT
	address 0x80180000
	include "data/graphics/scr_ending.o"
endseg

//Level graphics
beginseg
	name "lev_maptest"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_maptest.o"
endseg
beginseg
	name "lev_objtest"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_objtest.o"
endseg
beginseg
	name "lev_intro"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_intro.o"
endseg
beginseg
	name "lev_a1"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_a1.o"
endseg
beginseg
	name "lev_a2"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_a2.o"
endseg
beginseg
	name "lev_b1"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_b1.o"
endseg
beginseg
	name "lev_b2"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_b2.o"
endseg
beginseg
	name "lev_b3"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_b3.o"
endseg
beginseg
	name "lev_c1"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_c1.o"
endseg
beginseg
	name "lev_c2"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_c2.o"
endseg
beginseg
	name "lev_c3"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_c3.o"
endseg
beginseg
	name "lev_d1"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_d1.o"
endseg
beginseg
	name "lev_d2"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_d2.o"
endseg
beginseg
	name "lev_e1"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_e1.o"
endseg
beginseg
	name "lev_ending"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_ending.o"
endseg
beginseg
	name "lev_tr"
	flags OBJECT
	address 0x80280000
	include "data/graphics/lev_tr.o"
endseg

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
	include "gm_title"
	include "gm_play"
	include "gm_over"
	include "gm_ending"
	include "lev_maptest"
	include "lev_objtest"
	include "lev_intro"
	include "lev_a1"
	include "lev_a2"
	include "lev_b1"
	include "lev_b2"
	include "lev_b3"
	include "lev_c1"
	include "lev_c2"
	include "lev_c3"
	include "lev_d1"
	include "lev_d2"
	include "lev_e1"
	include "lev_ending"
	include "lev_tr"
endwave
