#include "RigidBody2DCircle.h"

void RigidBody2DCircle::Move(Vector2 amount)
{
	this->position = Vector2(amount) + this->position;
	this->circleShape.setPosition((Vector2(amount) + this->position).toSf());
	this->center = Vector2(this->position.x + this->radius, this->position.y + this->radius);
}

RigidBody2DCircle::RigidBody2DCircle() {
	this->radius = NULL;
	this->area = NULL;
	this->density = NULL;
	this->p_isStatic = NULL;
	this->mass = NULL;
	this->position = Vector2::Zero;
	this->restitution = NULL;
	this->linearVelocity = Vector2::Zero;
	this->rotation = 0.f;
	this->rotationVelocity = 0.f;
	this->circleShape = sf::CircleShape();
	this->center = Vector2::Zero;
}

RigidBody2DCircle::RigidBody2DCircle(Vector2 position, float radius, float density, float restitution, bool isStatic)
{

	float rb_area = radius * radius * (float)M_PI;

	if (rb_area < World::MinBodySize) {
		throw std::runtime_error("AREA IS SMALLER THAN MINIMUM BODY SIZE: " + std::to_string(World::MinBodySize));
		return;
	}

	if (rb_area > World::MaxBodySize) {
		throw std::runtime_error("AREA IS BIGGER THAN MAXIMUM BODY SIZE: " + std::to_string(World::MaxBodySize));
		return;
	}


	float rb_density = density;

	if (rb_density < World::MinDensity) {
		throw std::runtime_error("DENSITY IS SMALLER THAN MINIMUM DENSITY: " + std::to_string(World::MinDensity));
		return;
	}

	if (rb_density > World::MaxDensity) {
		throw std::runtime_error("DENSITY IS BIGGER THAN MAXIMUM DENSITY: " + std::to_string(World::MaxDensity));
		return;
	}

	float rb_restitution = Math::Clamp(restitution,0.f,1.f);


	this->radius = radius;
	this->area = rb_area;
	this->density = rb_density;
	this->p_isStatic = isStatic;
	this->mass = rb_area * rb_density;
	this->position = position;
	this->restitution = rb_restitution;
	this->linearVelocity = Vector2::Zero;
	this->rotation = 0.f;
	this->rotationVelocity = 0.f;
	this->circleShape = sf::CircleShape(this->radius);
	circleShape.setPosition(this->position.toSf());
	this->center = Vector2(this->position.x + this->radius, this->position.y + this->radius);
}

float RigidBody2DCircle::getRadius()
{
	return this->radius;
}

Vector2 RigidBody2DCircle::getPosition()
{
	return this->position;
}

void RigidBody2DCircle::setCircle(sf::CircleShape circle)
{
	this->circleShape = circle;
}

sf::CircleShape RigidBody2DCircle::getCircleShape()
{
	return circleShape;
}

Vector2 RigidBody2DCircle::getCenter()
{
	return this->center;
}

bool RigidBody2DCircle::intersects(RigidBody2DCircle circle)
{
	float radii = this->getRadius() + circle.getRadius();
	float distance = Math::Distance(this->getCenter(), circle.getCenter());
	if (distance >= radii) {
		return false;
	}
	return true;
}


// this doesn't work https://www.mathworks.com/matlabcentral/answers/401724-how-to-check-if-a-line-segment-intersects-a-circle
bool RigidBody2DCircle::intersects(sf::VertexArray line)
{
	Vector2 p1 = Vector2(line[0].position.x,line[0].position.y);
	Vector2 p2 = Vector2(line[1].position.x, line[1].position.y);
	Vector2 p12 = p1 - p2;
	Vector2 n = p12 / Math::Normalize(p12);
	Vector2 p1c = this->getCenter() - p1;
	float v = abs(n.x * p1c.y - n.y * p1c.x);

	return v <= this->getRadius();

}

void RigidBody2DCircle::setRadius(float radius)
{
	this->radius = radius;
	this->circleShape.setRadius(radius);
	this->center = Vector2(this->position.x + this->radius, this->position.y + this->radius);
}

void RigidBody2DCircle::setPosition(Vector2 position)
{
	this->position = position;
	this->circleShape.setPosition(position.toSf());
	this->center = Vector2(this->position.x + this->radius, this->position.y + this->radius);
}

RigidBody2DCircle::~RigidBody2DCircle()
{
	// delete circleShape;
}

