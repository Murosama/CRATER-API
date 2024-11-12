#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>
#include <mutex>
#include <chrono>

class Resource {
public:
    Resource(double initialAmount, double baseProductionRate, double baseDepletionRate);

    // Core Methods
    void produce(double playerInfluenceFactor);
    void deplete(double externalFactor);

    // Analytics and Tracking
    void updateAnalytics();
    double getTrend() const;

    // Dynamic Scaling
    void setScalingFactor(double factor);

    // Getters
    double getAmount() const;
    std::string getName() const;


protected:
    std::string name;
    double amount;
    double baseProductionRate;
    double baseDepletionRate;
    double scalingFactor; // Attribute for dynamic scaling. It's important


private:
    std::vector<double> amountHistory; // For real-time analytics
    std::mutex resourceMutex;

};

#endif