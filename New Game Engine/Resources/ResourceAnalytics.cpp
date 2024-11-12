#include "ResourceAnalytics.h"
#include <algorithm>
#include <numeric>
#include <cmath>

ResourceAnalytics::ResourceAnalytics() {}

void ResourceAnalytics::recordResourceData(const std::string& resourceName, double amount) {
    std::lock_guard<std::mutex> lock(dataMutex);
    auto now = std::chrono::steady_clock::now();
    resourceData[resourceName].emplace_back(now, amount);

    // Optional: Limit historical data size for efficiency
    if (resourceData[resourceName].size() > 100) {
        resourceData[resourceName].erase(resourceData[resourceName].begin());
    }
}

std::vector<double> ResourceAnalytics::getResourceTrends(const std::string& resourceName, int timeframe) const {
    std::lock_guard<std::mutex> lock(dataMutex);
    auto& data = resourceData.at(resourceName);
    auto cutoff = std::chrono::steady_clock::now() - std::chrono::minutes(timeframe);

    std::vector<double> trendData;
    for (const auto& [time, amount] : data) {
        if (time > cutoff) {
            trendData.push_back(amount);
        }
    }
    return trendData;
}

double ResourceAnalytics::calculateTrend(const std::vector<double>& data) const {
    if (data.empty()) return 0.0;
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double ResourceAnalytics::getForecast(const std::string& resourceName) const {
    auto trends = getResourceTrends(resourceName, 10);  // e.g., last 10 minutes
    return predictFutureValue(trends);
}

double ResourceAnalytics::predictFutureValue(const std::vector<double>& data) const {
    if (data.size() < 2) return data.empty() ? 0.0 : data.back();
    double trend = calculateTrend(data);
    return data.back() + trend;
}
