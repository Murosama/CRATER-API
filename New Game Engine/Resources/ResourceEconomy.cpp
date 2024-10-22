#include "ResourceEconomy.h"

ResourceEconomy::ResourceEconomy(double initialAmount) 
    : Resource(initialAmount), wealth(initialAmount) {}

void ResourceEconomy::trade(double amount, Resource& other) {
    if (wealth >= amount) {
        wealth -= amount;
        other.addResource(amount); // Assuming other resource class has an addResource method
    }
}

void ResourceEconomy::updateResourceValue(const std::string& resourceType, double value) {
    resourceValues[resourceType] = value; // Update the market value of the resource
}

double ResourceEconomy::getCurrentWealth() const {
    return wealth;
}
