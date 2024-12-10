#pragma once

#include <vector>
#include <string>

class Disease {
private:
    std::string name;
    double infectionRate;
    double recoveryRate;
    double mortalityRate;

public:
    Disease(const std::string& name, double infectionRate, double recoveryRate, double mortalityRate);

    double getInfectionRate() const;
    double getRecoveryRate() const;
    double getMortalityRate() const;
    const std::string& getName() const;
};

class HealthcareFacility {
private:
    std::string type;
    double capacity;
    double currentLoad;
    double effectiveness;

public:
    HealthcareFacility(const std::string& type, double capacity, double effectiveness);

    void admitPatients(double number);
    void dischargePatients(double number);
    double getEffectiveness() const;
    double getAvailableCapacity() const;
    double getCurrentLoad() const;
    const std::string& getType() const;
};

class HealthSystem {
private:
    std::vector<Disease> diseases;
    std::vector<HealthcareFacility> facilities;

    void spreadDiseases(double deltaTime);
    void manageHealthcare(double deltaTime);

public:
    void addDisease(const Disease& disease);
    void addHealthcareFacility(const HealthcareFacility& facility);

    void simulateStep(double deltaTime);
    const std::vector<Disease>& getDiseases() const;
    const std::vector<HealthcareFacility>& getFacilities() const;
};

class HealthPhysicsSimulation {
private:
    HealthSystem healthSystem;

    void resolveOutbreaks(double deltaTime);

public:
    void addHealthSystem(const HealthSystem& system);
    void simulateStep(double deltaTime);
    const HealthSystem& getHealthSystem() const;
};
