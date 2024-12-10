#include "PopulationDynamicsSimulation.h"
#include <cmath>

Vector2::Vector2(double x, double y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(double scalar) const {
    return Vector2(x * scalar, y * scalar);
}

double Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalize() const {
    double mag = magnitude();
    return mag > 0 ? *this * (1.0 / mag) : Vector2(0, 0);
}

Citizen::Citizen(Vector2 startPos, Vector2 dest, double satisfaction)
    : position(startPos), destination(dest), velocity(0, 0), satisfaction(satisfaction) {}

void Citizen::updatePosition(double deltaTime) {
    Vector2 direction = destination - position;
    if (direction.magnitude() > 0.1) {
        velocity = direction.normalize() * 2.0;
        position = position + velocity * deltaTime;
    } else {
        velocity = Vector2(0, 0);
    }
}

void Citizen::setDestination(const Vector2& dest) {
    destination = dest;
}

Vector2 Citizen::getPosition() const {
    return position;
}

double Citizen::getSatisfaction() const {
    return satisfaction;
}

void Citizen::adjustSatisfaction(double amount) {
    satisfaction += amount;
    if (satisfaction < 0) satisfaction = 0;
    if (satisfaction > 100) satisfaction = 100;
}

PopulationGroup::PopulationGroup(double birthRate, double deathRate, double migrationRate)
    : birthRate(birthRate), deathRate(deathRate), migrationRate(migrationRate) {}

void PopulationGroup::addCitizen(const Citizen& citizen) {
    citizens.push_back(citizen);
}

void PopulationGroup::simulateStep(double deltaTime) {
    handleGrowth(deltaTime);
    for (auto& citizen : citizens) {
        citizen.updatePosition(deltaTime);
    }
}

void PopulationGroup::handleGrowth(double deltaTime) {
    size_t births = static_cast<size_t>(birthRate * citizens.size() * deltaTime);
    size_t deaths = static_cast<size_t>(deathRate * citizens.size() * deltaTime);
    size_t migrations = static_cast<size_t>(migrationRate * citizens.size() * deltaTime);

    for (size_t i = 0; i < births; ++i) {
        citizens.emplace_back(Vector2(rand() % 100, rand() % 100), Vector2(rand() % 100, rand() % 100), 50.0);
    }
    for (size_t i = 0; i < deaths && !citizens.empty(); ++i) {
        citizens.erase(citizens.begin() + rand() % citizens.size());
    }
    for (size_t i = 0; i < migrations && !citizens.empty(); ++i) {
        citizens.erase(citizens.begin() + rand() % citizens.size());
        citizens.emplace_back(Vector2(rand() % 100, rand() % 100), Vector2(rand() % 100, rand() % 100), 50.0);
    }
}

std::vector<Citizen>& PopulationGroup::getCitizens() {
    return citizens;
}

PopulationSimulation::PopulationSimulation() {}

void PopulationSimulation::addPopulationGroup(const PopulationGroup& group) {
    populationGroups.push_back(group);
}

void PopulationSimulation::simulateStep(double deltaTime) {
    for (auto& group : populationGroups) {
        group.simulateStep(deltaTime);
    }
    resolveCrowds(deltaTime);
    adjustResourceConsumption();
}

void PopulationSimulation::resolveCrowds(double deltaTime) {
    for (auto& group : populationGroups) {
        for (auto& citizen : group.getCitizens()) {
            citizen.adjustSatisfaction(-0.01 * deltaTime);
        }
    }
}

void PopulationSimulation::adjustResourceConsumption() {
    for (auto& group : populationGroups) {
        size_t totalPopulation = group.getCitizens().size();
        // Placeholder: Adjust city resources based on totalPopulation
    }
}

const std::vector<PopulationGroup>& PopulationSimulation::getPopulationGroups() const {
    return populationGroups;
}
