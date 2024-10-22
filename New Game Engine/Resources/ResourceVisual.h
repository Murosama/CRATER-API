#ifndef RESOURCE_VISUAL_H
#define RESOURCE_VISUAL_H

#include "Resource.h"
#include <string>

class ResourceVisual : public Resource {
public:
    ResourceVisual(double initialAmount);
    std::string getResourceStatus() const; // Retrieve resource status for UI integration
};

#endif // RESOURCE_VISUAL_H
