#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game01");
    sf::Texture player;
    sf::Sprite shapeSprite;
    shapeSprite.setTexture(player);
    int spriteSizeX = player.getSize().x/3;
    int spriteSizeY = player.getSize().y/4;
    shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
    while (window.isOpen())                                                         //gameloop
    {
        window.draw(shapeSprite);
        window.display();
        window.clear();
    }

    return 0;
}