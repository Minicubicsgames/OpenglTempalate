#pragma once
#include <stdint.h>

namespace Engine
{
    float map(float x, float in_min, float in_max, float out_min, float out_max);

    struct Color
    {
        uint8_t r, g, b;
    };
}