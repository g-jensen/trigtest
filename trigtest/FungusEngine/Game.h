#pragma once

#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include "Camera.h"


class Game
{
public:
	Camera* camera;
	sf::RenderWindow* window;
	Vector2 getMousePosition();
	Game(int width, int height, std::string title);
	~Game();
	static void startDeltaTimer();
	static void resetDeltaTime();
	static sf::Time getDeltaTime();
	static double getFps();
private:
	static sf::Clock delta_timer;
};

