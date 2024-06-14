#ifndef SECURITYMONITORING_HPP
#define SECURITYMONITORING_HPP

#include <iostream>
#include <thread>
#include <chrono>

namespace SmartHome {

    class SecurityCamera {
    public:
        SecurityCamera(const std::string &location) : location(location), monitoring(false) {}

        void startMonitoring() {
            monitoring = true;
            std::cout << "Security camera at " << location << " started monitoring." << std::endl;
            std::thread(&SecurityCamera::monitor, this).detach();
        }

        void stopMonitoring() {
            monitoring = false;
            std::cout << "Security camera at " << location << " stopped monitoring." << std::endl;
        }

    private:
        void monitor() {
            while (monitoring) {
                std::this_thread::sleep_for(std::chrono::seconds(5));
                std::cout << "Security camera at " << location << " is monitoring..." << std::endl;
            }
        }

        std::string location;
        bool monitoring;
    };

}

#endif
