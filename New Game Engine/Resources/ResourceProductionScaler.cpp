#include "ResourceProductionScaler.h"
#include <iostream>

ResourceProductionScaler::ResourceProductionScaler(ResourceManager& resourceMgr)
    : resourceManager(resourceMgr) {}

void ResourceProductionScaler::adjustProductionRates() {
    for (const auto& resource : resourceScalingFactors) {
        double resourceAmount = resourceManager.getResourceAmount(resource.first);
        if (resourceAmount > surplusThreshold) {
            scaleResourceProduction(resource.first, dynamicScalingFactor);  // Increase production
        } else if (resourceAmount < scarcityThreshold) {
            scaleResourceProduction(resource.first, -dynamicScalingFactor);  // Decrease production
        }
    }
}

void ResourceProductionScaler::scaleResourceProduction(const std::string& resourceName, double rateFactor) {
    double currentRate = resourceManager.getResourceProductionRate(resourceName);
    resourceManager.setResourceProductionRate(resourceName, currentRate + rateFactor);
    std::cout << "Resource " << resourceName << " production rate adjusted by " << rateFactor << "\n";
}
