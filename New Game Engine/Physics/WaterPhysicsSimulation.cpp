#include "WaterPhysicsSimulation.h"
#include <cmath>
#include <vector>

struct Vector3 {
    double x, y, z;
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector3 operator+(const Vector3& other) const { return Vector3(x + other.x, y + other.y, z + other.z); }
    Vector3 operator-(const Vector3& other) const { return Vector3(x - other.x, y - other.y, z - other.z); }
    Vector3 operator*(double scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }
    double magnitude() const { return std::sqrt(x * x + y * y + z * z); }
    Vector3 normalize() const {
        double mag = magnitude();
        return mag > 0 ? *this * (1.0 / mag) : Vector3(0, 0, 0);
    }
};

struct WaterParticle {
    Vector3 position;
    Vector3 velocity;
    double pressure;
    double density;

    WaterParticle(Vector3 pos) : position(pos), velocity(0, 0, 0), pressure(0), density(0) {}
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

    double kernelPoly6(double r, double h) {
        if (r >= 0 && r <= h) {
            double hr = (h * h - r * r);
            return 315.0 / (64.0 * M_PI * std::pow(h, 9)) * hr * hr * hr;
        }
        return 0;
    }

    Vector3 kernelSpikyGradient(Vector3 r, double h) {
        double rMag = r.magnitude();
        if (rMag > 0 && rMag <= h) {
            double coeff = -45.0 / (M_PI * std::pow(h, 6)) * std::pow(h - rMag, 2);
            return r.normalize() * coeff;
        }
        return Vector3(0, 0, 0);
    }

    double kernelViscosityLaplacian(double r, double h) {
        if (r >= 0 && r <= h) {
            return 45.0 / (M_PI * std::pow(h, 6)) * (h - r);
        }
        return 0;
    }

    void computeDensityAndPressure() {
        for (auto& p : particles) {
            p.density = 0;
            for (const auto& neighbor : particles) {
                double r = (p.position - neighbor.position).magnitude();
                p.density += particleMass * kernelPoly6(r, smoothingRadius);
            }
            p.pressure = std::max(0.0, restDensity * (p.density - restDensity));
        }
    }

    void computeForces() {
        for (auto& p : particles) {
            Vector3 pressureForce(0, 0, 0);
            Vector3 viscosityForce(0, 0, 0);

            for (const auto& neighbor : particles) {
                Vector3 r = p.position - neighbor.position;
                double rMag = r.magnitude();

                if (rMag > 0 && rMag <= smoothingRadius) {
                    pressureForce = pressureForce - kernelSpikyGradient(r, smoothingRadius) * 
                                    (p.pressure + neighbor.pressure) / (2 * neighbor.density);
                    viscosityForce = viscosityForce + (neighbor.velocity - p.velocity) * 
                                     kernelViscosityLaplacian(rMag, smoothingRadius) / neighbor.density;
                }
            }

            Vector3 gravityForce = Vector3(0, -gravity, 0) * p.density;
            p.velocity = p.velocity + (pressureForce + viscosityForce + gravityForce) * (timeStep / p.density);
        }
    }

    void integrate() {
        for (auto& p : particles) {
            p.position = p.position + p.velocity * timeStep;
        }
    }

public:
    WaterSimulation(double gravity, double timeStep, double restDensity, double viscosity, double mass, double radius)
        : gravity(gravity), timeStep(timeStep), restDensity(restDensity), viscosity(viscosity), 
          particleMass(mass), smoothingRadius(radius) {}

    void addParticle(const Vector3& position) {
        particles.emplace_back(position);
    }

    void simulateStep() {
        computeDensityAndPressure();
        computeForces();
        integrate();
    }

    const std::vector<WaterParticle>& getParticles() const {
        return particles;
    }
};
