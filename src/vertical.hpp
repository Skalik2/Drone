#ifndef SENSOR_VERTICAL_HPP
#define SENSOR_VERTICAL_HPP

#include "SFML/Graphics.hpp"
#include "data.hpp"

struct Vertical {
    sf::RenderTexture window;
    sf::Sprite back, arrow, windowSprite;
    sf::Texture backTexture, arrowTexture;

    Vertical();
    void update(const SensorData &data);
    void draw(sf::RenderWindow& target);
};

inline Vertical vertical;

#endif //SENSOR_VERTICAL_HPP
