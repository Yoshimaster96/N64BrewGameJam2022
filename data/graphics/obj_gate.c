#include "data/graphics/obj_gate.h"

//Textures
u16 tex_obj_gate1[] = {
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
    0xDEF9,0xDEF9,0xDEF9,0xDEF9,0x4A99,0xDEF9,0xDEF9,0xDEF9,
    0x4A99,0x4A99,0x4A99,0xDEF9,0x4A99,0x4A99,0x4A99,0x4A99,
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
    0xDEF9,0xDEF9,0xDEF9,0xDEF9,0x4A99,0xDEF9,0xDEF9,0xDEF9,
    0x4A99,0x4A99,0x4A99,0xDEF9,0x4A99,0x4A99,0x4A99,0x4A99,
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
    0xDEF9,0xDEF9,0xDEF9,0xDEF9,0x4A99,0xDEF9,0xDEF9,0xDEF9,
    0x4A99,0x4A99,0x4A99,0xDEF9,0x4A99,0x4A99,0x4A99,0x4A99,
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
    0xDEF9,0xDEF9,0xDEF9,0xDEF9,0x4A99,0xDEF9,0xDEF9,0xDEF9,
    0x4A99,0x4A99,0x4A99,0xDEF9,0x4A99,0x4A99,0x4A99,0x4A99,
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
    0xF83E,0xDEF9,0xDEF9,0xDEF9,0xDEF9,0xDEF9,0xDEF9,0xF83E,
    0xF83E,0xDEF9,0x8CAB,0x8CAB,0x8CAB,0x8CAB,0x4A99,0xF83E,
    0xF83E,0xF83E,0xDEF9,0x8CAB,0x8CAB,0x4A99,0xF83E,0xF83E,
    0xF83E,0xF83E,0xDEF9,0x8CAB,0x8CAB,0x4A99,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
    0xF83E,0xF83E,0xF83E,0xDEF9,0x4A99,0xF83E,0xF83E,0xF83E,
};
u16 tex_obj_gate2[] = {
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x9C19,0x9C19,0x7B55,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x7B55,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x9C19,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x5A51,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x7B55,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x9C19,0x5A51,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x9C19,0x5A51,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x9C19,0x5A51,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x5A51,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x7B55,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x7B55,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,0x9C19,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x7B55,0x5A51,
    0x4A99,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x6BA3,0x4A99,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x7B55,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,0x5A51,
};

