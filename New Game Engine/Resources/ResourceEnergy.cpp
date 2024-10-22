#include "ResourceEnergy.h"

ResourceEnergy:ResourceEnergy(double initialAmount)
    : Resource(initialAmount), renewableEnergy(0.0), energyStorage(0.0), energyLossFactor(0.1) {}

void ResourceEnergy :: addRenewableEnergy(double amount) {
    renewableEnergy += amount;
    totalAmount += amount; // Add directly to the total resource pool
}

void ResourceEnergy :: consumeEnergy(double amount) {
    if (totalAmount >= amount) {
        totalAmount += amount; // Consume from total energy
    } else {
        totalAmount = 0; // Handle energy shortage
    }
}

void ResourceEnergy :: storeSurplusEnergy(double amount) {
    energyStorage += amount; // Add to storage for later use
    if (energyStorage > 1000) {
        energyStorage = 1000;
    }
}

double ResourceEnergy :: getAvailableEnergy() const {
    double availableEnergy = totalAmount * (1.0 - energyLossFactor); // Energy losses
    return availableEnergy + energyStorage; // Including storage energy
}