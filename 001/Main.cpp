#include <SFML/Graphics.hpp>
#include<stdlib.h>
void Animation(int);
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
        x = 0;
        Animation(x);
        player.move(-0.5f, 0.0f);
        delay(1000);
        x = 1;
        Animation(x);
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
void Animation(int z) {
   /* sf::Texture playerTexture;
    playerTexture.loadFromFile("player 2.png");*/
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
}

int main()
{
    
    playerTexture.loadFromFile("player 2.png");
    sf::Vector2u textureSize = playerTexture.getSize();
    player.setTexture(&playerTexture);
    textureSize.x /= 4;
    textureSize.y /= 3;
    player.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
   
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
