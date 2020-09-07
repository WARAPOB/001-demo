#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Animation.h"
int x;
sf::RectangleShape player(sf::Vector2f(40.0f, 70.0f));
sf::RenderWindow window(sf::VideoMode(800, 600), "Game01");
sf::Texture playerTexture;
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds 
    int milli_seconds = number_of_seconds;

    // Storing start time 
    clock_t start_time = clock();

    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds)
        ;
}
//1=a 2=d 3=w 4=s

void keyboardInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        player.move(-0.5f, 0.0f);
        printf("Keypress : A\n");
         
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        player.move(0.5f, 0.0f);
        printf("Keypress : D\n");
         x = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        player.move(0.0f, -0.5f);
        printf("Keypress : W\n");
        x = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        player.move(0.0f, 0.5f);
        printf("Keypress : S\n");
        x = 4;
    }
}
/*void Animation(int z) {
   /* sf::Texture playerTexture;
    playerTexture.loadFromFile("player 2.png");
    player.setTexture(&playerTexture);
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 4;
    textureSize.y /= 3;
    if (z == 0) {
        player.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 1, textureSize.x, textureSize.y));
        delay(5);
        //z++;
    }
    if (z == 1) {
        player.setTextureRect(sf::IntRect(textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));
        delay(5);
    }
}*/

int main()
{
    
    playerTexture.loadFromFile("player 2.png");
    sf::Vector2u textureSize = playerTexture.getSize();
    player.setTexture(&playerTexture);
    Animation animation(&playerTexture, sf::Vector2u(4, 3), 0.3f);
   /*textureSize.x /= 4;
    textureSize.y /= 3;
    player.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));*/
    float deltaTime = 0.0f;
    sf::Clock clock;
   
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        animation.Update(0, deltaTime);
        player.setTextureRect(animation.uvRect);
        keyboardInput();
        window.clear();
        window.draw(player);
        window.display();
        
    }
     
    return 0;
}
