#pragma once

#include "FungusEngine/FungusEngine.h"
#include "TrigCircle.h"
#include <math.h>

int main()
{
    Game game(1250, 900, "trig test");

    game.window->setView(game.camera->view);


    TrigCircle trigCircle(Vector2(game.window->getSize().x / 2.0f - (340.0f/*/2.0f*/), game.window->getSize().y / 2.0f - (320.0f/*/2.0f*/)), 340.0f);
    trigCircle.setFillColor(sf::Color::Black);
    trigCircle.setOutlineThickness(2.0f);
    trigCircle.setOutlineColor(sf::Color::White);

    float x_distance = 0;
    float y_distance = 0;
    float angle = 0;

    int unitCirclePoints[15] = { 30 , 45 , 60 , 90 , 120 , 135 , 150 , 180 , 210 , 225 , 240 , 270 , 300 , 315 , 330 };

    Text degreeLabel(Vector2(0,0),"Angle Deg: 0.00");
    degreeLabel.setPosition(Vector2(trigCircle.getPosition().x + trigCircle.getRadius() - (degreeLabel.getGlobalBounds().width / 2.0f), trigCircle.getPosition().y - 100.f).toSf());

    Text radianLabel(Vector2(0, 0), "Angle Rad π: 0.00");
    radianLabel.setPosition(Vector2(trigCircle.getPosition().x + trigCircle.getRadius() - (degreeLabel.getGlobalBounds().width / 2.0f), trigCircle.getPosition().y - 50.f).toSf());
    //sf::Font greek;
    //greek.loadFromFile("fonts/symbol.ttf");
    //radianLabel.setFont(greek);

    while (game.window->isOpen())
    {
        game.window->setFramerateLimit(300);

        sf::Event event;
        while (game.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                game.window->close();
            }
        }

        x_distance = (sf::Mouse::getPosition(*game.window).x - trigCircle.angleLine[0].position.x);
        y_distance = (sf::Mouse::getPosition(*game.window).y - trigCircle.angleLine[0].position.y);

        angle = atanf(y_distance / x_distance) * 180.f / (float)M_PI;

        // if in first quadrant
        if (x_distance > 0 && (y_distance < 0)) {
            angle = abs(angle);
        }
        // if in second quadrant
        if (x_distance < 0 && (y_distance < 0)) {
            angle = abs(90 - angle) + 90;
        }
        // if in third quadrant
        if ((x_distance < 0 && (y_distance > 0))) {
            angle = abs(angle) + 180;
        }
        // if in fourth quadrant
        if (x_distance > 0 && (y_distance > 0)) {
            angle = abs(90 - angle) + 270;
        }

        for (auto a : unitCirclePoints) {
            if (angle > a - 5 && angle < a + 5) {
                angle = a;
            }
        }
        if (angle < 360 - 5 && angle < 5) {
            angle = 360;
        }

        degreeLabel.setString("Angle Deg: " + std::to_string((int)angle));
        radianLabel.setString("Angle Rad: " + std::to_string(angle * (float)M_PI/180.f));

        trigCircle.angleLine[1].position = Vector2(
            (cosf((angle * -1) * (3.14159265 / 180)) * trigCircle.getRadius()) + trigCircle.angleLine[0].position.x,
            (sinf((angle * -1) * (3.14159265 / 180)) * trigCircle.getRadius()) + trigCircle.angleLine[0].position.y
        ).toSf();


        game.window->clear(sf::Color::Black);

        game.window->draw(trigCircle);
        game.window->draw(trigCircle.angleLine);
        for (auto line : trigCircle.getAxes()) {
            game.window->draw(line);
        }
        game.window->draw(degreeLabel);
        game.window->draw(radianLabel);

        game.window->display();

        game.window->setView(game.camera->view);

        Game::resetDeltaTime();
    }

    return 0;
}