//Vertices
Vtx vtx_obj_gate1[] = {
    {-512, 0, 0, 0, 0, 4096, 0, 0, 127, 255},
    {512, 0, 0, 0, 8192, 4096, 0, 0, 127, 255},
    {512, 512, 0, 0, 8192, 0, 0, 0, 127, 255},
    {-512, 512, 0, 0, 0, 0, 0, 0, 127, 255},
    {-512, 512, 0, 0, 0, 3072, 0, 0, 127, 255},
    {512, 512, 0, 0, 8192, 3072, 0, 0, 127, 255},
    {512, 768, 0, 0, 8192, 1024, 0, 0, 127, 255},
    {-512, 768, 0, 0, 0, 1024, 0, 0, 127, 255},
    {512, 0, 0, 0, 0, 4096, 0, 0, -127, 255},
    {-512, 0, 0, 0, 8192, 4096, 0, 0, -127, 255},
    {-512, 512, 0, 0, 8192, 0, 0, 0, -127, 255},
    {512, 512, 0, 0, 0, 0, 0, 0, -127, 255},
    {512, 512, 0, 0, 0, 3072, 0, 0, -127, 255},
    {-512, 512, 0, 0, 8192, 3072, 0, 0, -127, 255},
    {-512, 768, 0, 0, 8192, 1024, 0, 0, -127, 255},
    {512, 768, 0, 0, 0, 1024, 0, 0, -127, 255},
};
Vtx vtx_obj_gate2[] = {
    {-256, 0, 0, 0, 2048, 2048, 0, 0, 127, 255},
    {-256, 768, 0, 0, 2048, 0, 0, 0, 127, 255},
    {-512, 768, 0, 0, 512, 0, 0, 0, 127, 255},
    {-512, 0, 0, 0, 512, 2048, 0, 0, 127, 255},
    {-512, 768, 0, 0, 2048, 0, 0, 0, -127, 255},
    {-256, 768, 0, 0, 512, 0, 0, 0, -127, 255},
    {-256, 0, 0, 0, 512, 2048, 0, 0, -127, 255},
    {-512, 0, 0, 0, 2048, 2048, 0, 0, -127, 255},
    {0, 0, 0, 0, 2048, 2048, 0, 0, 127, 255},
    {0, 768, 0, 0, 2048, 0, 0, 0, 127, 255},
    {-256, 768, 0, 0, 512, 0, 0, 0, 127, 255},
    {-256, 0, 0, 0, 512, 2048, 0, 0, 127, 255},
    {-256, 768, 0, 0, 2048, 0, 0, 0, -127, 255},
    {0, 768, 0, 0, 512, 0, 0, 0, -127, 255},
    {0, 0, 0, 0, 512, 2048, 0, 0, -127, 255},
    {-256, 0, 0, 0, 2048, 2048, 0, 0, -127, 255},
    {256, 0, 0, 0, 2048, 2048, 0, 0, 127, 255},
    {256, 768, 0, 0, 2048, 0, 0, 0, 127, 255},
    {0, 768, 0, 0, 512, 0, 0, 0, 127, 255},
    {0, 0, 0, 0, 512, 2048, 0, 0, 127, 255},
    {0, 768, 0, 0, 2048, 0, 0, 0, -127, 255},
    {256, 768, 0, 0, 512, 0, 0, 0, -127, 255},
    {256, 0, 0, 0, 512, 2048, 0, 0, -127, 255},
    {0, 0, 0, 0, 2048, 2048, 0, 0, -127, 255},
    {512, 0, 0, 0, 2048, 2048, 0, 0, 127, 255},
    {512, 768, 0, 0, 2048, 0, 0, 0, 127, 255},
    {256, 768, 0, 0, 512, 0, 0, 0, 127, 255},
    {256, 0, 0, 0, 512, 2048, 0, 0, 127, 255},
    {256, 768, 0, 0, 2048, 0, 0, 0, -127, 255},
    {512, 768, 0, 0, 512, 0, 0, 0, -127, 255},
    {512, 0, 0, 0, 512, 2048, 0, 0, -127, 255},
    {256, 0, 0, 0, 2048, 2048, 0, 0, -127, 255},
    {-544, 512, 32, 0, 0, 0, -127, 0, 0, 255},
    {-544, 640, 32, 0, 512, 0, -127, 0, 0, 255},
    {-544, 640, -32, 0, 512, 512, -127, 0, 0, 255},
    {-544, 512, -32, 0, 0, 512, -127, 0, 0, 255},
    {-544, 512, -32, 0, 0, 512, 0, 0, -127, 255},
    {-544, 640, -32, 0, 512, 512, 0, 0, -127, 255},
    {544, 640, -32, 0, 512, 1024, 0, 0, -127, 255},
    {544, 512, -32, 0, 0, 1024, 0, 0, -127, 255},
    {544, 512, -32, 0, 0, 1024, 127, 0, 0, 255},
    {544, 640, -32, 0, 512, 1024, 127, 0, 0, 255},
    {544, 640, 32, 0, 512, 1536, 127, 0, 0, 255},
    {544, 512, 32, 0, 0, 1536, 127, 0, 0, 255},
    {544, 512, 32, 0, 0, 1536, 0, 0, 127, 255},
    {544, 640, 32, 0, 512, 1536, 0, 0, 127, 255},
    {-544, 640, 32, 0, 512, 2048, 0, 0, 127, 255},
    {-544, 512, 32, 0, 0, 2048, 0, 0, 127, 255},
    {-544, 640, 32, 0, 0, 0, 0, 127, 0, 255},
    {-512, 640, 0, 0, 512, 0, 0, 127, 0, 255},
    {-544, 640, -32, 0, 0, 512, 0, 127, 0, 255},
    {512, 640, 0, 0, 512, 1024, 0, 127, 0, 255},
    {544, 640, -32, 0, 0, 1024, 0, 127, 0, 255},
    {544, 640, 32, 0, 0, 1536, 0, 127, 0, 255},
    {-512, 640, 0, 0, 512, 2048, 0, 127, 0, 255},
    {-544, 640, 32, 0, 0, 2048, 0, 127, 0, 255},
    {-544, 512, 32, 0, 0, 0, 0, -127, 0, 255},
    {-544, 512, -32, 0, 0, 512, 0, -127, 0, 255},
    {-512, 512, 0, 0, 512, 0, 0, -127, 0, 255},
    {512, 512, 0, 0, 512, 1024, 0, -127, 0, 255},
    {544, 512, -32, 0, 0, 1024, 0, -127, 0, 255},
    {544, 512, 32, 0, 0, 1536, 0, -127, 0, 255},
    {-512, 512, 0, 0, 512, 2048, 0, -127, 0, 255},
    {-544, 512, 32, 0, 0, 2048, 0, -127, 0, 255},
    {-544, 128, 32, 0, 0, 0, -127, 0, 0, 255},
    {-544, 256, 32, 0, 512, 0, -127, 0, 0, 255},
    {-544, 256, -32, 0, 512, 512, -127, 0, 0, 255},
    {-544, 128, -32, 0, 0, 512, -127, 0, 0, 255},
    {-544, 128, -32, 0, 0, 512, 0, 0, -127, 255},
    {-544, 256, -32, 0, 512, 512, 0, 0, -127, 255},
    {544, 256, -32, 0, 512, 1024, 0, 0, -127, 255},
    {544, 128, -32, 0, 0, 1024, 0, 0, -127, 255},
    {544, 128, -32, 0, 0, 1024, 127, 0, 0, 255},
    {544, 256, -32, 0, 512, 1024, 127, 0, 0, 255},
    {544, 256, 32, 0, 512, 1536, 127, 0, 0, 255},
    {544, 128, 32, 0, 0, 1536, 127, 0, 0, 255},
    {544, 128, 32, 0, 0, 1536, 0, 0, 127, 255},
    {544, 256, 32, 0, 512, 1536, 0, 0, 127, 255},
    {-544, 256, 32, 0, 512, 2048, 0, 0, 127, 255},
    {-544, 128, 32, 0, 0, 2048, 0, 0, 127, 255},
    {-544, 256, 32, 0, 0, 0, 0, 127, 0, 255},
    {-512, 256, 0, 0, 512, 0, 0, 127, 0, 255},
    {-544, 256, -32, 0, 0, 512, 0, 127, 0, 255},
    {512, 256, 0, 0, 512, 1024, 0, 127, 0, 255},
    {544, 256, -32, 0, 0, 1024, 0, 127, 0, 255},
    {544, 256, 32, 0, 0, 1536, 0, 127, 0, 255},
    {-512, 256, 0, 0, 512, 2048, 0, 127, 0, 255},
    {-544, 256, 32, 0, 0, 2048, 0, 127, 0, 255},
    {-544, 128, 32, 0, 0, 0, 0, -127, 0, 255},
    {-544, 128, -32, 0, 0, 512, 0, -127, 0, 255},
    {-512, 128, 0, 0, 512, 0, 0, -127, 0, 255},
    {512, 128, 0, 0, 512, 1024, 0, -127, 0, 255},
    {544, 128, -32, 0, 0, 1024, 0, -127, 0, 255},
    {544, 128, 32, 0, 0, 1536, 0, -127, 0, 255},
    {-512, 128, 0, 0, 512, 2048, 0, -127, 0, 255},
    {-544, 128, 32, 0, 0, 2048, 0, -127, 0, 255},
};

//Display list
Gfx gfx_obj_gate1[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF,G_RM_AA_ZB_XLU_SURF2),
    gsDPLoadTextureBlock(tex_obj_gate1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 64, 0, G_TX_WRAP|G_TX_NOMIRROR, G_TX_WRAP|G_TX_NOMIRROR, 3, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(&vtx_obj_gate1[0], 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF,G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};
Gfx gfx_obj_gate2[] = {
    gsDPLoadTextureBlock(tex_obj_gate2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP|G_TX_NOMIRROR, G_TX_WRAP|G_TX_NOMIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(&vtx_obj_gate2[0], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPVertex(&vtx_obj_gate2[32], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(21, 19, 22, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
    gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
    gsSP2Triangles(29, 30, 27, 0, 29, 31, 30, 0),
    gsSPVertex(&vtx_obj_gate2[64], 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(21, 19, 22, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
    gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
    gsSP2Triangles(29, 30, 27, 0, 29, 31, 30, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
