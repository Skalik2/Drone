#include "data.hpp"
#include "horizon.hpp"
#include <SFML/Graphics.hpp>

#define SCREEN_RESOLUTION sf::Vector2u(1920, 1080)

int main() {
    // init here
    SensorData temp;

    sf::RenderWindow programWindow = sf::RenderWindow(sf::VideoMode(SCREEN_RESOLUTION.x ,SCREEN_RESOLUTION.y), "Okno sensorów", sf::Style::Fullscreen);
    programWindow.setFramerateLimit(60);
    programWindow.setVerticalSyncEnabled(true);
    while (programWindow.isOpen()) {

        programWindow.clear(sf::Color(48, 48, 48));

        horizon.update(temp);
        horizon.draw(programWindow);

        temp.rotation.y += 2;
        temp.rotation.x += 0.3;



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
