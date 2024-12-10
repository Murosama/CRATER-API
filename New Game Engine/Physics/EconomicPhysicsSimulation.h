#pragma once

#include <map>
#include <string>

class EconomicEntity {
private:
    std::string name;
    double value;
    double growthRate;

public:
    EconomicEntity(const std::string& name, double value, double growthRate);

    void updateValue(double deltaTime);
    double getValue() const;
    const std::string& getName() const;
};

class Market {
private:
    std::map<std::string, EconomicEntity> entities;
    double inflationRate;

    void applyInflation(double deltaTime);

public:
    Market(double inflationRate);

    void addEntity(const EconomicEntity& entity);
    void simulateStep(double deltaTime);
    const std::map<std::string, EconomicEntity>& getEntities() const;
};

class EmploymentSystem {
private:
    double employmentRate;
    double unemploymentRate;
    double jobGrowthRate;

    void updateRates(double deltaTime);

public:
    EmploymentSystem(double employmentRate, double unemploymentRate, double jobGrowthRate);

    void simulateStep(double deltaTime);
    double getEmploymentRate() const;
    double getUnemploymentRate() const;
};

class EconomicSimulation {
private:
    Market market;
    EmploymentSystem employment;

    void resolveEconomicShocks(double deltaTime);

public:
    EconomicSimulation(double inflationRate, double employmentRate, double unemploymentRate, double jobGrowthRate);

    void simulateStep(double deltaTime);
    const Market& getMarket() const;
    const EmploymentSystem& getEmployment() const;
};