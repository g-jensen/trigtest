#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(sf::Vector2f vector)
{
	this->x = vector.x;
	this->y = vector.y;
}

Vector2::Vector2(sf::Vector2i vector)
{
	this->x = vector.x;
	this->y = vector.y;
}

Vector2::Vector2() {
	this->x = 0.f;
	this->y = 0.f;
}



sf::Vector2f Vector2::toSf()
{
	return sf::Vector2f(this->x,this->y);
}

std::string Vector2::toString()
{
	return std::string("X: " + std::to_string(this->x) + ", " + "Y: " + std::to_string(this->y));
}

Vector2 Vector2::operator+(const Vector2& v)
{
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2& Vector2::operator+=(const Vector2 &v)
{
	*this = *this + v;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v)
{
	return Vector2(this->x - v.x, this->y - v.y);
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	*this = *this - v;
	return *this;
}

Vector2 Vector2::operator*(const float s)
{
	return Vector2(this->x * s, this->y * s);
}

Vector2 Vector2::operator/(const float s)
{
	return Vector2(this->x / s, this->y / s);
}

Vector2 Vector2::operator/(const Vector2& v)
{
	return Vector2(this->x / v.x,this->y / v.y);
}

bool Vector2::operator==(const Vector2& v)
{
	return (this->x == v.x && this->y == v.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
	std::cout << "X: " + std::to_string(v.x) + ", " + "Y: " + std::to_string(v.y);
	return os;
}

const Vector2 Vector2::Zero = Vector2(0, 0);