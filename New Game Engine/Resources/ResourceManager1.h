#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#pragma once
#include <map>
#include <vector>
#include "Resource.h"
#include "ResourceEvent.h"

class ResourceManager {
public:
    void produceResource(const std::string& name, double amount);
    void depleteResource(const std::string& name, double amount);
    void adjustResourceScaling(const std::string& name, double scalingFactor);
    void registerEvent(const std::string& resourceName, const ResourceEvent& event);
    void triggerEvent(const std::string& eventName, double value);

private:
    std::map<std::string, Resource> resources;
    std::map<std::string, std::vector<ResourceEvent>> events;  // Resource-specific events
};

#endif