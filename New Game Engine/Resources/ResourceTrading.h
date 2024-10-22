#ifndef RESOURCETRADING_H
#define RESOURCETRADING_H

#include <string>
#include <map>

class ResourceTrading {
public:
    ResourceTrading();
    void tradeResources(const std::string& resourceType, double amount, const std::string& targetResource);
    void generateRandomEvent();
    double getResourceAmount(const std::string& resourceType) const;
    void addResource(const std::string& resourceType, double amount);
    
private:
    std::map<std::string, double> resources;
    void handleTrade(const std::string& resourceType, double amount, const std::string& targetResource);
};

#endif // RESOURCETRADING_H
