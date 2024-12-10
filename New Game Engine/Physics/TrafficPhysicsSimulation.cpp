#include "TrafficPhysicsSimulation.h"
#include <cmath>

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

double Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize() const {
    double mag = magnitude();
    return mag > 0 ? *this * (1.0 / mag) : Vector3(0, 0, 0);
}

Vehicle::Vehicle(Vector3 startPos, double maxSpeed, double brakingForce, double length, double width)
    : position(startPos), velocity(0, 0, 0), acceleration(0, 0, 0), 
      maxSpeed(maxSpeed), brakingForce(brakingForce), length(length), width(width) {}

void Vehicle::update(double deltaTime) {
    velocity = velocity + acceleration * deltaTime;
    if (velocity.magnitude() > maxSpeed) {
        velocity = velocity.normalize() * maxSpeed;
    }
    position = position + velocity * deltaTime;
    acceleration = Vector3(0, 0, 0);
}

void Vehicle::applyAcceleration(Vector3 accel) {
    acceleration = acceleration + accel;
}

void Vehicle::applyBraking(double force) {
    double brakeMagnitude = std::min(force, velocity.magnitude());
    Vector3 brakeVector = velocity.normalize() * -brakeMagnitude;
    applyAcceleration(brakeVector);
}

Vector3 Vehicle::getPosition() const {
    return position;
}

Vector3 Vehicle::getVelocity() const {
    return velocity;
}

TrafficSimulation::TrafficSimulation(double timeStep) : timeStep(timeStep) {}

void TrafficSimulation::addVehicle(const Vehicle& vehicle) {
    vehicles.push_back(vehicle);
}

void TrafficSimulation::simulateStep() {
    handleCollisions();
    manageTrafficLights();
    resolveIntersections();

    for (auto& vehicle : vehicles) {
        vehicle.update(timeStep);
    }
}

void TrafficSimulation::handleCollisions() {
    for (size_t i = 0; i < vehicles.size(); ++i) {
        for (size_t j = i + 1; j < vehicles.size(); ++j) {
            Vector3 distance = vehicles[i].getPosition() - vehicles[j].getPosition();
            if (distance.magnitude() < vehicles[i].length) {
                vehicles[i].applyBraking(vehicles[i].velocity.magnitude());
                vehicles[j].applyBraking(vehicles[j].velocity.magnitude());
            }
        }
    }
}

void TrafficSimulation::manageTrafficLights() {
    for (size_t i = 0; i < vehicles.size(); ++i) {
        Vector3 pos = vehicles[i].getPosition();

        if (static_cast<int>(pos.x) % 50 == 0) {
            if (static_cast<int>(pos.x / 50) % 2 == 0) {
                vehicles[i].applyBraking(vehicles[i].velocity.magnitude());
            } else {
                vehicles[i].applyAcceleration(Vector3(1, 0, 0));
            }
        }
    }
}

void TrafficSimulation::resolveIntersections() {
    for (size_t i = 0; i < vehicles.size(); ++i) {
        for (size_t j = i + 1; j < vehicles.size(); ++j) {
            Vector3 pos1 = vehicles[i].getPosition();
            Vector3 pos2 = vehicles[j].getPosition();

            if (std::abs(pos1.x - pos2.x) < 5 && std::abs(pos1.y - pos2.y) < 5) {
                if (pos1.y < pos2.y) {
                    vehicles[j].applyBraking(vehicles[j].velocity.magnitude());
                } else {
                    vehicles[i].applyBraking(vehicles[i].velocity.magnitude());
                }
            }
        }
    }
}

const std::vector<Vehicle>& TrafficSimulation::getVehicles() const {
    return vehicles;
}