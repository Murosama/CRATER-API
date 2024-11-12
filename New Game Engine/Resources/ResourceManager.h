#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <string>
#include "ResourceAnalytics.h"

class ResourceManager {
public:
    // Constructor initializes resources to default values
    ResourceManager();

    // Method to add resources
    void addResource(const std::string& resourceName, int amount);

    // Method to consume resources
    bool consumeResource(const std::string& resourceName, int amount);

    // Method to trade resources with a ratio of exchange
    bool tradeResource(const std::string& resourceGiven, const std::string& resourceReceived, int amountGiven, int ratio);

    // Method for resource decay over time
    void decayResource(const std::string& resourceName, int decayRate);

    // Method to calculate and display resource efficiency (consumption vs. production)
    void calculateEfficiency();

    // Method for population growth based on resources and happiness
    void growPopulation();

    // Method for dynamic resource production (based on buildings, population, etc.)
    void produceResources();

    // Method for checking if a specific resource is running low
    void checkForLowResource(const std::string& resourceName, int threshold);

    // Method to display all current resources
    void displayResources();

    void produceResource(const std::string& name, double amount);

    void depleteResource(const std::string& name, double amount);

    void adjustResourceScaling(const std::string& name, double scalingFactor);

    void registerEvent(const std::string& resourceName, const ResourceEvent& event);

    void triggerEvent(const std::string& eventName, double value);

    std::vector<double> getResourceTrends(const std::string& resourceName) const;


private:
    // Using an unordered map to store resources for flexibility
    std::unordered_map<std::string, int> resources;
    std::map<std::string, Resource> resources;
    ResourceAnalytics analytics;
    std::map<std::string, std::vector<ResourceEvent>> events;
};

#endif // RESOURCEMANAGER_H
