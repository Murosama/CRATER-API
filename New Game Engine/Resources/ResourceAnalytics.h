#ifndef RESOURCE_ANALYTICS_H
#define RESOURCE_ANALYTICS_H

#include <map>
#include <vector>
#include <chrono>
#include <mutex>

class ResourceAnalytics {
public:
    ResourceAnalytics();
    void recordResourceData(const std::string& resourceName, double amount);
    std::vector<double> getResourceTrends(const std::string& resourceName, int timeframe) const;
    double getForecast(const std::string& resourceName) const;

private:
    std::map<std::string, std::vector<std::pair<std::chrono::time_point<std::chrono::steady_clock>, double>>> resourceData;
    mutable std::mutex dataMutex;

    double calculateTrend(const std::vector<double>& data) const;
    double predictFutureValue(const std::vector<double>& data) const;
};

#endif