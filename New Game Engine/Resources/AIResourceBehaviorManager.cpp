#include "AIResourceBehaviorManager.h"
#include <iostream>

AIResourceBehaviorManager::AIResourceBehaviorManager(ResourceManager& resourceMgr)
    : resourceManager(resourceMgr) {}

void AIResourceBehaviorManager::updateAIBehavior() {
    // Updating AI behavior based on available resources and changing conditions
    adjustAIResourceUsage();
    simulateAIResourceConsumption();
}

void AIResourceBehaviorManager::adjustAIResourceUsage() {
    // Adjusting AI's resource consumption dynamically based on availability. I'm tired. Why the heck I'm doing it?
    for (auto& need : aiNeeds) {
        for (auto& resource : aiResourcePriority) {
            if (isResourceScarce(resource.first)) {
                need -= 10;  // AI adjusts if resource is scarce
                std::cout << "AI adjusted its behavior due to scarcity of " << resource.first << "\n";
            }
        }
    }
}

void AIResourceBehaviorManager::simulateAIResourceConsumption() {
    // Simulating the AI consuming resources and adjusting based on priorities
    for (const auto& resource : aiResourcePriority) {
        double currentAmount = resourceManager.getResourceAmount(resource.first);
        if (currentAmount < 20) {
            std::cout << "AI is running low on " << resource.first << "\n";
            // Simulate behavior based on resource shortage
        }
    }
}

void AIResourceBehaviorManager::prioritizeResourceUsage(const std::string& resourceName) {
    aiResourcePriority[resourceName] = 1.0;  // Marking resource as high priority for AI
}

bool AIResourceBehaviorManager::isResourceScarce(const std::string& resourceName) {
    return resourceManager.getResourceAmount(resourceName) < 20;  // Threshold
}
