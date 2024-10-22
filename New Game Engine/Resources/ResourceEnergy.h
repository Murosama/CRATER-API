#pragma
#include "Resource.h"

class ResourceEnergy : public Resource {
public:
    ResourceEnergy(double initialAmount = 0.0);

    // Method to add energy production from renewable resources
    void addRenewableEnergy(double amount);

    // Method to consume energy by various buildings
    void consumeEnergy(double amount);

    // Method to handle energy surplus and storage
    void storeSurplusEnergy(double amount);

    // Get total energy available, after considering losses
    double getAvailableEnergy() const override;

private:
    double renewableEnergy; // Amount of energy generated from renewable sources
    double energyStorage; // Storage for surplus energy
    double energyLossFactor; // Factor for energy loss (grid inefficiencies and etc.)      
};