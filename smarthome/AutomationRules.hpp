#ifndef AUTOMATIONRULES_HPP
#define AUTOMATIONRULES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace SmartHome {

    class AutomationRule {
    public:
        AutomationRule(const std::string &description, std::function<void()> action)
            : description(description), action(action) {}

        void execute() {
            std::cout << "Executing rule: " << description << std::endl;
            action();
        }

    private:
        std::string description;
        std::function<void()> action;
    };

    class AutomationManager {
    public:
        void addRule(const AutomationRule &rule) {
            rules.push_back(rule);
        }

        void runAll() {
            for (const auto &rule : rules) {
                rule.execute();
            }
        }

    private:
        std::vector<AutomationRule> rules;
    };

}

#endif
