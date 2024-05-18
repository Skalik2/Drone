#ifndef SENSOR_DATA_HPP
#define SENSOR_DATA_HPP

#include <SFML/System.hpp>

struct SensorData {
    long double altitude = 1000;
    long double verticalVelocity = 0;
    long double horizontalVelocity = 0;
    sf::Vector3f rotation = {0, 0, 0};
};

#endif //SENSOR_DATA_HPP
