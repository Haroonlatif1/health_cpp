#ifndef VOICECONTROL_HPP
#define VOICECONTROL_HPP

#include <iostream>
#include <string>

namespace SmartHome {

    class VoiceControl {
    public:
        void interpretCommand(const std::string &command) {
            std::cout << "Interpreting voice command: " << command << std::endl;
            if (command == "turn on living room light") {
                std::cout << "Turning on living room light." << std::endl;
            } else if (command == "set thermostat to 22 degrees") {
                std::cout << "Setting thermostat to 22 degrees." << std::endl;
            } else {
                std::cout << "Command not recognized." << std::endl;
            }
        }
    };

}

#endif
