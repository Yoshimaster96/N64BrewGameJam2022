#ifndef GM_PLAY_H
#define GM_PLAY_H

//Includes
#include <ultra64.h>
#include <nusys.h>
#include "bank.h"
#include "graphics.h"
#include "data/graphics/lev_maptest.h"
#include "data/graphics/lev_objtest.h"
#include "data/graphics/lev_intro.h"
#include "data/graphics/lev_a1.h"
#include "data/graphics/lev_a2.h"
#include "data/graphics/lev_b1.h"
#include "data/graphics/lev_b2.h"
#include "data/graphics/lev_b3.h"
#include "data/graphics/lev_c1.h"
#include "data/graphics/lev_c2.h"
#include "data/graphics/lev_c3.h"
#include "data/graphics/lev_d1.h"
#include "data/graphics/lev_d2.h"
#include "data/graphics/lev_e1.h"
#include "data/graphics/lev_ending.h"
#include "data/graphics/lev_tr.h"
#include "data/graphics/chr_slime.h"
#include "data/graphics/chr_ghost.h"
#include "data/graphics/chr_zombie.h"
#include "data/graphics/obj_button.h"
#include "data/graphics/obj_gate.h"
#include "data/graphics/obj_fence.h"
#include "data/graphics/obj_gap.h"
#include "data/graphics/obj_rock.h"
#include "data/graphics/obj_key.h"
#include "data/graphics/obj_gem.h"
#include "data/graphics/obj_tunnel.h"

//Functions
void gm_play_disp();
void gm_play_proc();

#endif
