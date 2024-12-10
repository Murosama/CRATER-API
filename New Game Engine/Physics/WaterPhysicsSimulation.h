#pragma once

#include <vector>

struct Vector3 {
    double x, y, z;
    Vector3(double x, double y, double z);
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(double scalar) const;
    double magnitude() const;
    Vector3 normalize() const;
};

struct WaterParticle {
    Vector3 position;
    Vector3 velocity;
    double pressure;
    double density;

    WaterParticle(Vector3 pos);
};

class WaterSimulation {
private:
    std::vector<WaterParticle> particles;
    double gravity;
    double timeStep;
    double restDensity;
    double viscosity;
    double particleMass;
    double smoothingRadius;

    double kernelPoly6(double r, double h);
    Vector3 kernelSpikyGradient(Vector3 r, double h);
    double kernelViscosityLaplacian(double r, double h);

    void computeDensityAndPressure();
    void computeForces();
    void integrate();

public:
    WaterSimulation(double gravity, double timeStep, double restDensity, double viscosity, double mass, double radius);

    void addParticle(const Vector3& position);
    void simulateStep();
    const std::vector<WaterParticle>& getParticles() const;
};
