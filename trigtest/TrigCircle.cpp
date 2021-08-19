#include "TrigCircle.h"

TrigCircle::TrigCircle(Vector2 position, float radius)
{
    this->setRadius(radius);
    this->setPosition(position.toSf());
    this->angle_d = 0.0f;
    this->angle_r = 0.0f;

    this->vertLine = sf::VertexArray(sf::Lines, 2);
    vertLine[0].position = (Vector2(this->getPosition()) + Vector2(this->getRadius(),this->getRadius() * 2)).toSf();
    vertLine[1].position = (Vector2(this->getPosition()) + Vector2(this->getRadius(), 0.f)).toSf();
    axes.push_back(vertLine);

    this->horizLine = sf::VertexArray(sf::Lines, 2);
    horizLine[0].position = (Vector2(this->getPosition()) + Vector2(0.f,this->getRadius())).toSf();
    horizLine[1].position = (Vector2(this->getPosition()) + Vector2(this->getRadius() * 2, this->getRadius())).toSf();
    axes.push_back(horizLine);

    this->angleLine = sf::VertexArray(sf::Lines, 2);
    angleLine[0].position = (Vector2(this->getPosition()) + Vector2(this->getRadius(),this->getRadius())).toSf();
    angleLine[1].position = (Vector2(this->getPosition()) + Vector2(this->getRadius() * 2, this->getRadius())).toSf();
}

std::vector<sf::VertexArray> TrigCircle::getAxes()
{
    return this->axes;
}
