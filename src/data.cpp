#include "data.hpp"
#include <simpleble/SimpleBLE.h>
#include <iostream>
#include <vector>

void runBluetoothThread(SensorData* dataPointer) {
    if (!SimpleBLE::Adapter::bluetooth_enabled()) {
        std::cout << "Bluetooth is not enabled" << std::endl;
        return;
    }
    std::vector<SimpleBLE::Adapter> adapters = SimpleBLE::Adapter::get_adapters();
    // Get the first adapter
    SimpleBLE::Adapter adapter = adapters[0];


    adapter.scan_for(30000);

    // Get the list of peripherals found
    std::vector<SimpleBLE::Peripheral> peripherals = adapter.scan_get_results();

    // Print the identifier of each peripheral
    SimpleBLE::Peripheral mainPeripheral;
    for (auto peripheral : peripherals) {
        std::cout << "Peripheral identifier: " << peripheral.identifier() << std::endl;
        std::cout << "Peripheral address: " << peripheral.address() << std::endl;
        if (peripheral.identifier() == "Pixel 8") {
            std::cout << "Connecting to device...\n";
            mainPeripheral = peripheral;
            peripheral.connect();
            if (peripheral.is_connected()) {
                std::cout << "Connected successfully!\n";
                break;
            }
            else {
                std::cout << "Could not connect!\n";
                return;
            }
        }
    }
    if (!mainPeripheral.is_connected()) {
        return;
    }

    // Store all service and characteristic uuids in a vector.
    std::vector<std::pair<SimpleBLE::BluetoothUUID, SimpleBLE::BluetoothUUID>> uuids;
    for (auto service : mainPeripheral.services()) {
        for (auto characteristic : service.characteristics()) {
            uuids.push_back(std::make_pair(service.uuid(), characteristic.uuid()));
        }
    }

    std::cout << "The following services and characteristics were found:" << std::endl;
    for (size_t i = 0; i < uuids.size(); i++) {
        std::cout << "[" << i << "] " << uuids[i].first << " " << uuids[i].second << std::endl;
    }

    mainPeripheral.disconnect();




    return;
}
