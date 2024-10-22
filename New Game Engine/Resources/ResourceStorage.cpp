#include "ResourceStorage.h"

ResourceStorage::ResourceStorage(double initialAmount, double capacity) 
    : Resource(initialAmount), storageCapacity(capacity) {}

void ResourceStorage::addResource(double amount) {
    std::lock_guard<std::mutex> lock(mtx); // Ensure thread safety
    totalAmount += amount;
    if (totalAmount > storageCapacity) {
        totalAmount = storageCapacity; // Cap the amount to storage capacity
        // Optionally handle exceeding capacity
    }
}

void ResourceStorage::removeResource(double amount) {
    std::lock_guard<std::mutex> lock(mtx); // Ensure thread safety
    totalAmount -= amount;
    if (totalAmount < 0) totalAmount = 0; // Prevent negative resources
}

double ResourceStorage::getAvailableStorage() const {
    std::lock_guard<std::mutex> lock(mtx); // Ensure thread safety
    return storageCapacity - totalAmount;
}
