#include "HealthPhysicsSimulation.h"
#include <cmath>

Disease::Disease(const std::string& name, double infectionRate, double recoveryRate, double mortalityRate)
    : name(name), infectionRate(infectionRate), recoveryRate(recoveryRate), mortalityRate(mortalityRate) {}

double Disease::getInfectionRate() const {
    return infectionRate;
}

double Disease::getRecoveryRate() const {
    return recoveryRate;
}

double Disease::getMortalityRate() const {
    return mortalityRate;
}

const std::string& Disease::getName() const {
    return name;
}

HealthcareFacility::HealthcareFacility(const std::string& type, double capacity, double effectiveness)
    : type(type), capacity(capacity), currentLoad(0), effectiveness(effectiveness) {}

void HealthcareFacility::admitPatients(double number) {
    currentLoad += number;
    if (currentLoad > capacity) {
        currentLoad = capacity;
    }
}

void HealthcareFacility::dischargePatients(double number) {
    currentLoad -= number;
    if (currentLoad < 0) {
        currentLoad = 0;
    }
}

double HealthcareFacility::getEffectiveness() const {
    return effectiveness;
}

double HealthcareFacility::getAvailableCapacity() const {
    return capacity - currentLoad;
}

double HealthcareFacility::getCurrentLoad() const {
    return currentLoad;
}

const std::string& HealthcareFacility::getType() const {
    return type;
}

void HealthSystem::addDisease(const Disease& disease) {
    diseases.push_back(disease);
}

void HealthSystem::addHealthcareFacility(const HealthcareFacility& facility) {
    facilities.push_back(facility);
}

void HealthSystem::simulateStep(double deltaTime) {
    spreadDiseases(deltaTime);
    manageHealthcare(deltaTime);
}

void HealthSystem::spreadDiseases(double deltaTime) {
    for (auto& disease : diseases) {
        double spreadFactor = disease.getInfectionRate() * deltaTime;
        for (auto& facility : facilities) {
            double patients = facility.getCurrentLoad() * spreadFactor;
            facility.admitPatients(patients);
        }
    }
}

void HealthSystem::manageHealthcare(double deltaTime) {
    for (auto& facility : facilities) {
        double recoveryRate = facility.getEffectiveness() * deltaTime;
        double dischargedPatients = recoveryRate * facility.getCurrentLoad();
        facility.dischargePatients(dischargedPatients);
    }
}

const std::vector<Disease>& HealthSystem::getDiseases() const {
    return diseases;
}

const std::vector<HealthcareFacility>& HealthSystem::getFacilities() const {
    return facilities;
}

void HealthPhysicsSimulation::addHealthSystem(const HealthSystem& system) {
    healthSystem = system;
}

void HealthPhysicsSimulation::simulateStep(double deltaTime) {
    healthSystem.simulateStep(deltaTime);
    resolveOutbreaks(deltaTime);
}

void HealthPhysicsSimulation::resolveOutbreaks(double deltaTime) {
    for (auto& disease : healthSystem.getDiseases()) {
        for (auto& facility : healthSystem.getFacilities()) {
            double mortality = disease.getMortalityRate() * deltaTime;
            double fatalities = facility.getCurrentLoad() * mortality;
            facility.dischargePatients(fatalities);
        }
    }
}

const HealthSystem& HealthPhysicsSimulation::getHealthSystem() const {
    return healthSystem;
}
