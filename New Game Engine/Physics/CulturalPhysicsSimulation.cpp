#include "CulturalPhysicsSimulation.h"
#include <cmath>

CulturalEvent::CulturalEvent(const std::string& name, double popularity, double economicImpact, double trafficImpact, double happinessBoost)
    : name(name), popularity(popularity), economicImpact(economicImpact), trafficImpact(trafficImpact), happinessBoost(happinessBoost) {}

double CulturalEvent::getPopularity() const {
    return popularity;
}

double CulturalEvent::getEconomicImpact() const {
    return economicImpact;
}

double CulturalEvent::getTrafficImpact() const {
    return trafficImpact;
}

double CulturalEvent::getHappinessBoost() const {
    return happinessBoost;
}

const std::string& CulturalEvent::getName() const {
    return name;
}

CulturalInstitution::CulturalInstitution(const std::string& type, double culturalValue, double visitorCapacity)
    : type(type), culturalValue(culturalValue), visitorCapacity(visitorCapacity), currentVisitors(0) {}

void CulturalInstitution::addVisitors(double visitors) {
    currentVisitors += visitors;
    if (currentVisitors > visitorCapacity) {
        currentVisitors = visitorCapacity;
    }
}

void CulturalInstitution::removeVisitors(double visitors) {
    currentVisitors -= visitors;
    if (currentVisitors < 0) {
        currentVisitors = 0;
    }
}

double CulturalInstitution::getCulturalValue() const {
    return culturalValue;
}

double CulturalInstitution::getCurrentVisitors() const {
    return currentVisitors;
}

double CulturalInstitution::getVisitorCapacity() const {
    return visitorCapacity;
}

const std::string& CulturalInstitution::getType() const {
    return type;
}

void CulturalNetwork::addEvent(const CulturalEvent& event) {
    events.push_back(event);
}

void CulturalNetwork::addInstitution(const CulturalInstitution& institution) {
    institutions.push_back(institution);
}

void CulturalNetwork::simulateStep(double deltaTime) {
    simulateEvents(deltaTime);
    manageInstitutions(deltaTime);
}

void CulturalNetwork::simulateEvents(double deltaTime) {
    for (const auto& event : events) {
        double visitorIncrease = event.getPopularity() * deltaTime * 10;
        for (auto& institution : institutions) {
            institution.addVisitors(visitorIncrease * (institution.getCulturalValue() / 100));
        }
    }
}

void CulturalNetwork::manageInstitutions(double deltaTime) {
    for (auto& institution : institutions) {
        double decay = institution.getCurrentVisitors() * 0.05 * deltaTime;
        institution.removeVisitors(decay);
    }
}

const std::vector<CulturalEvent>& CulturalNetwork::getEvents() const {
    return events;
}

const std::vector<CulturalInstitution>& CulturalNetwork::getInstitutions() const {
    return institutions;
}

void CulturalPhysicsSimulation::addNetwork(const CulturalNetwork& network) {
    this->network = network;
}

void CulturalPhysicsSimulation::simulateStep(double deltaTime) {
    network.simulateStep(deltaTime);
    resolveEventImpact(deltaTime);
}

void CulturalPhysicsSimulation::resolveEventImpact(double deltaTime) {
    for (const auto& event : network.getEvents()) {
        double trafficImpact = event.getTrafficImpact() * deltaTime;
        double economicBoost = event.getEconomicImpact() * deltaTime;
        double happinessIncrease = event.getHappinessBoost() * deltaTime;

        for (auto& institution : network.getInstitutions()) {
            institution.addVisitors(happinessIncrease * 10);
        }

        double totalEconomicBoost = economicBoost * network.getInstitutions().size();
        double totalTrafficImpact = trafficImpact * network.getInstitutions().size();

        for (auto& institution : network.getInstitutions()) {
            institution.addVisitors(happinessIncrease * 10);
        }

        
        double cityWideEconomicImpact = totalEconomicBoost;
        double cityWideTrafficIncrease = totalTrafficImpact;
        double cityWideHappiness = happinessIncrease * network.getInstitutions().size();

        
    }
}

const CulturalNetwork& CulturalPhysicsSimulation::getNetwork() const {
    return network;
}
