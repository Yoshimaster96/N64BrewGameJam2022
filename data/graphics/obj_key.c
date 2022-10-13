#include "data/graphics/obj_key.h"

//Textures
u16 tex_obj_key1[] = {
    0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xF507,0xF507,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xDA09,0xDA09,0xDA09,0xDA09,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0xF507,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xFE91,0xFE91,0xFE91,0xF507,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0xF507,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0xF507,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0xF507,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0x70CB,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0x70CB,0x70CB,0x70CB,0x70CB,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xF507,0xF507,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
    0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xF507,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,0xFE91,
};
u16 tex_obj_key2[] = {
    0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xDA09,0xDA09,0xDA09,0xDA09,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xDA09,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xDA09,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0x70CB,0xB10B,0xB10B,0xB10B,0xB10B,0x70CB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0x70CB,0x70CB,0x70CB,0x70CB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
    0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,0xB5B3,
};

//Vertices
Vtx vtx_obj_key[] = {
    {8, 8, -8, 0, 512, 928, 0, -127, 0, 255},
    {48, 8, -8, 0, 1024, 928, 0, -127, 0, 255},
    {48, 8, 8, 0, 1024, 928, 0, -127, 0, 255},
    {8, 8, 8, 0, 512, 928, 0, -127, 0, 255},
    {-24, 251, 16, 0, 736, 512, -49, 117, 0, 255},
    {-24, 251, -16, 0, 736, 0, -49, 117, 0, 255},
    {-45, 237, -16, 0, 704, 0, -90, 90, 0, 255},
    {0, 256, 16, 0, 768, 512, 0, 127, 0, 255},
    {-45, 237, 16, 0, 704, 512, -90, 90, 0, 255},
    {0, 256, -16, 0, 768, 0, 0, 127, 0, 255},
    {-59, 216, -16, 0, 672, 0, -117, 49, 0, 255},
    {24, 251, 16, 0, 800, 512, 49, 117, 0, 255},
    {-59, 216, 16, 0, 672, 512, -117, 49, 0, 255},
    {24, 251, -16, 0, 800, 0, 49, 117, 0, 255},
    {-64, 192, -16, 0, 640, 0, -127, 0, 0, 255},
    {45, 237, 16, 0, 832, 512, 90, 90, 0, 255},
    {-64, 192, 16, 0, 640, 512, -127, 0, 0, 255},
    {45, 237, -16, 0, 832, 0, 90, 90, 0, 255},
    {-59, 168, -16, 0, 608, 0, -117, -49, 0, 255},
    {59, 216, 16, 0, 864, 512, 117, 49, 0, 255},
    {-59, 168, 16, 0, 608, 512, -117, -49, 0, 255},
    {59, 216, -16, 0, 864, 0, 117, 49, 0, 255},
    {-45, 147, -16, 0, 576, 0, -90, -90, 0, 255},
    {64, 192, 16, 0, 896, 512, 127, 0, 0, 255},
    {-45, 147, 16, 0, 576, 512, -90, -90, 0, 255},
    {64, 192, -16, 0, 896, 0, 127, 0, 0, 255},
    {-24, 133, -16, 0, 544, 0, -49, -117, 0, 255},
    {59, 168, 16, 0, 928, 512, 117, -49, 0, 255},
    {-24, 133, 16, 0, 544, 512, -49, -117, 0, 255},
    {59, 168, -16, 0, 928, 0, 117, -49, 0, 255},
    {0, 128, -16, 0, 512, 0, 0, -127, 0, 255},
    {0, 128, 16, 0, 512, 512, 0, -127, 0, 255},
    {45, 147, 16, 0, 960, 512, 90, -90, 0, 255},
    {59, 168, -16, 0, 928, 0, 117, -49, 0, 255},
    {59, 168, 16, 0, 928, 512, 117, -49, 0, 255},
    {45, 147, -16, 0, 960, 0, 90, -90, 0, 255},
    {24, 133, 16, 0, 992, 512, 49, -117, 0, 255},
    {24, 133, -16, 0, 992, 0, 49, -117, 0, 255},
    {0, 128, 16, 0, 1024, 512, 0, -127, 0, 255},
    {0, 128, -16, 0, 1024, 0, 0, -127, 0, 255},
    {-8, 0, 8, 0, 64, 1024, -90, 0, 90, 255},
    {-8, 133, 8, 0, 64, 0, -90, 0, 90, 255},
    {-12, 133, 0, 0, 0, 0, -127, 0, 0, 255},
    {0, 0, 12, 0, 256, 1024, 0, 0, 127, 255},
    {-12, 0, 0, 0, 0, 1024, -127, 0, 0, 255},
    {0, 133, 12, 0, 256, 0, 0, 0, 127, 255},
    {-8, 133, -8, 0, 64, 0, -90, 0, -90, 255},
    {8, 0, 8, 0, 448, 1024, 90, 0, 90, 255},
    {-8, 0, -8, 0, 64, 1024, -90, 0, -90, 255},
    {8, 133, 8, 0, 448, 0, 90, 0, 90, 255},
    {0, 133, -12, 0, 256, 0, 0, 0, -127, 255},
    {12, 0, 0, 0, 512, 1024, 127, 0, 0, 255},
    {0, 0, -12, 0, 256, 1024, 0, 0, -127, 255},
    {12, 133, 0, 0, 512, 0, 127, 0, 0, 255},
    {8, 133, -8, 0, 448, 0, 90, 0, -90, 255},
    {8, 0, -8, 0, 448, 1024, 90, 0, -90, 255},
    {59, 168, -16, 0, 1056, 704, 0, 0, -127, 255},
    {59, 216, -16, 0, 1056, 320, 0, 0, -127, 255},
    {64, 192, -16, 0, 1024, 512, 0, 0, -127, 255},
    {45, 147, -16, 0, 1184, 864, 0, 0, -127, 255},
    {45, 237, -16, 0, 1184, 160, 0, 0, -127, 255},
    {24, 133, -16, 0, 1344, 992, 0, 0, -127, 255},
    {24, 251, -16, 0, 1344, 32, 0, 0, -127, 255},
    {0, 128, -16, 0, 1536, 1024, 0, 0, -127, 255},
    {0, 256, -16, 0, 1536, 0, 0, 0, -127, 255},
    {24, 251, -16, 0, 1344, 32, 0, 0, -127, 255},
    {0, 128, -16, 0, 1536, 1024, 0, 0, -127, 255},
    {-24, 133, -16, 0, 1728, 992, 0, 0, -127, 255},
    {-24, 251, -16, 0, 1728, 32, 0, 0, -127, 255},
    {-45, 147, -16, 0, 1888, 864, 0, 0, -127, 255},
    {-45, 237, -16, 0, 1888, 160, 0, 0, -127, 255},
    {-59, 168, -16, 0, 2016, 704, 0, 0, -127, 255},
    {-59, 216, -16, 0, 2016, 320, 0, 0, -127, 255},
    {-64, 192, -16, 0, 2048, 512, 0, 0, -127, 255},
    {-59, 168, 16, 0, 1056, 704, 0, 0, 127, 255},
    {-59, 216, 16, 0, 1056, 320, 0, 0, 127, 255},
    {-64, 192, 16, 0, 1024, 512, 0, 0, 127, 255},
    {-45, 147, 16, 0, 1184, 864, 0, 0, 127, 255},
    {-45, 237, 16, 0, 1184, 160, 0, 0, 127, 255},
    {-24, 133, 16, 0, 1344, 992, 0, 0, 127, 255},
    {-24, 251, 16, 0, 1344, 32, 0, 0, 127, 255},
    {0, 128, 16, 0, 1536, 1024, 0, 0, 127, 255},
    {0, 256, 16, 0, 1536, 0, 0, 0, 127, 255},
    {24, 133, 16, 0, 1728, 992, 0, 0, 127, 255},
    {24, 251, 16, 0, 1728, 32, 0, 0, 127, 255},
    {45, 147, 16, 0, 1888, 864, 0, 0, 127, 255},
    {45, 237, 16, 0, 1888, 160, 0, 0, 127, 255},
    {59, 168, 16, 0, 2016, 704, 0, 0, 127, 255},
    {59, 216, 16, 0, 2016, 320, 0, 0, 127, 255},
    {64, 192, 16, 0, 2048, 512, 0, 0, 127, 255},
    {-8, 0, -8, 0, 64, 1024, 0, -127, 0, 255},
    {-8, 0, 8, 0, 64, 1024, 0, -127, 0, 255},
    {-12, 0, 0, 0, 0, 1024, 0, -127, 0, 255},
    {0, 0, -12, 0, 256, 1024, 0, -127, 0, 255},
    {0, 0, 12, 0, 256, 1024, 0, -127, 0, 255},
    {8, 0, -8, 0, 448, 1024, 0, -127, 0, 255},
    {0, 0, 12, 0, 256, 1024, 0, -127, 0, 255},
    {8, 0, -8, 0, 448, 1024, 0, -127, 0, 255},
    {8, 0, 8, 0, 448, 1024, 0, -127, 0, 255},
    {12, 0, 0, 0, 512, 1024, 0, -127, 0, 255},
    {32, 48, -8, 0, 832, 768, 99, -79, 0, 255},
    {48, 68, -8, 0, 1024, 672, 99, -79, 0, 255},
    {48, 68, 8, 0, 1024, 672, 99, -79, 0, 255},
    {32, 48, 8, 0, 832, 768, 99, -79, 0, 255},
    {48, 28, -8, 0, 1024, 864, 99, 79, 0, 255},
    {32, 48, -8, 0, 832, 768, 99, 79, 0, 255},
    {32, 48, 8, 0, 832, 768, 99, 79, 0, 255},
    {48, 28, 8, 0, 1024, 864, 99, 79, 0, 255},
    {48, 68, -8, 0, 1024, 672, 127, 0, 0, 255},
    {48, 88, -8, 0, 1024, 608, 127, 0, 0, 255},
    {48, 88, 8, 0, 1024, 608, 127, 0, 0, 255},
    {48, 68, 8, 0, 1024, 672, 127, 0, 0, 255},
    {48, 88, -8, 0, 1024, 608, 0, 127, 0, 255},
    {8, 88, -8, 0, 512, 608, 0, 127, 0, 255},
    {8, 88, 8, 0, 512, 608, 0, 127, 0, 255},
    {48, 88, 8, 0, 1024, 608, 0, 127, 0, 255},
    {48, 8, -8, 0, 1024, 928, 127, 0, 0, 255},
    {48, 28, -8, 0, 1024, 864, 127, 0, 0, 255},
    {48, 28, 8, 0, 1024, 864, 127, 0, 0, 255},
    {48, 8, 8, 0, 1024, 928, 127, 0, 0, 255},
    {8, 88, 8, 0, 512, 608, 0, 0, 127, 255},
    {48, 68, 8, 0, 1024, 672, 0, 0, 127, 255},
    {48, 88, 8, 0, 1024, 608, 0, 0, 127, 255},
    {32, 48, 8, 0, 832, 768, 0, 0, 127, 255},
    {8, 8, 8, 0, 512, 928, 0, 0, 127, 255},
    {48, 28, 8, 0, 1024, 864, 0, 0, 127, 255},
    {48, 8, 8, 0, 1024, 928, 0, 0, 127, 255},
    {8, 88, -8, 0, 512, 608, 0, 0, -127, 255},
    {48, 88, -8, 0, 1024, 608, 0, 0, -127, 255},
    {48, 68, -8, 0, 1024, 672, 0, 0, -127, 255},
    {32, 48, -8, 0, 832, 768, 0, 0, -127, 255},
    {8, 8, -8, 0, 512, 928, 0, 0, -127, 255},
    {48, 28, -8, 0, 1024, 864, 0, 0, -127, 255},
    {48, 8, -8, 0, 1024, 928, 0, 0, -127, 255},
};

