#pragma once

#include <vector>
#include <string>

class CulturalEvent {
private:
    std::string name;
    double popularity;
    double economicImpact;
    double trafficImpact;
    double happinessBoost;

public:
    CulturalEvent(const std::string& name, double popularity, double economicImpact, double trafficImpact, double happinessBoost);

    double getPopularity() const;
    double getEconomicImpact() const;
    double getTrafficImpact() const;
    double getHappinessBoost() const;
    const std::string& getName() const;
};

class CulturalInstitution {
private:
    std::string type;
    double culturalValue;
    double visitorCapacity;
    double currentVisitors;

public:
    CulturalInstitution(const std::string& type, double culturalValue, double visitorCapacity);

    void addVisitors(double visitors);
    void removeVisitors(double visitors);
    double getCulturalValue() const;
    double getCurrentVisitors() const;
    double getVisitorCapacity() const;
    const std::string& getType() const;
};

class CulturalNetwork {
private:
    std::vector<CulturalEvent> events;
    std::vector<CulturalInstitution> institutions;

    void simulateEvents(double deltaTime);
    void manageInstitutions(double deltaTime);

public:
    void addEvent(const CulturalEvent& event);
    void addInstitution(const CulturalInstitution& institution);

    void simulateStep(double deltaTime);
    const std::vector<CulturalEvent>& getEvents() const;
    const std::vector<CulturalInstitution>& getInstitutions() const;
};

class CulturalPhysicsSimulation {
private:
    CulturalNetwork network;

    void resolveEventImpact(double deltaTime);

public:
    void addNetwork(const CulturalNetwork& network);
    void simulateStep(double deltaTime);
    const CulturalNetwork& getNetwork() const;
};
