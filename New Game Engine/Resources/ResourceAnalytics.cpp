#include "ResourceAnalytics.h"

void ResourceAnalytics::recordTrend(const std::string& resourceName, double amount) {
    resourceTrends[resourceName].push_back(amount);
}

std::vector<double> ResourceAnalytics::getTrends(const std::string& resourceName) const {
    auto it = resourceTrends.find(resourceName);
    return (it != resourceTrends.end()) ? it->second : std::vector<double>();
}