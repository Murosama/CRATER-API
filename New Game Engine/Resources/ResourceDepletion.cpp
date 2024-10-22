#include "ResourceDepletion.h"

ResourceDepletion::ResourceDepletion(double initialAmount, double rate) 
    : Resource(initialAmount), depletionRate(rate), lastUpdate(std::chrono::steady_clock::now()) {}

void ResourceDepletion::update() {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastUpdate;
    
    totalAmount -= elapsed.count() * depletionRate; // Deplete based on time elapsed
    if (totalAmount < 0) totalAmount = 0; // Prevent negative resources
    
    lastUpdate = now; // Reset last update time
}

double ResourceDepletion::getCurrentAmount() const {
    return totalAmount;
}
