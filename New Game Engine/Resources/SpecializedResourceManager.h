#pragma once

#include "ResourceManager.h"
#include <unordered_map>
#include <string>
#include <vector>

class SpecializedResourceManager {
public:
    SpecializedResourceManager(ResourceManager& resourceManager);
    
    void gatherSpecializedResource(const std::string& resourceName);
    bool canGatherSpecializedResource(const std::string& resourceName);
    void updateSpecializedResourceConditions();

private:
    ResourceManager& resourceManager;
    std::unordered_map<std::string, bool> specializedResourceConditions;
    std::unordered_map<std::string, double> resourceSpecializationMultiplier;
};
