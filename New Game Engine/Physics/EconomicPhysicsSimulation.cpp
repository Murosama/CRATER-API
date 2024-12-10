#include "EconomicPhysicsSimulation.h"
#include <cmath>

EconomicEntity::EconomicEntity(const std::string& name, double value, double growthRate)
    : name(name), value(value), growthRate(growthRate) {}

void EconomicEntity::updateValue(double deltaTime) {
    value += value * growthRate * deltaTime;
}

double EconomicEntity::getValue() const {
    return value;
}

const std::string& EconomicEntity::getName() const {
    return name;
}

Market::Market(double inflationRate) : inflationRate(inflationRate) {}

void Market::addEntity(const EconomicEntity& entity) {
    entities[entity.getName()] = entity;
}

void Market::simulateStep(double deltaTime) {
    applyInflation(deltaTime);
    for (auto& [name, entity] : entities) {
        entity.updateValue(deltaTime);
    }
}

void Market::applyInflation(double deltaTime) {
    for (auto& [name, entity] : entities) {
        double inflationEffect = entity.getValue() * inflationRate * deltaTime;
        entity.updateValue(inflationEffect);
    }
}

const std::map<std::string, EconomicEntity>& Market::getEntities() const {
    return entities;
}

EmploymentSystem::EmploymentSystem(double employmentRate, double unemploymentRate, double jobGrowthRate)
    : employmentRate(employmentRate), unemploymentRate(unemploymentRate), jobGrowthRate(jobGrowthRate) {}

void EmploymentSystem::simulateStep(double deltaTime) {
    updateRates(deltaTime);
}

void EmploymentSystem::updateRates(double deltaTime) {
    double delta = jobGrowthRate * deltaTime;
    employmentRate += delta;
    unemploymentRate -= delta;
    if (employmentRate > 100.0) employmentRate = 100.0;
    if (unemploymentRate < 0.0) unemploymentRate = 0.0;
}

double EmploymentSystem::getEmploymentRate() const {
    return employmentRate;
}

double EmploymentSystem::getUnemploymentRate() const {
    return unemploymentRate;
}

EconomicSimulation::EconomicSimulation(double inflationRate, double employmentRate, double unemploymentRate, double jobGrowthRate)
    : market(inflationRate), employment(employmentRate, unemploymentRate, jobGrowthRate) {}

void EconomicSimulation::simulateStep(double deltaTime) {
    market.simulateStep(deltaTime);
    employment.simulateStep(deltaTime);
    resolveEconomicShocks(deltaTime);
}

void EconomicSimulation::resolveEconomicShocks(double deltaTime) {
    for (const auto& [name, entity] : market.getEntities()) {
        if (entity.getValue() < 0.5) {
            double adjustment = unemploymentRate * 0.1 * deltaTime;
            employment.simulateStep(-adjustment);
        }
    }
}

const Market& EconomicSimulation::getMarket() const {
    return market;
}

const EmploymentSystem& EconomicSimulation::getEmployment() const {
    return employment;
}
