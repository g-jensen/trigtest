#pragma once

#include "Sprite.h"
#include "RigidBody2DCircle.h"
#include "Vector2.h"

class Entity
{
public:
	Entity(Vector2 position);
	~Entity();

	Sprite getSprite();
	RigidBody2DCircle getRigidBody();
	Vector2 getPosition();

	void setSprite(const Sprite& sprite);
	void setRigidBody(const RigidBody2DCircle& rigidBody);
	void setPosition(const Vector2& position);

private:
	Vector2 position;
	Sprite* sprite;
	RigidBody2DCircle* rigidBody;
};

