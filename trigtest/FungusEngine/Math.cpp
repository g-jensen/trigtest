#include "Math.h"

float Math::Clamp(float value, float min, float max)
{
	if (min == max) {
		return min;
	}

	if (min > max) {
		return max;
	}

	if (value < min) {
		return min;
	}

	if (value > max) {
		return max;
	}

	return value;
}

float Math::Distance(Vector2 v1, Vector2 v2) {
	float dx = (v1.x - v2.x);
	float dy = (v1.y - v2.y);

	return sqrt(dx*dx + dy*dy);

}

float Math::Length(Vector2 v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

Vector2 Math::Normalize(Vector2 v)
{
	float length = Math::Length(v);
	return Vector2(v.x/length, v.y/length);
}
