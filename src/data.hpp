#ifndef SENSOR_DATA_HPP
#define SENSOR_DATA_HPP

#include <SFML/System.hpp>
#include <thread>

struct SensorData {
    long double altitude = 1000;
    long double verticalVelocity = 0;
    long double horizontalVelocity = 0;
    sf::Vector3f rotation = {0, 0, 0};
};

void runBluetoothThread(SensorData* dataPointer);

inline std::thread bluetoothThread;

#endif //SENSOR_DATA_HPP
