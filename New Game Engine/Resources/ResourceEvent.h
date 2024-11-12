#pragma once
#include <functional>
#include <string>

class ResourceEvent {
public:
    enum EventType { BOOST, DECAY, LOCKDOWN, PRICE_SURGE };  // Define different event types

    using Callback = std::function<void(double)>;
    
    ResourceEvent(const std::string& name, EventType type, Callback callback)
        : eventName(name), eventType(type), eventCallback(callback) {}

    void triggerEvent(double value) {
        eventCallback(value);  // Execute callback with provided value
    }

    std::string getName() const { return eventName; }
    EventType getType() const { return eventType; }

private:
    std::string eventName;
    EventType eventType;
    Callback eventCallback;
};
