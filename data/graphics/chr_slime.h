#ifndef CHR_SLIME_H
#define CHR_SLIME_H

//Includes
#include <ultra64.h>
#include <nusys.h>
#include "graphics.h"
#include "data/graphics/tex_chr_eye.h"
#include "data/graphics/act_chr_slime_idle.h"
#include "data/graphics/act_chr_slime_move.h"
#include "data/graphics/act_chr_slime_idle_s.h"
#include "data/graphics/act_chr_slime_move_s.h"
#include "data/graphics/act_chr_slime_swallow.h"
#include "data/graphics/act_chr_slime_spit.h"

//Defines
#define VTX_BUF_SLIME_SIZE	480
#define GFX_BUF_SLIME_SIZE	355

//Variables
extern Vtx vtx_chr_slime[];
extern Gfx gfx_chr_slime[];
extern Vtx animVtxBuf_slime[GFX_GTASK_NUM*1*VTX_BUF_SLIME_SIZE];
extern Gfx animGfxBuf_slime[GFX_GTASK_NUM*1*GFX_BUF_SLIME_SIZE];

#endif
