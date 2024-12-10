#pragma once

#include <vector>
#include <map>
#include <string>

struct ResourceNode {
    std::string type;
    double capacity;
    double currentLoad;

    ResourceNode(const std::string& type, double capacity);
    void addLoad(double amount);
    void removeLoad(double amount);
    bool isOverloaded() const;
    double getAvailableCapacity() const;
};

class ResourceFlow {
private:
    ResourceNode* source;
    ResourceNode* destination;
    double flowRate;

public:
    ResourceFlow(ResourceNode* source, ResourceNode* destination, double flowRate);

    void simulateFlow(double deltaTime);
    double getFlowRate() const;
};

class ResourceNetwork {
private:
    std::vector<ResourceNode> nodes;
    std::vector<ResourceFlow> flows;

    void balanceFlows();

public:
    void addNode(const ResourceNode& node);
    void addFlow(const ResourceFlow& flow);
    void simulateStep(double deltaTime);
    const std::vector<ResourceNode>& getNodes() const;
    const std::vector<ResourceFlow>& getFlows() const;
};

class ResourceFlowSimulation {
private:
    ResourceNetwork network;

    void resolveOverloads();
    void optimizeFlow();

public:
    void addNetwork(const ResourceNetwork& resourceNetwork);
    void simulateStep(double deltaTime);
    const ResourceNetwork& getNetwork() const;
};
