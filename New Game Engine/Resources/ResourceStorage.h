#ifndef RESOURCE_STORAGE_H
#define RESOURCE_STORAGE_H

#include "Resource.h"
#include <mutex>

class ResourceStorage : public Resource {
public:
    ResourceStorage(double initialAmount, double capacity);
    void addResource(double amount);
    void removeResource(double amount);
    double getAvailableStorage() const;

private:
    double storageCapacity; // Maximum storage capacity for resources
    std::mutex mtx; // Mutex for thread-safe access
};

#endif // RESOURCE_STORAGE_H
