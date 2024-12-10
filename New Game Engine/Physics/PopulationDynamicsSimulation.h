#pragma once

#include <vector>
#include <string>

struct Vector2 {
    double x, y;
    Vector2(double x, double y);
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(double scalar) const;
    double magnitude() const;
    Vector2 normalize() const;
};

class Citizen {
private:
    Vector2 position;
    Vector2 destination;
    Vector2 velocity;
    double satisfaction;

public:
    Citizen(Vector2 startPos, Vector2 dest, double satisfaction);

    void updatePosition(double deltaTime);
    void setDestination(const Vector2& dest);
    Vector2 getPosition() const;
    double getSatisfaction() const;
    void adjustSatisfaction(double amount);
};

class PopulationGroup {
private:
    std::vector<Citizen> citizens;
    double birthRate;
    double deathRate;
    double migrationRate;

    void handleGrowth(double deltaTime);

public:
    PopulationGroup(double birthRate, double deathRate, double migrationRate);

    void addCitizen(const Citizen& citizen);
    void simulateStep(double deltaTime);
    std::vector<Citizen>& getCitizens();
};

class PopulationSimulation {
private:
    std::vector<PopulationGroup> populationGroups;

    void resolveCrowds(double deltaTime);
    void adjustResourceConsumption();

public:
    PopulationSimulation();

    void addPopulationGroup(const PopulationGroup& group);
    void simulateStep(double deltaTime);
    const std::vector<PopulationGroup>& getPopulationGroups() const;
};