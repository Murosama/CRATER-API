#pragma once
#include <functional>
#include <string>

class ResourceEvent {
public:
    using Callback = std::function<void(double)>;  // Event callback takes a numeric value (e.g., production boost)

    ResourceEvent(const std::string& name, Callback callback)
        : eventName(name), eventCallback(callback) {}

    void triggerEvent(double value) {
        eventCallback(value);  // Execute callback with provided value
    }

    std::string getName() const { return eventName; }

private:
    std::string eventName;
    Callback eventCallback;
};