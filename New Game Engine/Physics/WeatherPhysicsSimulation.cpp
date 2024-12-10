#include "WeatherPhysicsSimulation.h"
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

WeatherEffect::WeatherEffect(const std::string& type, double intensity, const Vector3& direction)
    : type(type), intensity(intensity), direction(direction) {}

std::string WeatherEffect::getType() const {
    return type;
}

double WeatherEffect::getIntensity() const {
    return intensity;
}

Vector3 WeatherEffect::getDirection() const {
    return direction;
}

WeatherSystem::WeatherSystem(double initialTemperature)
    : temperature(initialTemperature) {}

void WeatherSystem::addWeatherEffect(const WeatherEffect& effect) {
    activeEffects.push_back(effect);
}

void WeatherSystem::updateRainEffect(double deltaTime) {
    for (auto& effect : activeEffects) {
        if (effect.getType() == "rain") {
            temperature -= effect.getIntensity() * 0.01 * deltaTime;
        }
    }
}

void WeatherSystem::updateWindEffect(double deltaTime) {
    for (auto& effect : activeEffects) {
        if (effect.getType() == "wind") {
            temperature -= effect.getIntensity() * 0.005 * deltaTime;
        }
    }
}

void WeatherSystem::updateSnowEffect(double deltaTime) {
    for (auto& effect : activeEffects) {
        if (effect.getType() == "snow") {
            temperature -= effect.getIntensity() * 0.02 * deltaTime;
        }
    }
}

void WeatherSystem::updateWeather(double deltaTime) {
    updateRainEffect(deltaTime);
    updateWindEffect(deltaTime);
    updateSnowEffect(deltaTime);
}

double WeatherSystem::getTemperature() const {
    return temperature;
}

const std::vector<WeatherEffect>& WeatherSystem::getActiveEffects() const {
    return activeEffects;
}

WeatherSimulation::WeatherSimulation(double initialTemperature)
    : weatherSystem(initialTemperature), globalTime(0) {}

void WeatherSimulation::simulateWeatherChanges(double deltaTime) {
    globalTime += deltaTime;
    if (static_cast<int>(globalTime) % 100 == 0) {
        weatherSystem.addWeatherEffect(WeatherEffect("rain", 10.0, Vector3(0, -1, 0)));
    }
    if (static_cast<int>(globalTime) % 200 == 0) {
        weatherSystem.addWeatherEffect(WeatherEffect("wind", 5.0, Vector3(1, 0, 0)));
    }
    if (static_cast<int>(globalTime) % 300 == 0) {
        weatherSystem.addWeatherEffect(WeatherEffect("snow", 15.0, Vector3(0, -1, 0)));
    }
}

void WeatherSimulation::simulateStep(double deltaTime) {
    simulateWeatherChanges(deltaTime);
    weatherSystem.updateWeather(deltaTime);
}

WeatherSystem WeatherSimulation::getWeatherSystem() const {
    return weatherSystem;
}
