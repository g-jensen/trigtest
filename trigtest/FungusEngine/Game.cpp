#include "Game.h"

Vector2 Game::getMousePosition()
{
	sf::Vector2f mp(sf::Mouse::getPosition(*window));
	return Vector2(mp.x,mp.y);
}

Game::Game(int width, int height, std::string title)
{
	Game::startDeltaTimer();
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	camera = new Camera(*window);
}

Game::~Game()
{
	delete window;
	delete camera;
}

sf::Clock Game::delta_timer;

sf::Time Game::getDeltaTime() {
	return Game::delta_timer.getElapsedTime();
}

double Game::getFps()
{
	return 1.0f / (float)Game::getDeltaTime().asMicroseconds() * 1000000.f;
}

void Game::resetDeltaTime()
{
	Game::delta_timer.restart();
}

void Game::startDeltaTimer()
{
	Game::delta_timer.restart();
}