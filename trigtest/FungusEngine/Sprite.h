#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Sprite : public sf::Sprite
{
public:
	sf::Texture texture;
	Sprite(Vector2 position, const std::string& path);
	Sprite(Vector2 position, sf::Texture texture);
};

