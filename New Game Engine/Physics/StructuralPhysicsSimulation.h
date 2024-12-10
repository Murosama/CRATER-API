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

class StructuralElement {
private:
    Vector3 position;
    double strength;
    double currentLoad;
    double maxLoad;

public:
    StructuralElement(Vector3 pos, double strength, double maxLoad);

    void applyLoad(double load);
    void removeLoad(double load);
    bool isOverloaded() const;
    double getStress() const;
    Vector3 getPosition() const;
};

class Structure {
private:
    std::vector<StructuralElement> elements;
    double integrity;

    void calculateIntegrity();

public:
    Structure();

    void addElement(const StructuralElement& element);
    void applyLoadToElement(size_t index, double load);
    void removeLoadFromElement(size_t index, double load);
    bool isCollapsed() const;
    double getIntegrity() const;
    const std::vector<StructuralElement>& getElements() const;
};

class StructuralSimulation {
private:
    std::vector<Structure> structures;
    double environmentalFactor;

    void applyEnvironmentalStress();
    void resolveCollapses();

public:
    StructuralSimulation(double environmentalFactor);

    void addStructure(const Structure& structure);
    void simulateStep();
    const std::vector<Structure>& getStructures() const;
};