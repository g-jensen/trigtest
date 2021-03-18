#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

// get set of coordinates based on a starting point (x,y), distance away from point, and angle
sf::Vector2f getCoordsToDrawLine (float x, float y, float distance, float angle) {
    sf::Vector2f vec;
    float new_x = (cosf((angle * -1) * (3.14159265/180)) * distance) + x;
    float new_y = (sinf((angle * -1) * (3.14159265/180)) * distance) + y;
    vec.x = (new_x);
    vec.y = (new_y);
    return vec;
}

// get absolute value of float
float absolute(float num) {
    if (num < 0) {
        num = num * -1;
    }
    return num;
}

std::string roundString (std::string s) {
    int indexOfPeriod = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.substr(i,1) == ".") {
            indexOfPeriod = i;
            break;
        }
    }
    std::string substring = s.substr(0,indexOfPeriod);
    return s.substr(0,indexOfPeriod+4);
}

int main () {
    float windowWidth = 1920.f;
    float windowHeight = 1080.f;

    // radius of the circle
    float radius = 500.f;
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight),"Trigonometry Test");
    
    sf::CircleShape myCircle(radius);
    
    sf::VertexArray draw_vert (sf::Lines,2);
    sf::VertexArray draw_horiz (sf::Lines,2);
    
    bool toggleDraw = true;

    myCircle.setPosition(windowWidth/2-radius,windowHeight/2-radius);
    
    sf::IntRect boundingBox(windowWidth/2-radius,windowHeight/2-radius,radius*2,radius*2);
    
    // create the xAxis
    sf::Vertex xAxisVerticies[] = {
        sf::Vertex(sf::Vector2f((myCircle.getPosition().x),(myCircle.getPosition().y+radius)),sf::Color::Red),
        sf::Vertex(sf::Vector2f((myCircle.getPosition().x+(radius*2)),(myCircle.getPosition().y+radius)),sf::Color::Red)
    };

    // create the yAxis
    sf::Vertex yAxisVerticies[] = {
        sf::Vertex(sf::Vector2f((myCircle.getPosition().x+radius),(myCircle.getPosition().y)),sf::Color::Red),
        sf::Vertex(sf::Vector2f((myCircle.getPosition().x+radius),(myCircle.getPosition().y+(radius*2))),sf::Color::Red)
    };


    while (window.isOpen()) {

    //std::vector<sf::Vertex> triangles;
    

    float angleText;
    float angle;
    float x_distance = myCircle.getPosition().x+radius - sf::Mouse::getPosition(window).x;
    float y_distance = myCircle.getPosition().y+radius - sf::Mouse::getPosition(window).y;

    // the coordinates of the tip of the horizontal line
    sf::Vector2f horizontalTip = getCoordsToDrawLine(myCircle.getPosition().x+radius,myCircle.getPosition().y+radius,radius,angle);
    // draw the line from the middle of the circle to the tip of the horizontal line
    sf::Vertex horizontalLine[] = {
        sf::Vertex(sf::Vector2f((myCircle.getPosition().x+radius),(myCircle.getPosition().y+radius)),sf::Color::Red),
        sf::Vertex(sf::Vector2f((horizontalTip.x),horizontalTip.y),sf::Color::Red)
    };

    // downward line length
    float downwardLine;
    downwardLine = radius * sinf(angle * 3.14159265/180);
    // the coordinates for the tip of the line that creates the right angle
    sf::Vector2f rightAngleVec = getCoordsToDrawLine(horizontalTip.x,horizontalTip.y,downwardLine,270);
    // draw the line
    sf::Vertex rightAngleVerticies[] = {
        sf::Vertex(sf::Vector2f((horizontalTip.x),(horizontalTip.y)),sf::Color::Red),
        sf::Vertex(sf::Vector2f((rightAngleVec.x),(rightAngleVec.y)),sf::Color::Red)
    };

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                draw_horiz[0] = sf::Vector2f((myCircle.getPosition().x+radius),(myCircle.getPosition().y+radius));
                draw_horiz[1] = sf::Vector2f((horizontalTip.x),horizontalTip.y);
                draw_vert[0] = sf::Vector2f((horizontalTip.x),(horizontalTip.y));
                draw_vert[1] = sf::Vector2f((rightAngleVec.x),(rightAngleVec.y));
                draw_vert[0].color = sf::Color::Blue;
                draw_vert[1].color = sf::Color::Blue;
                draw_horiz[0].color = sf::Color::Blue;
                draw_horiz[1].color = sf::Color::Blue;
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                bool current = toggleDraw;
                if (current == true) {
                    toggleDraw = false;
                }
                if (current == false) {
                    toggleDraw = true;
                }
            }
        }
    }

    


    float horiz;
    float padding = 15.f;
    float vert_padd = 15.f;

    horiz = sqrt((radius*radius) - (downwardLine*downwardLine))/radius;

    // if in first quadrant
    if ((x_distance < 0 && (y_distance > 0))) {
        angle = atanf(y_distance/x_distance) * -180/3.14159265;
        angleText = angle;
        vert_padd = 0;
    }
    // if in second quadrant
    if (x_distance > 0 && (y_distance > 0)) { 
        angle = atanf(y_distance/x_distance) * 180/3.14159265;
        float diff = 90 - angle;
        angle = diff + 90;
        angleText = angle;
        horiz = horiz * -1;
        vert_padd = 0;
    }
    // if in third quadrant
    if (x_distance > 0 && (y_distance < 0)) {
        angle = atanf(y_distance/x_distance) * -180/3.14159265;
        angle += 180;
        angleText = angle;
        horiz = horiz * -1;
        padding = 0;
        vert_padd = 15.f;
    }
    // if in fourth quadrant
    if (x_distance < 0 && (y_distance < 0)) {
        angle = atanf(y_distance/x_distance) * -180/3.14159265;
        angleText = angle + 360;
        padding = 0;
        vert_padd = 15.f;
    }

    sf::Font font;
    // get the font
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    
    // display for the angle in degrees
    sf::Text angle_deg;
    angle_deg.setFont(font);
    angle_deg.setPosition((10),(10));
    angle_deg.setString("angle deg: " + std::to_string(angleText));

    // display the angle in radians
    sf::Text angle_rad;
    angle_rad.setFont(font);
    angle_rad.setPosition((10),(40));
    angle_rad.setString("angle rad: " + std::to_string(angleText * 3.14159265/180));

    

    // display for the vertical line length
    sf::Text vertLine_len;
    vertLine_len.setFont(font);
    vertLine_len.setPosition(((myCircle.getPosition().x+radius) + horiz*radius),(myCircle.getPosition().y+radius-padding));
    vertLine_len.setCharacterSize(15);
    vertLine_len.setFillColor(sf::Color::Magenta);
    vertLine_len.setString(roundString((std::to_string(absolute(downwardLine)/300))));


    

    sf::Text hoizLine_len;
    hoizLine_len.setFont(font);
    hoizLine_len.setPosition((myCircle.getPosition().x+radius),(myCircle.getPosition().y+radius-vert_padd));
    hoizLine_len.setCharacterSize(15);
    hoizLine_len.setFillColor(sf::Color::Magenta);
    hoizLine_len.setString(roundString((std::to_string(absolute(horiz)))));


        // draw everything
        window.clear();
        window.draw(myCircle);
        window.draw(xAxisVerticies,2,sf::Lines);
        window.draw(yAxisVerticies,2,sf::Lines);
        window.draw(horizontalLine,2,sf::Lines);
        window.draw(rightAngleVerticies,2,sf::Lines);
        window.draw(angle_deg);
        window.draw(angle_rad);
        window.draw(vertLine_len);
        window.draw(hoizLine_len);
        if (toggleDraw) {
            window.draw(draw_horiz);
            window.draw(draw_vert);
        }
        window.display();

    }
    
}
