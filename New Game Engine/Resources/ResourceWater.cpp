#include "ResourceWater.h"

ResourceWater::ResourceWater(double initialAmount)
    : Resource(initialAmount), contaminatedWater(0.0), purifiedWater(0.0),waterLossFactor(0.05) {}

void ResourceWater::extractWater(double amount) {
    totalAmount += amount; // Extracting raw water from natural sources
    contaminatedWater += amount * 0.3; // 30% of extracted water is contaminated    
}    

void ResourceWater::purifyWater(double amount) {
    if (contaminatedWater >= amount) {
        contaminatedWater -= amount;
        purifiedWater += amount; // Add to purified water pool
    }
}

void ResourceWater::distributeWater(double amount) {
    if (purifiedWater >= amount) {
        purifiedWater -= amount;
    } else {
        // Handling the water shortages
        purifiedWater = 0;
    }
}

double ResourceWater::getAvailableWater() const {
    return purifiedWater * (1.0 - waterLossFactor); // Including water loss during distribution
}