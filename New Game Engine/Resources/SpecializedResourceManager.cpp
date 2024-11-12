#include "SpecializedResourceManager.h"
#include <iostream>

SpecializedResourceManager::SpecializedResourceManager(ResourceManager& resourceMgr)
    : resourceManager(resourceMgr) {
    // Initialize specialized resource conditions
    specializedResourceConditions["RareCrystal"] = true;  // Example: Only gatherable under certain conditions
    resourceSpecializationMultiplier["RareCrystal"] = 1.5;
}

bool SpecializedResourceManager::canGatherSpecializedResource(const std::string& resourceName) {
    return specializedResourceConditions[resourceName];
}

void SpecializedResourceManager::gatherSpecializedResource(const std::string& resourceName) {
    if (canGatherSpecializedResource(resourceName)) {
        double amountToGather = 100 * resourceSpecializationMultiplier[resourceName];
        resourceManager.addResource(resourceName, amountToGather);
        std::cout << "Gathered specialized resource: " << resourceName << " amount: " << amountToGather << "\n";
    } else {
        std::cout << "Cannot gather " << resourceName << " under current conditions.\n";
    }
}

void SpecializedResourceManager::updateSpecializedResourceConditions() {
    // Update the specialized resource conditions based on environmental factors
    specializedResourceConditions["RareCrystal"] = resourceManager.getResourceAmount("Gold") > 500;  // Condition example
}
