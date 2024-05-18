#include "data.hpp"
#include "horizon.hpp"
#include "altimeter.hpp"
#include <SFML/Graphics.hpp>

#define SCREEN_RESOLUTION sf::Vector2u(1920, 1080)

int main() {
    // init here
    SensorData temp;
    horizon.textureSprite.setPosition(SCREEN_RESOLUTION.x / 2, SCREEN_RESOLUTION.y / 1.5);
    altimeter.windowSprite.setPosition(420, 420);

    sf::RenderWindow programWindow = sf::RenderWindow(sf::VideoMode(SCREEN_RESOLUTION.x ,SCREEN_RESOLUTION.y), "Okno sensorów", sf::Style::Default);
    programWindow.setFramerateLimit(60);
    programWindow.setVerticalSyncEnabled(true);

    while (programWindow.isOpen()) {

        programWindow.clear(sf::Color(48, 48, 48));

        horizon.update(temp);
        horizon.draw(programWindow);
        altimeter.update(temp);
        altimeter.draw(programWindow);
        temp.altitude += 5;

        temp.rotation.y -= 0.02;
        //temp.rotation.y = 10;
        temp.rotation.x += 0.05;



        programWindow.display();

        sf::Event event = {};
        while (programWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                programWindow.close();
                break;
            }
        }
    }




    return 0;
}
