#pragma once

#include <vector>
#include <map>
#include <string>

class PollutionSource {
private:
    std::string type;
    double emissionRate;
    double spreadRadius;

public:
    PollutionSource(const std::string& type, double emissionRate, double spreadRadius);

    double getEmissionRate() const;
    double getSpreadRadius() const;
    const std::string& getType() const;
};

class SoilQuality {
private:
    double fertility;
    double pollutionLevel;

public:
    SoilQuality(double fertility, double pollutionLevel);

    void adjustFertility(double amount);
    void increasePollution(double amount);
    void decreasePollution(double amount);
    double getFertility() const;
    double getPollutionLevel() const;
};

class NaturalResource {
private:
    std::string name;
    double totalAmount;
    double currentUsage;

public:
    NaturalResource(const std::string& name, double totalAmount);

    void useResource(double amount);
    void replenishResource(double amount);
    double getAvailableAmount() const;
    const std::string& getName() const;
};

class EnvironmentalSystem {
private:
    std::vector<PollutionSource> pollutionSources;
    std::vector<SoilQuality> soilData;
    std::vector<NaturalResource> resources;

    void spreadPollution(double deltaTime);
    void renewResources(double deltaTime);

public:
    void addPollutionSource(const PollutionSource& source);
    void addSoilData(const SoilQuality& soil);
    void addResource(const NaturalResource& resource);

    void simulateStep(double deltaTime);
    const std::vector<PollutionSource>& getPollutionSources() const;
    const std::vector<SoilQuality>& getSoilData() const;
    const std::vector<NaturalResource>& getResources() const;
};
