#include "ResourceTrading.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

ResourceTrading::ResourceTrading() {
    // Initialize resources with some default amounts
    resources["Gold"] = 1000.0;
    resources["Wood"] = 500.0;
    resources["Food"] = 300.0;
    resources["Technology"] = 0.0;
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random events
}

void ResourceTrading::tradeResources(const std::string& resourceType, double amount, const std::string& targetResource) {
    if (resources[resourceType] >= amount) {
        handleTrade(resourceType, amount, targetResource);
    } else {
        std::cout << "Insufficient " << resourceType << " for trade!" << std::endl;
    }
}

void ResourceTrading::handleTrade(const std::string& resourceType, double amount, const std::string& targetResource) {
    resources[resourceType] -= amount;
    resources[targetResource] += amount; // Simplified trade logic for example
    std::cout << "Traded " << amount << " " << resourceType << " for " << targetResource << std::endl;
}

void ResourceTrading::generateRandomEvent() {
    int event = rand() % 3; // Three types of random events
    switch (event) {
        case 0:
            std::cout << "A drought has reduced your food supply!" << std::endl;
            resources["Food"] -= 50; // Random negative event
            break;
        case 1:
            std::cout << "A trader offers you a great deal!" << std::endl;
            addResource("Gold", 100); // Random positive event
            break;
        case 2:
            std::cout << "Your technology has advanced!" << std::endl;
            addResource("Technology", 50); // Another positive event
            break;
    }
}

double ResourceTrading::getResourceAmount(const std::string& resourceType) const {
    auto it = resources.find(resourceType);
    if (it != resources.end()) {
        return it->second;
    }
    return 0.0;
}

void ResourceTrading::addResource(const std::string& resourceType, double amount) {
    resources[resourceType] += amount;
}
