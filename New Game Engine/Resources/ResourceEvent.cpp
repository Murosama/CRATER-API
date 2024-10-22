#include "ResourceEvent.h"

void ResourceEvent::subscribe(const std::function<void()>& callback) {
    listeners.push_back(callback);
}

void ResourceEvent::notify() {
    for (const auto& listener : listeners) {
        listener();
    }
}

