#pragma once

namespace MyApp::math
{
    struct Vector2
    {
        float x, y;

        Vector2() : x(0), y(0) {}
        Vector2(float _x, float _y) : x(_x), y(_y) {}
    };
}