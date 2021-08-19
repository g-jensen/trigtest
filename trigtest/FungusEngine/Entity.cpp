#include "Entity.h"

Entity::Entity(Vector2 position)
{
	this->position = position;
	this->sprite = nullptr;
	this->rigidBody = nullptr;
}

Entity::~Entity()
{
	delete sprite;
	delete rigidBody;
}

Sprite Entity::getSprite()
{
	return *this->sprite;
}

RigidBody2DCircle Entity::getRigidBody()
{
	return *this->rigidBody;
}

Vector2 Entity::getPosition()
{
	return this->position;
}

void Entity::setSprite(const Sprite& sprite)
{
	*this->sprite = sprite;
}

void Entity::setRigidBody(const RigidBody2DCircle& rigidBody)
{
	*this->rigidBody = rigidBody;
}

void Entity::setPosition(const Vector2& position)
{
	this->position = position;
}
