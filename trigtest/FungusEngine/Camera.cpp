
#include "Camera.h"
#include "Game.h"

Camera::Camera(sf::View& view)
{
	this->maxZoom = 256.f;
	this->minZoom = 0.0001f;
	this->zoomScale = 1;
	this->moveSpeed = 50.f;
	this->zoomAmount = 1.5f;
	this->view = view;
}

Camera::Camera(sf::RenderWindow& window)
{
	this->maxZoom = 256.f;
	this->minZoom = 0.0001f;
	this->zoomScale = 1;
	this->moveSpeed = 50.f;
	this->zoomAmount = 1.5f;
	this->view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f((float)window.getSize().x, (float)window.getSize().y)));
}

void Camera::move(float x, float y)
{
	this->view.move(x, y);
}

void Camera::zoom(float magnitude)
{
	if (zoomScale*magnitude > minZoom && zoomScale*magnitude < maxZoom) {
		this->zoomScale *= magnitude;
		this->view.zoom(magnitude);
		std::cout << std::to_string(this->zoomScale) << std::endl;
	}
}

void Camera::cameraUp(Camera &camera)
{
	camera.move(0, -camera.moveSpeed * Game::getDeltaTime().asMicroseconds() / 100000.0f);
}

void Camera::cameraDown(Camera &camera)
{
	camera.move(0, camera.moveSpeed * Game::getDeltaTime().asMicroseconds() / 100000.0f);
}

void Camera::cameraLeft(Camera &camera)
{
	camera.move(-camera.moveSpeed * Game::getDeltaTime().asMicroseconds() / 100000.0f, 0);
}

void Camera::cameraRight(Camera &camera)
{
	camera.move(camera.moveSpeed * Game::getDeltaTime().asMicroseconds() / 100000.0f, 0);
}
