#include "ResourceFlowSimulation.h"
#include <cmath>

ResourceNode::ResourceNode(const std::string& type, double capacity)
    : type(type), capacity(capacity), currentLoad(0) {}

void ResourceNode::addLoad(double amount) {
    currentLoad += amount;
}

void ResourceNode::removeLoad(double amount) {
    currentLoad -= amount;
    if (currentLoad < 0) {
        currentLoad = 0;
    }
}

bool ResourceNode::isOverloaded() const {
    return currentLoad > capacity;
}

double ResourceNode::getAvailableCapacity() const {
    return capacity - currentLoad;
}

ResourceFlow::ResourceFlow(ResourceNode* source, ResourceNode* destination, double flowRate)
    : source(source), destination(destination), flowRate(flowRate) {}

void ResourceFlow::simulateFlow(double deltaTime) {
    double amount = flowRate * deltaTime;
    if (source->getAvailableCapacity() >= amount && !destination->isOverloaded()) {
        source->removeLoad(amount);
        destination->addLoad(amount);
    }
}

double ResourceFlow::getFlowRate() const {
    return flowRate;
}

void ResourceNetwork::addNode(const ResourceNode& node) {
    nodes.push_back(node);
}

void ResourceNetwork::addFlow(const ResourceFlow& flow) {
    flows.push_back(flow);
}

void ResourceNetwork::simulateStep(double deltaTime) {
    for (auto& flow : flows) {
        flow.simulateFlow(deltaTime);
    }
    balanceFlows();
}

void ResourceNetwork::balanceFlows() {
    for (auto& node : nodes) {
        if (node.isOverloaded()) {
            for (auto& flow : flows) {
                if (flow.getFlowRate() > 0 && node.getAvailableCapacity() > 0) {
                    double adjustAmount = std::min(node.getAvailableCapacity(), flow.getFlowRate());
                    node.removeLoad(adjustAmount);
                }
            }
        }
    }
}

const std::vector<ResourceNode>& ResourceNetwork::getNodes() const {
    return nodes;
}

const std::vector<ResourceFlow>& ResourceNetwork::getFlows() const {
    return flows;
}

void ResourceFlowSimulation::addNetwork(const ResourceNetwork& resourceNetwork) {
    network = resourceNetwork;
}

void ResourceFlowSimulation::simulateStep(double deltaTime) {
    network.simulateStep(deltaTime);
    resolveOverloads();
    optimizeFlow();
}

void ResourceFlowSimulation::resolveOverloads() {
    for (auto& node : network.getNodes()) {
        if (node.isOverloaded()) {
            for (auto& flow : network.getFlows()) {
                double excessLoad = node.currentLoad - node.capacity;
                double adjustment = std::min(excessLoad, flow.getFlowRate());
                node.removeLoad(adjustment);
            }
        }
    }
}

void ResourceFlowSimulation::optimizeFlow() {
    for (auto& flow : network.getFlows()) {
        ResourceNode* source = flow.source;
        ResourceNode* destination = flow.destination;
        if (source->getAvailableCapacity() > destination->getAvailableCapacity()) {
            double adjustment = (source->getAvailableCapacity() - destination->getAvailableCapacity()) * 0.5;
            source->removeLoad(adjustment);
            destination->addLoad(adjustment);
        }
    }
}

const ResourceNetwork& ResourceFlowSimulation::getNetwork() const {
    return network;
}
