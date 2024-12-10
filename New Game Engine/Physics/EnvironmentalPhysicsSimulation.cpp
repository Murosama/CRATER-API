#include "EnvironmentalPhysicsSimulation.h"
#include <cmath>

PollutionSource::PollutionSource(const std::string& type, double emissionRate, double spreadRadius)
    : type(type), emissionRate(emissionRate), spreadRadius(spreadRadius) {}

double PollutionSource::getEmissionRate() const {
    return emissionRate;
}

double PollutionSource::getSpreadRadius() const {
    return spreadRadius;
}

const std::string& PollutionSource::getType() const {
    return type;
}

SoilQuality::SoilQuality(double fertility, double pollutionLevel)
    : fertility(fertility), pollutionLevel(pollutionLevel) {}

void SoilQuality::adjustFertility(double amount) {
    fertility += amount;
    if (fertility < 0) fertility = 0;
    if (fertility > 100) fertility = 100;
}

void SoilQuality::increasePollution(double amount) {
    pollutionLevel += amount;
    if (pollutionLevel > 100) pollutionLevel = 100;
}

void SoilQuality::decreasePollution(double amount) {
    pollutionLevel -= amount;
    if (pollutionLevel < 0) pollutionLevel = 0;
}

double SoilQuality::getFertility() const {
    return fertility;
}

double SoilQuality::getPollutionLevel() const {
    return pollutionLevel;
}

NaturalResource::NaturalResource(const std::string& name, double totalAmount)
    : name(name), totalAmount(totalAmount), currentUsage(0) {}

void NaturalResource::useResource(double amount) {
    currentUsage += amount;
    if (currentUsage > totalAmount) currentUsage = totalAmount;
}

void NaturalResource::replenishResource(double amount) {
    currentUsage -= amount;
    if (currentUsage < 0) currentUsage = 0;
}

double NaturalResource::getAvailableAmount() const {
    return totalAmount - currentUsage;
}

const std::string& NaturalResource::getName() const {
    return name;
}

void EnvironmentalSystem::addPollutionSource(const PollutionSource& source) {
    pollutionSources.push_back(source);
}

void EnvironmentalSystem::addSoilData(const SoilQuality& soil) {
    soilData.push_back(soil);
}

void EnvironmentalSystem::addResource(const NaturalResource& resource) {
    resources.push_back(resource);
}

void EnvironmentalSystem::simulateStep(double deltaTime) {
    spreadPollution(deltaTime);
    renewResources(deltaTime);
}

void EnvironmentalSystem::spreadPollution(double deltaTime) {
    for (const auto& source : pollutionSources) {
        double spreadImpact = source.getEmissionRate() * deltaTime;
        for (auto& soil : soilData) {
            soil.increasePollution(spreadImpact / soilData.size());
            soil.adjustFertility(-spreadImpact * 0.1);
        }
    }
}

void EnvironmentalSystem::renewResources(double deltaTime) {
    for (auto& resource : resources) {
        double renewAmount = resource.getAvailableAmount() * 0.05 * deltaTime;
        resource.replenishResource(renewAmount);
    }
}

const std::vector<PollutionSource>& EnvironmentalSystem::getPollutionSources() const {
    return pollutionSources;
}

const std::vector<SoilQuality>& EnvironmentalSystem::getSoilData() const {
    return soilData;
}

const std::vector<NaturalResource>& EnvironmentalSystem::getResources() const {
    return resources;
}
