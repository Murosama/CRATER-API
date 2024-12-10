#include "StructuralPhysicsSimulation.h"
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

StructuralElement::StructuralElement(Vector3 pos, double strength, double maxLoad)
    : position(pos), strength(strength), currentLoad(0), maxLoad(maxLoad) {}

void StructuralElement::applyLoad(double load) {
    currentLoad += load;
}

void StructuralElement::removeLoad(double load) {
    currentLoad -= load;
    if (currentLoad < 0) {
        currentLoad = 0;
    }
}

bool StructuralElement::isOverloaded() const {
    return currentLoad > maxLoad;
}

double StructuralElement::getStress() const {
    return currentLoad / maxLoad;
}

Vector3 StructuralElement::getPosition() const {
    return position;
}

Structure::Structure() : integrity(1.0) {}

void Structure::addElement(const StructuralElement& element) {
    elements.push_back(element);
    calculateIntegrity();
}

void Structure::applyLoadToElement(size_t index, double load) {
    if (index < elements.size()) {
        elements[index].applyLoad(load);
        calculateIntegrity();
    }
}

void Structure::removeLoadFromElement(size_t index, double load) {
    if (index < elements.size()) {
        elements[index].removeLoad(load);
        calculateIntegrity();
    }
}

bool Structure::isCollapsed() const {
    return integrity <= 0;
}

double Structure::getIntegrity() const {
    return integrity;
}

const std::vector<StructuralElement>& Structure::getElements() const {
    return elements;
}

void Structure::calculateIntegrity() {
    double totalStress = 0;
    for (const auto& element : elements) {
        totalStress += element.getStress();
    }
    integrity = 1.0 - (totalStress / elements.size());
    if (integrity < 0) {
        integrity = 0;
    }
}

StructuralSimulation::StructuralSimulation(double environmentalFactor)
    : environmentalFactor(environmentalFactor) {}

void StructuralSimulation::addStructure(const Structure& structure) {
    structures.push_back(structure);
}

void StructuralSimulation::simulateStep() {
    applyEnvironmentalStress();
    resolveCollapses();
}

void StructuralSimulation::applyEnvironmentalStress() {
    for (auto& structure : structures) {
        for (size_t i = 0; i < structure.getElements().size(); ++i) {
            structure.applyLoadToElement(i, environmentalFactor);
        }
    }
}

void StructuralSimulation::resolveCollapses() {
    for (auto& structure : structures) {
        if (structure.isCollapsed()) {
            structure = Structure();
        }
    }
}

const std::vector<Structure>& StructuralSimulation::getStructures() const {
    return structures;
}