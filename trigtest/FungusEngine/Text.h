#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Text : public sf::Text
{
public:
	Text(Vector2 position, std::string string);
private:
	sf::Font defaultFont;
};

