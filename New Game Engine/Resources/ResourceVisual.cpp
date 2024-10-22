#include "ResourceVisual.h"

ResourceVisual::ResourceVisual(double initialAmount) 
    : Resource(initialAmount) {}

std::string ResourceVisual::getResourceStatus() const {
    return "Current Amount: " + std::to_string(totalAmount); // Return formatted status string
}
