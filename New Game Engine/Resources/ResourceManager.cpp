#include <iostream>
#include <unordered_map>
#include <string>
#include <ResourceManager.h>

class ResourceManager {
public:
    // Constructor initializes resources to default values
    ResourceManager() {
        resources["Energy"] = 1000;
        resources["Water"] = 500;
        resources["Food"] = 200;
        resources["BuildingMaterials"] = 100;
        resources["Population"] = 50;
        resources["Gold"] = 1000;
        resources["Metal"] = 300;
        resources["Technology"] = 50;
        resources["Happiness"] = 75;  // Citizens' happiness level
    }
    ResourceManager::ResourceManager() {}

    // Method to add resources
    void addResource(const std::string& resourceName, int amount) {
        resources[resourceName] += amount;
        std::cout << amount << " " << resourceName << " added. Current: " << resources[resourceName] << std::endl;
    }

    // Method to consume resources
    bool consumeResource(const std::string& resourceName, int amount) {
        if (resources[resourceName] >= amount) {
            resources[resourceName] -= amount;
            std::cout << amount << " " << resourceName << " consumed. Current: " << resources[resourceName] << std::endl;
            return true;
        } else {
            std::cout << "Not enough " << resourceName << " available!" << std::endl;
            return false;
        }
    }

    // Method to trade resources with a ratio of exchange
    bool tradeResource(const std::string& resourceGiven, const std::string& resourceReceived, int amountGiven, int ratio) {
        if (consumeResource(resourceGiven, amountGiven)) {
            int amountReceived = amountGiven * ratio;
            addResource(resourceReceived, amountReceived);
            std::cout << "Trade successful: " << amountGiven << " " << resourceGiven << " for " << amountReceived << " " << resourceReceived << std::endl;
            return true;
        } else {
            std::cout << "Trade failed: not enough " << resourceGiven << std::endl;
            return false;
        }
    }

    // Method for resource decay over time
    void decayResource(const std::string& resourceName, int decayRate) {
        if (resources[resourceName] > decayRate) {
            resources[resourceName] -= decayRate;
            std::cout << resourceName << " decayed by " << decayRate << ". Current: " << resources[resourceName] << std::endl;
        } else {
            resources[resourceName] = 0;
            std::cout << resourceName << " fully decayed!" << std::endl;
        }
    }

    // Method to calculate and display resource efficiency (consumption vs. production)
    void calculateEfficiency() {
        std::cout << "\n---- Resource Efficiency ----" << std::endl;
        // Example: hardcoded resource production and consumption values
        int energyProduced = 200;
        int energyConsumed = 150;
        int waterProduced = 100;
        int waterConsumed = 80;

        std::cout << "Energy Efficiency: " << energyProduced - energyConsumed << std::endl;
        std::cout << "Water Efficiency: " << waterProduced - waterConsumed << std::endl;
        std::cout << "-----------------------------\n" << std::endl;
    }

    // Method for population growth based on resources and happiness
    void growPopulation() {
        int populationGrowth = 0;
        if (resources["Food"] > 100 && resources["Happiness"] > 60) {
            populationGrowth = resources["Population"] * 0.05;  // Growth rate of 5%
            addResource("Population", populationGrowth);
            std::cout << "Population grew by " << populationGrowth << "!" << std::endl;
        } else {
            std::cout << "Not enough resources or happiness for population growth!" << std::endl;
        }
    }

    // Method for dynamic resource production (based on buildings, population, etc.)
    void produceResources() {
        int newEnergy = resources["Population"] * 10;  // Example: each citizen generates 10 energy
        int newFood = resources["Population"] * 5;     // Example: each citizen produces 5 food
        int newTechnology = resources["Population"] * 1; // Example: each citizen adds 1 technology point

        addResource("Energy", newEnergy);
        addResource("Food", newFood);
        addResource("Technology", newTechnology);

        std::cout << "Resources produced by population!" << std::endl;
    }

    // Method for checking if a specific resource is running low
    void checkForLowResource(const std::string& resourceName, int threshold) {
        if (resources[resourceName] < threshold) {
            std::cout << resourceName << " is running low! Current: " << resources[resourceName] << std::endl;
        } else {
            std::cout << resourceName << " is in good supply." << std::endl;
        }
    }

    // Method to display all current resources
    void displayResources() {
        std::cout << "\n---- Current Resources ----" << std::endl;
        for (const auto& resource : resources) {
            std::cout << resource.first << ": " << resource.second << std::endl;
        }
        std::cout << "--------------------------\n" << std::endl;
    }

    void ResourceManager::produceResource(const std::string& name, double amount) {
        resources[name].produce(amount);
    }

    void ResourceManager::depleteResource(const std::string& name, double amount) {
        resources[name].deplete(amount);
    }

    std::vector<double> ResourceManager::getResourceTrends(const std::string& name) const {
    return resources.at(name).getAnalytics();
    }

    void ResourceManager::adjustResourceScaling(const std::string& name, double scalingFactor) {
        resources[name].setScalingFactor(scalingFactor);
    }

    double ResourceManager::getResourceAmount(const std::string& name) const {
        return resources.at(name).getCurrentAmount();
    }

    void ResourceManager::registerEvent(const std::string& resourceName, const ResourceEvent& event) {
        events[resourceName].push_back(event);
}

    void ResourceManager::triggerEvent(const std::string& eventName, double value) {
        for (auto& [resourceName, resourceEvents] : events) {
            for (auto& event : resourceEvents) {
                if (event.getName() == eventName) {
                 event.triggerEvent(value);
            }
        }
    }
}


    void ResourceManager::produceResource(const std::string& name, double amount) {
        resources[name].produce(amount);
        analytics.recordTrend(name, resources[name].getCurrentAmount());  // Track trend after production
}

    void ResourceManager::depleteResource(const std::string& name, double amount) {
        resources[name].deplete(amount);
        analytics.recordTrend(name, resources[name].getCurrentAmount());  // Track trend after depletion
}

    std::vector<double> ResourceManager::getResourceTrends(const std::string& resourceName) const {
        return analytics.getTrends(resourceName);
}

private:
    // Using an unordered map to store resources for flexibility
    std::unordered_map<std::string, int> resources;
};

int main() {
    ResourceManager manager;

    // Display initial resources
    manager.displayResources();

    // Example actions:
    manager.addResource("Energy", 200);  // Adding energy
    manager.consumeResource("Water", 50); // Consuming water
    manager.tradeResource("Gold", "Food", 100, 2); // Trading gold for food (2x ratio)
    manager.produceResources();  // Producing resources based on population
    manager.checkForLowResource("Food", 150);  // Check if food is running low

    // Decay certain resources over time
    manager.decayResource("BuildingMaterials", 10);
    manager.decayResource("Food", 5);

    // Population growth based on conditions
    manager.growPopulation();

    // Calculate resource efficiency
    manager.calculateEfficiency();

    // Display updated resources after actions
    manager.displayResources();

    return 0;
}

