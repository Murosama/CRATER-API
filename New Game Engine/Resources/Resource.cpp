#include "Resource.h"

Resource::Resource(double initialAmount, double scalingFactor)
    : totalAmount(initialAmount), scalingFactor(scalingFactor) {}

void Resource::produce(double amount) {
    totalAmount += amount * scalingFactor;
    updateAnalytics();
}

void Resource::deplete(double amount) {
    totalAmount -= amount * scalingFactor;
    if (totalAmount < 0) totalAmount = 0;
    updateAnalytics();
}

void Resource::updateAnalytics() {
    // Record production and depletion trends over time
    analyticsData.push_back(totalAmount);
}

void Resource::setScalingFactor(double newScalingFactor) {
    scalingFactor = newScalingFactor;
}

double Resource::getCurrentAmount() const {
    return totalAmount;
}

std::vector<double> Resource::getAnalytics() const {
    return analyticsData;
}
