#pragma once
#include <map>
#include <string>
#include <vector>

class ResourceAnalytics {
public:
    void recordTrend(const std::string& resourceName, double amount);
    std::vector<double> getTrends(const std::string& resourceName) const;

private:
    std::map<std::string, std::vector<double>> resourceTrends;  // Trend data by resource name
};