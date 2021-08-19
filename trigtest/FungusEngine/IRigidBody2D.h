#pragma once
class IRigidBody2D
{
public:
	// IRigidBody2D();
	virtual void Move(Vector2 amount) = 0;
	virtual Vector2 getPosition() = 0;
	virtual Vector2 getLinearVelocity() = 0;
	virtual float getRotation() = 0;
	virtual float getRotationVelocity() = 0;
	virtual bool isStatic() = 0;
	virtual float getRestitution() = 0;
	virtual float getDensity() = 0;
	virtual Vector2 getCenter() = 0;
	virtual void setPosition(Vector2 position) = 0;
	virtual void setLinearVelocity(Vector2 velocity) = 0;
	virtual void setRotation(float rotation) = 0;
	virtual void setRotationVelocity(float velocity) = 0;
	virtual void setStatic(bool isStatic) = 0;
	virtual void setRestitution(float restitution) = 0;
	virtual void setDensity(float density) = 0;
};

