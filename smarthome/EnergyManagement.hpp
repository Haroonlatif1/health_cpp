#ifndef ENERGYMANAGEMENT_HPP
#define ENERGYMANAGEMENT_HPP

#include <iostream>
#include <string>
#include <vector>

namespace SmartHome {

    class EnergyMonitor {
    public:
        void addDevice(Device* device) {
            devices.push_back(device);
        }

        void reportEnergyUsage() {
            std::cout << "Energy usage report:" << std::endl;
            for (const auto &device : devices) {
                std::cout << " - " << device->getName() << ": " << (device->getState() ? "ON" : "OFF") << std::endl;
            }
        }

    private:
        std::vector<Device*> devices;
    };

}

#endif
