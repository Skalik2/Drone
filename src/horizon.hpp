#ifndef SENSOR_OBJECTS_HPP
#define SENSOR_OBJECTS_HPP

#include <SFML/Graphics.hpp>
#include "data.hpp"

struct Horizon {
    sf::RenderTexture window;
    sf::Sprite background, scale, planeIndicator, textureSprite, angle;
    sf::Texture backgroundTexture, scaleTexture, planeIndicatorTexture, angleTexture;
    sf::RectangleShape blueShape, brownShape;

    Horizon();

    void update(const SensorData& data);
    void draw(sf::RenderWindow& target);
};

inline Horizon horizon;

#endif //SENSOR_OBJECTS_HPP
