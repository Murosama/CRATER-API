#pragma once

#include <vector>
#include <string>

class PowerPlant {
private:
    std::string type;
    double capacity;
    double currentOutput;

public:
    PowerPlant(const std::string& type, double capacity);

    void producePower(double amount);
    void reducePower(double amount);
    double getCurrentOutput() const;
    double getCapacity() const;
    const std::string& getType() const;
};

class TransmissionLine {
private:
    double maxLoad;
    double currentLoad;
    double lossRate;

public:
    TransmissionLine(double maxLoad, double lossRate);

    void transmitPower(double amount);
    void reduceLoad(double amount);
    double getCurrentLoad() const;
    double getLossRate() const;
};

class EnergyGrid {
private:
    std::vector<PowerPlant> powerPlants;
    std::vector<TransmissionLine> transmissionLines;

    void balancePower();

public:
    void addPowerPlant(const PowerPlant& plant);
    void addTransmissionLine(const TransmissionLine& line);

    void simulateStep(double deltaTime);
    const std::vector<PowerPlant>& getPowerPlants() const;
    const std::vector<TransmissionLine>& getTransmissionLines() const;
};

class EnergyFlowSimulation {
private:
    EnergyGrid grid;

    void manageOutages();

public:
    void addEnergyGrid(const EnergyGrid& energyGrid);
    void simulateStep(double deltaTime);
    const EnergyGrid& getEnergyGrid() const;
};