//Display list
Gfx gfx_obj_key[] = {
    gsSPVertex(&vtx_obj_key[0], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSP2Triangles(4, 6, 8, 0, 7, 9, 5, 0),
    gsSP2Triangles(8, 6, 10, 0, 11, 9, 7, 0),
    gsSP2Triangles(8, 10, 12, 0, 11, 13, 9, 0),
    gsSP2Triangles(12, 10, 14, 0, 15, 13, 11, 0),
    gsSP2Triangles(12, 14, 16, 0, 15, 17, 13, 0),
    gsSP2Triangles(16, 14, 18, 0, 19, 17, 15, 0),
    gsSP2Triangles(16, 18, 20, 0, 19, 21, 17, 0),
    gsSP2Triangles(20, 18, 22, 0, 23, 21, 19, 0),
    gsSP2Triangles(20, 22, 24, 0, 23, 25, 21, 0),
    gsSP2Triangles(24, 22, 26, 0, 27, 25, 23, 0),
    gsSP2Triangles(24, 26, 28, 0, 27, 29, 25, 0),
    gsSP2Triangles(28, 26, 30, 0, 28, 30, 31, 0),
    gsSPVertex(&vtx_obj_key[32], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 9, 8, 0),
    gsSP2Triangles(8, 10, 12, 0, 11, 13, 9, 0),
    gsSP2Triangles(12, 10, 14, 0, 15, 13, 11, 0),
    gsSP2Triangles(12, 14, 16, 0, 15, 17, 13, 0),
    gsSP2Triangles(16, 14, 18, 0, 19, 17, 15, 0),
    gsSP2Triangles(16, 18, 20, 0, 19, 21, 17, 0),
    gsSP2Triangles(20, 18, 22, 0, 23, 21, 19, 0),
    gsSP2Triangles(20, 22, 23, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 25, 24, 0),
    gsSP2Triangles(27, 28, 25, 0, 29, 28, 27, 0),
    gsSP2Triangles(29, 30, 28, 0, 31, 30, 29, 0),
    gsSPVertex(&vtx_obj_key[64], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
    gsSP2Triangles(8, 6, 7, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 11, 10, 0),
    gsSP2Triangles(13, 14, 11, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 14, 15, 0, 16, 15, 17, 0),
    gsSP2Triangles(18, 16, 17, 0, 18, 17, 19, 0),
    gsSP2Triangles(20, 18, 19, 0, 20, 19, 21, 0),
    gsSP2Triangles(22, 20, 21, 0, 22, 21, 23, 0),
    gsSP2Triangles(24, 22, 23, 0, 25, 24, 23, 0),
    gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
    gsSP2Triangles(27, 29, 30, 0, 29, 31, 30, 0),
    gsSPVertex(&vtx_obj_key[96], 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
    gsSP2Triangles(28, 27, 24, 0, 29, 27, 28, 0),
    gsSP1Triangle(30, 29, 28, 0),
    gsSPVertex(&vtx_obj_key[127], 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
    gsSP1Triangle(6, 4, 5, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
Gfx gfx_obj_key1[] = {
    gsDPLoadTextureBlock(tex_obj_key1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0, G_TX_WRAP|G_TX_NOMIRROR, G_TX_WRAP|G_TX_NOMIRROR, 5, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPDisplayList(OS_K0_TO_PHYSICAL(gfx_obj_key)),
    gsSPEndDisplayList(),
};
Gfx gfx_obj_key2[] = {
    gsDPLoadTextureBlock(tex_obj_key2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0, G_TX_WRAP|G_TX_NOMIRROR, G_TX_WRAP|G_TX_NOMIRROR, 5, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPDisplayList(OS_K0_TO_PHYSICAL(gfx_obj_key)),
    gsSPEndDisplayList(),
};
