#include <iostream>
#include "SmartHome/DeviceControl.hpp"
#include "SmartHome/AutomationRules.hpp"
#include "SmartHome/SecurityMonitoring.hpp"
#include "SmartHome/EnergyManagement.hpp"
#include "SmartHome/VoiceControl.hpp"

using namespace SmartHome;

int main() {
    // Create devices
    SmartLight livingRoomLight("Living Room Light");
    SmartThermostat homeThermostat("Home Thermostat", 20.0);

    SecurityCamera frontDoorCamera("Front Door");

    EnergyMonitor energyMonitor;
    energyMonitor.addDevice(&livingRoomLight);
    energyMonitor.addDevice(&homeThermostat);

    AutomationManager automationManager;

    // Add automation rules
    automationManager.addRule(AutomationRule("Turn on light at 6 PM", [&]() { livingRoomLight.turnOn(); }));
    automationManager.addRule(AutomationRule("Set thermostat to 22°C when home", [&]() { homeThermostat.setTemperature(22.0); }));

    frontDoorCamera.startMonitoring();

    automationManager.runAll();

    energyMonitor.reportEnergyUsage();

    VoiceControl voiceControl;
    voiceControl.interpretCommand("turn on living room light");

    frontDoorCamera.stopMonitoring();

    return 0;
}
