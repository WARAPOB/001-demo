#include <SFML/Graphics.hpp>
sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
void keyboardInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        player.move(-0.5f, 0.0f);
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
}

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game01");
    
    while (window.isOpen())
    {
        bool w = true, a = true, s = true, d = true;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        keyboardInput();
        window.clear();
        window.draw(player);
        window.display();
        
    }

    return 0;
}
