#pragma once

namespace MyApp::math
{
    struct Vector2
    {
        static Vector2 One;
		static Vector2 Zero;

        float x, y;

        Vector2() : x(0), y(0) {}
        Vector2(float _x, float _y) : x(_x), y(_y) {}
    };
}