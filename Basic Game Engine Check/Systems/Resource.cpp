#include "Resource.h"

// Constructor for FResource
FResource::FResource() : Name(TEXT("Unknown")), Amount(0) {}

FResource::FResource(FString ResourceName, int32 InitialAmount)
    : Name(ResourceName), Amount(InitialAmount) {}

// Function to modify the amount of the resource
void FResource::ModifyAmount(int32 Change) {
    Amount = FMath::Max(0, Amount + Change);  // Ensure the amount doesn't go negative
}

// Function to get a string representation of the resource
FString FResource::ToString() const {
    return FString::Printf(TEXT("%s: %d"), *Name, Amount);
}
