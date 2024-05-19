#ifndef SENSOR_SPEED_HPP
#define SENSOR_SPEED_HPP

#include "SFML/Graphics.hpp"
#include "data.hpp"

struct Speed {
    sf::RenderTexture window;
    sf::Sprite back, arrow, windowSprite;
    sf::Texture backTexture, arrowTexture;

    Speed();
    void update(const SensorData &data);
    void draw(sf::RenderWindow& target);
};

inline Speed speed;


#endif //SENSOR_SPEED_HPP
