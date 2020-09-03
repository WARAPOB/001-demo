#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game01");
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(-0.5f,0.0f);
            printf("Keypress : A\n");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move(0.5f, 0.0f);
            printf("Keypress : D\n");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.move(0.0f, -0.5f);
            printf("Keypress : W\n");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.move(0.0f, 0.5f);
            printf("Keypress : S\n");
        }
        window.clear();
        window.draw(player);
        window.display();
        
    }

    return 0;
}
