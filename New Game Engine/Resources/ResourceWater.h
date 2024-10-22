#pragma once
#include "Resource.h"

class ResourceWater : public Resource {
public:
    ResourceWater(double initialAmount = 0.0);

    // Method to simulate water extraction from natural sources
    void extractWater(double amount);

    // Method to purify water for consumption
    void purifyWater(double amount);

    // Method to distribute water to citizens and buildings
    void distributeWater(double amount);

    // Get total water available, considering waste and purification losses
    double getAvailableWater() const override;

private:
    double contaminatedWater; // Water that needs purification
    double purifiedWater; // Clean, usable water
    double waterLossFactor; // Water loss due to inefficiency or evaporation    
};