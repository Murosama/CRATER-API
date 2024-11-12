#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>
#include <memory>
#include <mutex>
#include <vector>
#include "Resource.h"

class ResourceManager {
public:
    ResourceManager();

    // Core Methods
    void addResource(const std::string& name, std::unique_ptr<Resource> resource);
    void produceResource(const std::string& name, double influenceFactor);
    void depleteResource(const std::string& name, double factor);
    
    // Real-Time Analytics
    std::vector<double> getResourceTrends() const;

    // Dynamic Scaling
    void adjustResourceScaling(const std::string& name, double newFactor);

private:
    std::map<std::string, std::unique_ptr<Resource>> resources;
    mutable std::mutex managerMutex;
};

#endif