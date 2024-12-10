#pragma once

#include <vector>
#include <string>

struct Vector3 {
    double x, y, z;
    Vector3(double x, double y, double z);
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(double scalar) const;
    double magnitude() const;
    Vector3 normalize() const;
};

class Vehicle {
private:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    double maxSpeed;
    double brakingForce;
    double length;
    double width;

public:
    Vehicle(Vector3 startPos, double maxSpeed, double brakingForce, double length, double width);

    void update(double deltaTime);
    void applyAcceleration(Vector3 accel);
    void applyBraking(double force);
    Vector3 getPosition() const;
    Vector3 getVelocity() const;
};

class TrafficSimulation {
private:
    std::vector<Vehicle> vehicles;
    double timeStep;

    void handleCollisions();
    void manageTrafficLights();
    void resolveIntersections();

public:
    TrafficSimulation(double timeStep);

    void addVehicle(const Vehicle& vehicle);
    void simulateStep();
    const std::vector<Vehicle>& getVehicles() const;
};
