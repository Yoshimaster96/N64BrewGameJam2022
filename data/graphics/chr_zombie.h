#ifndef CHR_ZOMBIE_H
#define CHR_ZOMBIE_H

//Includes
#include <ultra64.h>
#include <nusys.h>
#include "graphics.h"
#include "data/graphics/tex_chr_eye.h"
#include "data/graphics/act_chr_zombie_idle.h"
#include "data/graphics/act_chr_zombie_move.h"
#include "data/graphics/act_chr_zombie_chase.h"

//Defines
#define VTX_BUF_ZOMBIE_SIZE	543
#define GFX_BUF_ZOMBIE_SIZE	346

//Variables
extern Vtx vtx_chr_zombie[];
extern Gfx gfx_chr_zombie[];
extern Vtx animVtxBuf_zombie[GFX_GTASK_NUM*8*VTX_BUF_ZOMBIE_SIZE];
extern Gfx animGfxBuf_zombie[GFX_GTASK_NUM*8*GFX_BUF_ZOMBIE_SIZE];

#endif
