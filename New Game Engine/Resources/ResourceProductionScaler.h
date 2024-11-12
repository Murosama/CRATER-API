#pragma once

#include "ResourceManager.h"
#include <string>

class ResourceProductionScaler {
public:
    ResourceProductionScaler(ResourceManager& resourceManager);
    
    void adjustProductionRates();
    void scaleResourceProduction(const std::string& resourceName, double rateFactor);
    
private:
    ResourceManager& resourceManager;
    double surplusThreshold = 1.5;
    double scarcityThreshold = 0.5;
    double dynamicScalingFactor = 0.1;
    std::unordered_map<std::string, double> resourceScalingFactors;
};
