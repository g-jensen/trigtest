#pragma once

#include "Vector2.h"

class Math
{
public:
	static float Clamp(float value, float min, float max);
	static float Distance(Vector2 v1, Vector2 v2);
	static float Length(Vector2 v);
	static Vector2 Normalize(Vector2 v);
};

