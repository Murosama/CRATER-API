#pragma once

#include "ResourceManager.h"
#include <vector>
#include <unordered_map>

class AIResourceBehaviorManager {
public:
    AIResourceBehaviorManager(ResourceManager& resourceManager);
    
    void updateAIBehavior();
    void adjustAIResourceUsage();
    void simulateAIResourceConsumption();
    void monitorResourceTrends();
    
    // AI logic for prioritizing specific resources
    void prioritizeResourceUsage(const std::string& resourceName);
    
private:
    ResourceManager& resourceManager;
    std::unordered_map<std::string, double> aiResourcePriority;  // Resources and their priority level
    std::vector<int> aiNeeds;
    bool isResourceScarce(const std::string& resourceName);
};