#pragma once

#include <SFML/Graphics.hpp>
#include "FungusEngine/Vector2.h"
#include "FungusEngine/Math.h"

class TrigCircle : public sf::CircleShape
{
public:
	TrigCircle(Vector2 position, float radius);
	std::vector<sf::VertexArray> getAxes();
	sf::VertexArray angleLine;
private:
	float angle_r;
	float angle_d;
	sf::VertexArray horizLine;
	sf::VertexArray vertLine;
	std::vector<sf::VertexArray> axes;
};

