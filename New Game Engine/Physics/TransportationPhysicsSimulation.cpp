#include "TransportationPhysicsSimulation.h"
#include <cmath>

TransitVehicle::TransitVehicle(const std::string& type, double capacity, double speed, const std::vector<std::string>& route)
    : type(type), capacity(capacity), currentLoad(0), speed(speed), route(route), currentStopIndex(0) {}

void TransitVehicle::loadPassengers(double passengers) {
    currentLoad += passengers;
    if (currentLoad > capacity) {
        currentLoad = capacity;
    }
}

void TransitVehicle::unloadPassengers(double passengers) {
    currentLoad -= passengers;
    if (currentLoad < 0) {
        currentLoad = 0;
    }
}

void TransitVehicle::moveToNextStop() {
    currentStopIndex = (currentStopIndex + 1) % route.size();
}

double TransitVehicle::getCurrentLoad() const {
    return currentLoad;
}

double TransitVehicle::getCapacity() const {
    return capacity;
}

const std::string& TransitVehicle::getType() const {
    return type;
}

const std::string& TransitVehicle::getCurrentStop() const {
    return route[currentStopIndex];
}

void TransportationNetwork::addVehicle(const TransitVehicle& vehicle) {
    vehicles.push_back(vehicle);
}

void TransportationNetwork::updatePassengerFlow(const std::string& stop, size_t passengers) {
    passengerFlow[stop] += passengers;
}

void TransportationNetwork::simulateStep(double deltaTime) {
    distributePassengers(deltaTime);
    for (auto& vehicle : vehicles) {
        vehicle.moveToNextStop();
    }
    optimizeRoutes();
}

void TransportationNetwork::distributePassengers(double deltaTime) {
    for (auto& vehicle : vehicles) {
        const std::string& stop = vehicle.getCurrentStop();
        size_t passengersAtStop = passengerFlow[stop];

        double loadablePassengers = std::min(static_cast<double>(passengersAtStop), vehicle.getCapacity() - vehicle.getCurrentLoad());
        vehicle.loadPassengers(loadablePassengers);
        passengerFlow[stop] -= static_cast<size_t>(loadablePassengers);
    }
}

void TransportationNetwork::optimizeRoutes() {
    for (auto& vehicle : vehicles) {
        if (vehicle.getCurrentLoad() < vehicle.getCapacity() * 0.5) {
            vehicle.unloadPassengers(vehicle.getCurrentLoad() * 0.1);
        }
    }
}

const std::vector<TransitVehicle>& TransportationNetwork::getVehicles() const {
    return vehicles;
}

const std::map<std::string, size_t>& TransportationNetwork::getPassengerFlow() const {
    return passengerFlow;
}

void TransportationPhysicsSimulation::addNetwork(const TransportationNetwork& network) {
    this->network = network;
}

void TransportationPhysicsSimulation::simulateStep(double deltaTime) {
    network.simulateStep(deltaTime);
    resolveOvercrowding(deltaTime);
}

void TransportationPhysicsSimulation::resolveOvercrowding(double deltaTime) {
    for (auto& vehicle : network.getVehicles()) {
        if (vehicle.getCurrentLoad() > vehicle.getCapacity()) {
            double excessPassengers = vehicle.getCurrentLoad() - vehicle.getCapacity();
            vehicle.unloadPassengers(excessPassengers * deltaTime);
        }
    }
}

const TransportationNetwork& TransportationPhysicsSimulation::getNetwork() const {
    return network;
}
