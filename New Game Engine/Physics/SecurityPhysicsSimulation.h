#pragma once

#include <vector>
#include <string>

class CrimeIncident {
private:
    std::string type;
    double severity;
    double probability;

public:
    CrimeIncident(const std::string& type, double severity, double probability);

    double getSeverity() const;
    double getProbability() const;
    const std::string& getType() const;
};

class EmergencyService {
private:
    std::string type;
    double responseTime;
    double effectiveness;

public:
    EmergencyService(const std::string& type, double responseTime, double effectiveness);

    double getResponseTime() const;
    double getEffectiveness() const;
    const std::string& getType() const;
};

class SecurityNetwork {
private:
    std::vector<CrimeIncident> incidents;
    std::vector<EmergencyService> services;

    void resolveCrimes(double deltaTime);
    void dispatchServices(double deltaTime);

public:
    void addCrimeIncident(const CrimeIncident& incident);
    void addEmergencyService(const EmergencyService& service);

    void simulateStep(double deltaTime);
    const std::vector<CrimeIncident>& getCrimeIncidents() const;
    const std::vector<EmergencyService>& getEmergencyServices() const;
};

class SecurityPhysicsSimulation {
private:
    SecurityNetwork network;

    void manageEmergencyImpact(double deltaTime);

public:
    void addNetwork(const SecurityNetwork& network);
    void simulateStep(double deltaTime);
    const SecurityNetwork& getNetwork() const;
};
