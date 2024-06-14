#ifndef DEVICECONTROL_HPP
#define DEVICECONTROL_HPP

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

namespace SmartHome {

    class Device {
    public:
        Device(const std::string &name) : name(name), state(false) {}
        virtual ~Device() = default;

        void turnOn() {
            state = true;
            std::cout << name << " is now ON." << std::endl;
        }

        void turnOff() {
            state = false;
            std::cout << name << " is now OFF." << std::endl;
        }

        void toggle() {
            state = !state;
            std::cout << name << " is now " << (state ? "ON" : "OFF") << std::endl;
        }

        bool getState() const {
            return state;
        }

    protected:
        std::string name;
        bool state;
    };

    class SmartLight : public Device {
    public:
        SmartLight(const std::string &name) : Device(name) {}

        void dim(int level) {
            std::cout << name << " dimmed to " << level << "%" << std::endl;
        }
    };

    class SmartThermostat : public Device {
    public:
        SmartThermostat(const std::string &name, float temp) : Device(name), temperature(temp) {}

        void setTemperature(float temp) {
            temperature = temp;
            std::cout << name << " temperature set to " << temperature << "°C" << std::endl;
        }

        float getTemperature() const {
            return temperature;
        }

    private:
        float temperature;
    };

}

#endif
