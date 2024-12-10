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

class WeatherEffect {
private:
    std::string type;
    double intensity;
    Vector3 direction;

public:
    WeatherEffect(const std::string& type, double intensity, const Vector3& direction);

    std::string getType() const;
    double getIntensity() const;
    Vector3 getDirection() const;
};

class WeatherSystem {
private:
    std::vector<WeatherEffect> activeEffects;
    double temperature;

    void updateRainEffect(double deltaTime);
    void updateWindEffect(double deltaTime);
    void updateSnowEffect(double deltaTime);

public:
    WeatherSystem(double initialTemperature);

    void addWeatherEffect(const WeatherEffect& effect);
    void updateWeather(double deltaTime);
    double getTemperature() const;
    const std::vector<WeatherEffect>& getActiveEffects() const;
};

class WeatherSimulation {
private:
    WeatherSystem weatherSystem;
    double globalTime;

    void simulateWeatherChanges(double deltaTime);

public:
    WeatherSimulation(double initialTemperature);

    void simulateStep(double deltaTime);
    WeatherSystem getWeatherSystem() const;
};