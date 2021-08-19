#include "Text.h"

Text::Text(Vector2 position, std::string string)
{
	this->setPosition(position.toSf());
	this->setString(string);
	this->defaultFont.loadFromFile("fonts/Rubik-Light.ttf");
	this->setFont(defaultFont);
}
