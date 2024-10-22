#ifndef RESOURCE_ECONOMY_H
#define RESOURCE_ECONOMY_H

#include "Resource.h"
#include <unordered_map>
#include <string>

class ResourceEconomy : public Resource {
public:
    ResourceEconomy(double initialAmount);
    void trade(double amount, Resource& other);
    void updateResourceValue(const std::string& resourceType, double value);
    double getCurrentWealth() const;

private:
    double wealth; // Currency amount representing the economy
    std::unordered_map<std::string, double> resourceValues; // Resource values for trading
};

#endif // RESOURCE_ECONOMY_H
