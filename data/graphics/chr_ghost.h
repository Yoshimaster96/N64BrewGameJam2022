#ifndef CHR_GHOST_H
#define CHR_GHOST_H

//Includes
#include <ultra64.h>
#include <nusys.h>
#include "graphics.h"
#include "data/graphics/tex_chr_eye.h"
#include "data/graphics/act_chr_ghost_idle.h"
#include "data/graphics/act_chr_ghost_move.h"
#include "data/graphics/act_chr_ghost_chase.h"

//Defines
#define VTX_BUF_GHOST_SIZE	622
#define GFX_BUF_GHOST_SIZE	450

//Variables
extern Vtx vtx_chr_ghost[];
extern Gfx gfx_chr_ghost[];
extern Vtx animVtxBuf_ghost[GFX_GTASK_NUM*8*VTX_BUF_GHOST_SIZE];
extern Gfx animGfxBuf_ghost[GFX_GTASK_NUM*8*GFX_BUF_GHOST_SIZE];

#endif
