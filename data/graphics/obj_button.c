#include "data/graphics/obj_button.h"

//Textures
u16 tex_obj_button[] = {
    0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,
    0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,
    0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,
    0x70CB,0x70CB,0x70CB,0x70CB,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,
    0x38C9,0x38C9,0x38C9,0x38C9,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,
    0x4A99,0x4A99,0x4A99,0x4A99,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x6BA3,0x6BA3,0x6BA3,0x6BA3,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x6BA3,0x6BA3,0x6BA3,0x6BA3,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x4A99,0x4A99,0x4A99,0x4A99,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x4A99,0x4A99,0x4A99,0x4A99,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x6BA3,0x6BA3,0x6BA3,0x6BA3,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xFFFF,0xFFFF,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x4A99,0x4A99,0x4A99,0x4A99,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
    0x31D1,0x31D1,0x31D1,0x31D1,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,0xDA09,
};

//Vertices
Vtx vtx_obj_button[] = {
    {0, 0, -128, 0, 128, 512, 0, 0, -127, 255},
    {0, 16, -128, 0, 128, 384, 0, 0, -127, 255},
    {49, 16, -118, 0, 128, 384, 49, 0, -117, 255},
    {49, 0, -118, 0, 128, 512, 49, 0, -117, 255},
    {91, 16, -91, 0, 128, 384, 90, 0, -90, 255},
    {91, 0, -91, 0, 128, 512, 90, 0, -90, 255},
    {118, 16, -49, 0, 96, 384, 117, 0, -49, 255},
    {118, 0, -49, 0, 96, 512, 117, 0, -49, 255},
    {128, 16, 0, 0, 96, 384, 127, 0, 0, 255},
    {128, 0, 0, 0, 96, 512, 127, 0, 0, 255},
    {118, 16, 49, 0, 96, 384, 117, 0, 49, 255},
    {118, 0, 49, 0, 96, 512, 117, 0, 49, 255},
    {91, 16, 91, 0, 64, 384, 90, 0, 90, 255},
    {91, 0, 91, 0, 64, 512, 90, 0, 90, 255},
    {49, 16, 118, 0, 64, 384, 49, 0, 117, 255},
    {49, 0, 118, 0, 64, 512, 49, 0, 117, 255},
    {0, 16, 128, 0, 64, 384, 0, 0, 127, 255},
    {0, 0, 128, 0, 64, 512, 0, 0, 127, 255},
    {-49, 16, 118, 0, 64, 384, -49, 0, 117, 255},
    {-49, 0, 118, 0, 64, 512, -49, 0, 117, 255},
    {-91, 16, 91, 0, 64, 384, -90, 0, 90, 255},
    {-91, 0, 91, 0, 64, 512, -90, 0, 90, 255},
    {-118, 16, 49, 0, 32, 384, -117, 0, 49, 255},
    {-118, 0, 49, 0, 32, 512, -117, 0, 49, 255},
    {-128, 16, 0, 0, 32, 384, -127, 0, 0, 255},
    {-128, 0, 0, 0, 32, 512, -127, 0, 0, 255},
    {-118, 16, -49, 0, 32, 384, -117, 0, -49, 255},
    {-118, 0, -49, 0, 32, 512, -117, 0, -49, 255},
    {-91, 16, -91, 0, 0, 384, -90, 0, -90, 255},
    {-91, 0, -91, 0, 0, 512, -90, 0, -90, 255},
    {-49, 16, -118, 0, 0, 384, -49, 0, -117, 255},
    {-49, 0, -118, 0, 0, 512, -49, 0, -117, 255},
    {-49, 0, -118, 0, 0, 512, -49, 0, -117, 255},
    {-49, 16, -118, 0, 0, 384, -49, 0, -117, 255},
    {0, 16, -128, 0, 0, 384, 0, 0, -127, 255},
    {0, 0, -128, 0, 0, 512, 0, 0, -127, 255},
    {0, 64, 0, 0, 320, 256, 0, 127, 0, 255},
    {-30, 64, 74, 0, 256, 480, -20, 115, 49, 255},
    {0, 64, 80, 0, 320, 512, 0, 115, 53, 255},
    {30, 64, 74, 0, 384, 480, 20, 115, 49, 255},
    {-56, 64, 56, 0, 192, 448, -37, 115, 37, 255},
    {56, 64, 56, 0, 448, 448, 37, 115, 37, 255},
    {-74, 64, 30, 0, 128, 352, -49, 115, 20, 255},
    {74, 64, 30, 0, 512, 352, 49, 115, 20, 255},
    {-80, 64, 0, 0, 128, 256, -53, 115, 0, 255},
    {80, 64, 0, 0, 512, 256, 53, 115, 0, 255},
    {-74, 64, -30, 0, 128, 160, -49, 115, -20, 255},
    {74, 64, -30, 0, 512, 160, 49, 115, -20, 255},
    {-56, 64, -56, 0, 192, 64, -37, 115, -37, 255},
    {56, 64, -56, 0, 448, 64, 37, 115, -37, 255},
    {-30, 64, -74, 0, 256, 32, -20, 115, -49, 255},
    {30, 64, -74, 0, 384, 32, 20, 115, -49, 255},
    {0, 64, -80, 0, 320, 0, 0, 115, -53, 255},
    {118, 16, 49, 0, 96, 384, 0, 127, 0, 255},
    {128, 16, 0, 0, 96, 384, 0, 127, 0, 255},
    {96, 16, 0, 0, 96, 256, 0, 127, 0, 255},
    {89, 16, 37, 0, 96, 256, 0, 127, 0, 255},
    {89, 16, -37, 0, 96, 256, 0, 127, 0, 255},
    {91, 16, 91, 0, 64, 384, 0, 127, 0, 255},
    {118, 16, -49, 0, 96, 384, 0, 127, 0, 255},
    {68, 16, 68, 0, 64, 256, 0, 127, 0, 255},
    {68, 16, -68, 0, 128, 256, 0, 127, 0, 255},
    {49, 16, 118, 0, 64, 384, 0, 127, 0, 255},
    {91, 16, -91, 0, 128, 384, 0, 127, 0, 255},
    {49, 16, 118, 0, 64, 384, 0, 127, 0, 255},
    {68, 16, 68, 0, 64, 256, 0, 127, 0, 255},
    {37, 16, 89, 0, 64, 256, 0, 127, 0, 255},
    {91, 16, -91, 0, 128, 384, 0, 127, 0, 255},
    {37, 16, -89, 0, 128, 256, 0, 127, 0, 255},
    {68, 16, -68, 0, 128, 256, 0, 127, 0, 255},
    {0, 16, 128, 0, 64, 384, 0, 127, 0, 255},
    {49, 16, -118, 0, 128, 384, 0, 127, 0, 255},
    {0, 16, 96, 0, 64, 256, 0, 127, 0, 255},
    {0, 16, -96, 0, 128, 256, 0, 127, 0, 255},
    {0, 16, -128, 0, 128, 384, 0, 127, 0, 255},
    {-49, 16, 118, 0, 64, 384, 0, 127, 0, 255},
    {-37, 16, 89, 0, 64, 256, 0, 127, 0, 255},
    {-91, 16, 91, 0, 64, 384, 0, 127, 0, 255},
    {-68, 16, 68, 0, 64, 256, 0, 127, 0, 255},
    {-118, 16, 49, 0, 32, 384, 0, 127, 0, 255},
    {-89, 16, 37, 0, 32, 256, 0, 127, 0, 255},
    {-128, 16, 0, 0, 32, 384, 0, 127, 0, 255},
    {-96, 16, 0, 0, 32, 256, 0, 127, 0, 255},
    {-118, 16, -49, 0, 32, 384, 0, 127, 0, 255},
    {-89, 16, -37, 0, 32, 256, 0, 127, 0, 255},
    {-91, 16, -91, 0, 0, 384, 0, 127, 0, 255},
    {-68, 16, -68, 0, 0, 256, 0, 127, 0, 255},
    {-49, 16, -118, 0, 0, 384, 0, 127, 0, 255},
    {-37, 16, -89, 0, 0, 256, 0, 127, 0, 255},
    {0, 16, -128, 0, 0, 384, 0, 127, 0, 255},
    {0, 16, -96, 0, 0, 256, 0, 127, 0, 255},
    {37, 16, 89, 0, 64, 256, 49, 0, 117, 255},
    {37, 48, 89, 0, 64, 64, 45, 47, 109, 255},
    {0, 48, 96, 0, 64, 64, 0, 47, 118, 255},
    {68, 16, 68, 0, 64, 256, 90, 0, 90, 255},
    {0, 16, 96, 0, 64, 256, 0, 0, 127, 255},
    {68, 16, 68, 0, 64, 256, 90, 0, 90, 255},
    {68, 48, 68, 0, 64, 64, 83, 47, 83, 255},
    {37, 48, 89, 0, 64, 64, 45, 47, 109, 255},
    {89, 16, 37, 0, 96, 256, 117, 0, 49, 255},
    {0, 48, 96, 0, 64, 64, 0, 47, 118, 255},
    {30, 64, 74, 0, 64, 0, 20, 115, 49, 255},
    {56, 64, 56, 0, 64, 0, 37, 115, 37, 255},
    {0, 64, 80, 0, 64, 0, 0, 115, 53, 255},
    {74, 64, 30, 0, 96, 0, 49, 115, 20, 255},
    {-37, 48, 89, 0, 64, 64, -45, 47, 109, 255},
    {0, 16, 96, 0, 64, 256, 0, 0, 127, 255},
    {-30, 64, 74, 0, 64, 0, -20, 115, 49, 255},
    {-37, 16, 89, 0, 64, 256, -49, 0, 117, 255},
    {-68, 48, 68, 0, 64, 64, -83, 47, 83, 255},
    {-56, 64, 56, 0, 64, 0, -37, 115, 37, 255},
    {-68, 16, 68, 0, 64, 256, -90, 0, 90, 255},
    {-89, 48, 37, 0, 32, 64, -109, 47, 45, 255},
    {-74, 64, 30, 0, 32, 0, -49, 115, 20, 255},
    {-89, 16, 37, 0, 32, 256, -117, 0, 49, 255},
    {-96, 48, 0, 0, 32, 64, -118, 47, 0, 255},
    {-80, 64, 0, 0, 32, 0, -53, 115, 0, 255},
    {-96, 16, 0, 0, 32, 256, -127, 0, 0, 255},
    {-89, 48, -37, 0, 32, 64, -109, 47, -45, 255},
    {-74, 64, -30, 0, 32, 0, -49, 115, -20, 255},
    {-89, 16, -37, 0, 32, 256, -117, 0, -49, 255},
    {-68, 48, -68, 0, 0, 64, -83, 47, -83, 255},
    {-56, 64, -56, 0, 0, 0, -37, 115, -37, 255},
    {-68, 16, -68, 0, 0, 256, -90, 0, -90, 255},
    {-37, 48, -89, 0, 0, 64, -45, 47, -109, 255},
    {-30, 64, -74, 0, 0, 0, -20, 115, -49, 255},
    {-37, 16, -89, 0, 0, 256, -49, 0, -117, 255},
    {0, 48, -96, 0, 0, 64, 0, 47, -118, 255},
    {0, 48, -96, 0, 0, 64, 0, 47, -118, 255},
    {-30, 64, -74, 0, 0, 0, -20, 115, -49, 255},
    {0, 64, -80, 0, 0, 0, 0, 115, -53, 255},
    {-37, 16, -89, 0, 0, 256, -49, 0, -117, 255},
    {0, 16, -96, 0, 0, 256, 0, 0, -127, 255},
    {68, 48, 68, 0, 64, 64, 83, 47, 83, 255},
    {89, 48, 37, 0, 96, 64, 109, 47, 45, 255},
    {74, 64, 30, 0, 96, 0, 49, 115, 20, 255},
    {89, 16, 37, 0, 96, 256, 117, 0, 49, 255},
    {80, 64, 0, 0, 96, 0, 53, 115, 0, 255},
    {96, 16, 0, 0, 96, 256, 127, 0, 0, 255},
    {96, 48, 0, 0, 96, 64, 118, 47, 0, 255},
    {74, 64, -30, 0, 96, 0, 49, 115, -20, 255},
    {89, 16, -37, 0, 96, 256, 117, 0, -49, 255},
    {89, 48, -37, 0, 96, 64, 109, 47, -45, 255},
    {56, 64, -56, 0, 128, 0, 37, 115, -37, 255},
    {68, 16, -68, 0, 128, 256, 90, 0, -90, 255},
    {68, 48, -68, 0, 128, 64, 83, 47, -83, 255},
    {30, 64, -74, 0, 128, 0, 20, 115, -49, 255},
    {37, 16, -89, 0, 128, 256, 49, 0, -117, 255},
    {37, 48, -89, 0, 128, 64, 45, 47, -109, 255},
    {0, 64, -80, 0, 128, 0, 0, 115, -53, 255},
    {0, 16, -96, 0, 128, 256, 0, 0, -127, 255},
    {0, 48, -96, 0, 128, 64, 0, 47, -118, 255},
};

