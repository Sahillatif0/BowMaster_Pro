#include<iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
    sf::Texture texture;
    if (!texture.loadFromFile("assets/p.png"))
    {
        std::cout << "Error loading texture" << std::endl;
        return -1;
    }

    sf::Sprite circle;
    circle.setTexture(texture);
    circle.setScale(0.1, 0.1);
    circle.setPosition(0, 0);
    // sf::CircleShape circle(50);
    // circle.setFillColor(sf::Color::Red);

    sf::Vector2f velocity(0.2f, 0.2f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ((circle.getPosition().x > window.getSize().x && velocity.x > 0) ||
            (circle.getPosition().x < 0 && velocity.x < 0))
        {
            // circle.setRadius(circle.getRadius()-1);
            velocity.x = -velocity.x;
        }

        if ((circle.getPosition().y > window.getSize().y && velocity.y > 0) ||
            (circle.getPosition().y < 0 && velocity.y < 0))
        {
            // circle.setRadius(circle.getRadius()-1);
            std::cout<<circle.getPosition().x<<std::endl;
            velocity.y = -velocity.y;
        }
        circle.move(velocity);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}