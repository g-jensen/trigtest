#include "Sprite.h"

Sprite::Sprite(Vector2 position, const std::string& path)
{
	if (!this->texture.loadFromFile(path)) {
		if (!this->texture.loadFromFile("Debug/" + path)) {
			this->texture.loadFromFile("Release/" + path);
		}
	}
	this->setTexture(this->texture);
	this->setPosition(position.toSf());
}

Sprite::Sprite(Vector2 position, sf::Texture texture)
{
	this->setTexture(texture);
	this->setPosition(position.toSf());
}
