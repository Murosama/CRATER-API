#include "FuelResource.h"

UFuelResource::UFuelResource() {
    FuelEfficiency = 75; // Default fuel efficiency
    ResourceName = TEXT("Fuel");
    bIsRenewable = false; // Fuel resources are generally non-renewable
}

void UFuelResource::Collect(int32 Amount) {
    Super::Collect(Amount);
    // Additional logic for fuel collection
}

void UFuelResource::OnCollected(int32 Amount) {
    // Logic to handle fuel-specific behavior
    UE_LOG(LogTemp, Log, TEXT("%d units of fuel collected!"), Amount);
}