//Display list
Gfx gfx_obj_button[] = {
    gsDPLoadTextureBlock(tex_obj_button, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_WRAP|G_TX_NOMIRROR, G_TX_WRAP|G_TX_NOMIRROR, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(&vtx_obj_button[0], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 8, 10, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
    gsSP2Triangles(13, 12, 14, 0, 13, 14, 15, 0),
    gsSP2Triangles(15, 14, 16, 0, 15, 16, 17, 0),
    gsSP2Triangles(17, 16, 18, 0, 17, 18, 19, 0),
    gsSP2Triangles(19, 18, 20, 0, 19, 20, 21, 0),
    gsSP2Triangles(21, 20, 22, 0, 21, 22, 23, 0),
    gsSP2Triangles(23, 22, 24, 0, 23, 24, 25, 0),
    gsSP2Triangles(25, 24, 26, 0, 25, 26, 27, 0),
    gsSP2Triangles(27, 26, 28, 0, 27, 28, 29, 0),
    gsSP2Triangles(29, 28, 30, 0, 29, 30, 31, 0),
    gsSPVertex(&vtx_obj_button[32], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(4, 8, 5, 0, 4, 7, 9, 0),
    gsSP2Triangles(4, 10, 8, 0, 4, 9, 11, 0),
    gsSP2Triangles(4, 12, 10, 0, 4, 11, 13, 0),
    gsSP2Triangles(4, 14, 12, 0, 4, 13, 15, 0),
    gsSP2Triangles(4, 16, 14, 0, 4, 15, 17, 0),
    gsSP2Triangles(4, 18, 16, 0, 4, 17, 19, 0),
    gsSP2Triangles(4, 20, 18, 0, 4, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 21, 23, 24, 0),
    gsSP2Triangles(22, 25, 23, 0, 26, 21, 24, 0),
    gsSP2Triangles(22, 27, 25, 0, 26, 24, 28, 0),
    gsSP2Triangles(27, 29, 25, 0, 30, 26, 28, 0),
    gsSP1Triangle(27, 31, 29, 0),
    gsSPVertex(&vtx_obj_button[64], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 0, 2, 0, 3, 7, 4, 0),
    gsSP2Triangles(6, 2, 8, 0, 7, 9, 4, 0),
    gsSP2Triangles(7, 10, 9, 0, 11, 6, 8, 0),
    gsSP2Triangles(11, 8, 12, 0, 13, 11, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 13, 14, 0),
    gsSP2Triangles(15, 14, 16, 0, 17, 15, 16, 0),
    gsSP2Triangles(17, 16, 18, 0, 19, 17, 18, 0),
    gsSP2Triangles(19, 18, 20, 0, 21, 19, 20, 0),
    gsSP2Triangles(21, 20, 22, 0, 23, 21, 22, 0),
    gsSP2Triangles(23, 22, 24, 0, 25, 23, 24, 0),
    gsSP2Triangles(25, 24, 26, 0, 27, 28, 29, 0),
    gsSP2Triangles(30, 28, 27, 0, 27, 29, 31, 0),
    gsSPVertex(&vtx_obj_button[96], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 2, 5, 0, 2, 6, 5, 0),
    gsSP2Triangles(2, 1, 6, 0, 4, 5, 7, 0),
    gsSP2Triangles(1, 8, 6, 0, 9, 4, 7, 0),
    gsSP2Triangles(10, 4, 9, 0, 9, 7, 11, 0),
    gsSP2Triangles(10, 9, 12, 0, 13, 9, 11, 0),
    gsSP2Triangles(12, 9, 13, 0, 13, 11, 14, 0),
    gsSP2Triangles(12, 13, 15, 0, 16, 13, 14, 0),
    gsSP2Triangles(15, 13, 16, 0, 16, 14, 17, 0),
    gsSP2Triangles(15, 16, 18, 0, 19, 16, 17, 0),
    gsSP2Triangles(18, 16, 19, 0, 19, 17, 20, 0),
    gsSP2Triangles(18, 19, 21, 0, 22, 19, 20, 0),
    gsSP2Triangles(21, 19, 22, 0, 22, 20, 23, 0),
    gsSP2Triangles(21, 22, 24, 0, 25, 22, 23, 0),
    gsSP2Triangles(24, 22, 25, 0, 25, 23, 26, 0),
    gsSP2Triangles(24, 25, 27, 0, 28, 25, 26, 0),
    gsSP2Triangles(27, 25, 28, 0, 28, 26, 29, 0),
    gsSP2Triangles(27, 28, 30, 0, 31, 28, 29, 0),
    gsSP1Triangle(30, 28, 31, 0),
    gsSPVertex(&vtx_obj_button[128], 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 6, 5, 0),
    gsSP2Triangles(6, 9, 7, 0, 10, 6, 8, 0),
    gsSP2Triangles(6, 11, 9, 0, 10, 11, 6, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 11, 10, 0),
    gsSP2Triangles(11, 14, 12, 0, 13, 14, 11, 0),
    gsSP2Triangles(14, 15, 12, 0, 16, 14, 13, 0),
    gsSP2Triangles(14, 17, 15, 0, 16, 17, 14, 0),
    gsSP2Triangles(17, 18, 15, 0, 19, 17, 16, 0),
    gsSP2Triangles(17, 20, 18, 0, 19, 20, 17, 0),
    gsSP2Triangles(20, 21, 18, 0, 22, 20, 19, 0),
    gsSP2Triangles(20, 23, 21, 0, 22, 23, 20, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
