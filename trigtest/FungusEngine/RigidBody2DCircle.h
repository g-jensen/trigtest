#pragma once

#define _USE_MATH_DEFINES

#include <stdexcept>
#include "World.h"
#include "Math.h"
#include <cmath>
#include "Vector2.h"
#include "IRigidBody2D.h"
#include <SFML/Graphics.hpp>

class RigidBody2DCircle/* : public IRigidBody2D*/
{
public:
	
	RigidBody2DCircle();
	RigidBody2DCircle(Vector2 position, float radius, float density, float restitution, bool isStatic);
	
	// inherited methods
	 void Move(Vector2 amount);
	 Vector2 getPosition();
	 Vector2 getLinearVelocity();
	 float getRotation();
	 float getRotationVelocity();
	 bool isStatic();
	 float getRestitution();
	 float getDensity();
	 Vector2 getCenter();
	 void setPosition(Vector2 position);
	 void setLinearVelocity(Vector2 velocity);
	 void setRotation(float rotation);
	 void setRotationVelocity(float velocity);
	 void setStatic(bool isStatic);
	 void setRestitution(float restitution);
	 void setDensity(float density);

	// custom methods
	float getRadius();
	void setRadius(float radius);
	sf::CircleShape getCircleShape();
	void setCircle(sf::CircleShape circle);
	bool intersects(RigidBody2DCircle circle);
	bool intersects(sf::VertexArray line);

	~RigidBody2DCircle();
private:
	sf::CircleShape circleShape; 
	Vector2 position; 
	Vector2 linearVelocity; 
	float rotation; 
	float rotationVelocity; 
	float density; 
	float mass;
	float restitution; 
	float area;
	bool p_isStatic;  
	float radius; 
	Vector2 center; 
};

