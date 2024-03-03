#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);

    sf::Vector2f velocity(0.1f, 0.1f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ((circle.getPosition().x + circle.getRadius() > window.getSize().x && velocity.x > 0) ||
            (circle.getPosition().x - circle.getRadius() < 0 && velocity.x < 0))
        {
            velocity.x = -velocity.x;
        }

        if ((circle.getPosition().y + circle.getRadius() > window.getSize().y && velocity.y > 0) ||
            (circle.getPosition().y - circle.getRadius() < 0 && velocity.y < 0))
        {
            velocity.y = -velocity.y;
        }

        circle.move(velocity);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}