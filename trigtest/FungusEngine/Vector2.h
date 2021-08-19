#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <SFML/System/Vector2.hpp>

class Vector2
{
public:
	float x;
	float y;
	Vector2();
	Vector2(float x, float y);
	Vector2(sf::Vector2f vector);
	Vector2(sf::Vector2i vector);
	const static Vector2 Zero;
	sf::Vector2f toSf();
	std::string toString();
	Vector2 operator+(const Vector2 &v);
	Vector2& operator+=(const Vector2 &v);
	Vector2 operator-(const Vector2 &v);
	Vector2& operator-=(const Vector2 &v);
	Vector2 operator*(const float s);
	Vector2 operator/(const float s);
	Vector2 operator/(const Vector2& v);
	bool operator==(const Vector2& v);
	friend std::ostream& operator<<(std::ostream &os, const Vector2 &v);
};

