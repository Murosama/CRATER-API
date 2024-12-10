#include "EnergyFlowSimulation.h"
#include <cmath>

PowerPlant::PowerPlant(const std::string& type, double capacity)
    : type(type), capacity(capacity), currentOutput(0) {}

void PowerPlant::producePower(double amount) {
    currentOutput += amount;
    if (currentOutput > capacity) {
        currentOutput = capacity;
    }
}

void PowerPlant::reducePower(double amount) {
    currentOutput -= amount;
    if (currentOutput < 0) {
        currentOutput = 0;
    }
}

double PowerPlant::getCurrentOutput() const {
    return currentOutput;
}

double PowerPlant::getCapacity() const {
    return capacity;
}

const std::string& PowerPlant::getType() const {
    return type;
}

TransmissionLine::TransmissionLine(double maxLoad, double lossRate)
    : maxLoad(maxLoad), currentLoad(0), lossRate(lossRate) {}

void TransmissionLine::transmitPower(double amount) {
    double effectiveAmount = amount * (1.0 - lossRate);
    currentLoad += effectiveAmount;
    if (currentLoad > maxLoad) {
        currentLoad = maxLoad;
    }
}

void TransmissionLine::reduceLoad(double amount) {
    currentLoad -= amount;
    if (currentLoad < 0) {
        currentLoad = 0;
    }
}

double TransmissionLine::getCurrentLoad() const {
    return currentLoad;
}

double TransmissionLine::getLossRate() const {
    return lossRate;
}

void EnergyGrid::addPowerPlant(const PowerPlant& plant) {
    powerPlants.push_back(plant);
}

void EnergyGrid::addTransmissionLine(const TransmissionLine& line) {
    transmissionLines.push_back(line);
}

void EnergyGrid::simulateStep(double deltaTime) {
    for (auto& line : transmissionLines) {
        for (auto& plant : powerPlants) {
            double availablePower = plant.getCurrentOutput() * deltaTime;
            line.transmitPower(availablePower);
            plant.reducePower(availablePower);
        }
    }
    balancePower();
}

void EnergyGrid::balancePower() {
    for (auto& line : transmissionLines) {
        if (line.getCurrentLoad() > line.getLossRate() * line.getCurrentLoad()) {
            double excessPower = line.getCurrentLoad() - line.getLossRate() * line.getCurrentLoad();
            for (auto& plant : powerPlants) {
                plant.producePower(excessPower);
            }
        }
    }
}

const std::vector<PowerPlant>& EnergyGrid::getPowerPlants() const {
    return powerPlants;
}

const std::vector<TransmissionLine>& EnergyGrid::getTransmissionLines() const {
    return transmissionLines;
}

void EnergyFlowSimulation::addEnergyGrid(const EnergyGrid& energyGrid) {
    grid = energyGrid;
}

void EnergyFlowSimulation::simulateStep(double deltaTime) {
    grid.simulateStep(deltaTime);
    manageOutages();
}

void EnergyFlowSimulation::manageOutages() {
    for (auto& line : grid.getTransmissionLines()) {
        if (line.getCurrentLoad() > line.getLossRate() * line.getCurrentLoad()) {
            line.reduceLoad(line.getLossRate() * line.getCurrentLoad());
        }
    }
}

const EnergyGrid& EnergyFlowSimulation::getEnergyGrid() const {
    return grid;
}
