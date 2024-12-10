#pragma once

#include <vector>
#include <string>

class TransitVehicle {
private:
    std::string type;
    double capacity;
    double currentLoad;
    double speed;
    std::vector<std::string> route;
    size_t currentStopIndex;

public:
    TransitVehicle(const std::string& type, double capacity, double speed, const std::vector<std::string>& route);

    void loadPassengers(double passengers);
    void unloadPassengers(double passengers);
    void moveToNextStop();
    double getCurrentLoad() const;
    double getCapacity() const;
    const std::string& getType() const;
    const std::string& getCurrentStop() const;
};

class TransportationNetwork {
private:
    std::vector<TransitVehicle> vehicles;
    std::map<std::string, size_t> passengerFlow;

    void optimizeRoutes();
    void distributePassengers(double deltaTime);

public:
    void addVehicle(const TransitVehicle& vehicle);
    void updatePassengerFlow(const std::string& stop, size_t passengers);

    void simulateStep(double deltaTime);
    const std::vector<TransitVehicle>& getVehicles() const;
    const std::map<std::string, size_t>& getPassengerFlow() const;
};

class TransportationPhysicsSimulation {
private:
    TransportationNetwork network;

    void resolveOvercrowding(double deltaTime);

public:
    void addNetwork(const TransportationNetwork& network);
    void simulateStep(double deltaTime);
    const TransportationNetwork& getNetwork() const;
};
