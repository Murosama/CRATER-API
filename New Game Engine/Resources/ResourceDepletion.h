#ifndef RESOURCE_DEPLETION_H
#define RESOURCE_DEPLETION_H

#include "Resource.h"
#include <chrono>

class ResourceDepletion : public Resource {
public:
    ResourceDepletion(double initialAmount, double depletionRate);
    void update(); // Update based on time passed
    double getCurrentAmount() const;

private:
    double depletionRate; // Rate at which the resource depletes per time unit
    std::chrono::steady_clock::time_point lastUpdate; // Track last update time
};

#endif // RESOURCE_DEPLETION_H
