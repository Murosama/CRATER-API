#ifndef RESOURCE_EVENT_H
#define RESOURCE_EVENT_H

#include <functional>
#include <vector>

class ResourceEvent {
public:
    void subscribe(const std::function<void()>& callback);
    void notify(); // Notify all subscribers about an event

private:
    std::vector<std::function<void()>> listeners; // List of event listeners
};

#endif // RESOURCE_EVENT_H
