#include "data/graphics/obj_fence.h"

//Textures
u16 tex_obj_fence[] = {
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xDEF9,0x8CAB,0x8CAB,0x4A99,0xF83E,0xF83E,
    0xF83E,0xF83E,0xDEF9,0x8CAB,0x8CAB,0x4A99,0xF83E,0xF83E,
    0xF83E,0xDEF9,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x4A99,0xF83E,
    0xF83E,0x4A99,0x4A99,0x4A99,0x4A99,0x4A99,0x4A99,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xDEF9,0xDEF9,0xDEF9,0xDEF9,0x4A99,0xDEF9,0xDEF9,0xDEF9,
    0x4A99,0x4A99,0x4A99,0xDEF9,0x4A99,0x4A99,0x4A99,0x4A99,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
};

//Vertices
Vtx vtx_obj_fence[] = {
    {-256, 0, 0, 0, 0, 1024, 0, 0, 127, 255},
    {256, 0, 0, 0, 2048, 1024, 0, 0, 127, 255},
    {256, 256, 0, 0, 2048, 0, 0, 0, 127, 255},
    {-256, 256, 0, 0, 0, 0, 0, 0, 127, 255},
};

//Display list
Gfx gfx_obj_fence[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF,G_RM_AA_ZB_XLU_SURF2),
    gsDPLoadTextureBlock(tex_obj_fence, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 32, 0, G_TX_WRAP|G_TX_NOMIRROR, G_TX_WRAP|G_TX_NOMIRROR, 3, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(&vtx_obj_fence[0], 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF,G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};