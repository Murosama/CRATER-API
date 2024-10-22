#include "EnergyResource.h"

UEnergyResource::UEnergyResource() {
    EnergyOutput = 50; // Default energy output
    ResourceName = TEXT("Energy");
    bIsRenewable = true; // Energy resources can often be renewable
}

void UEnergyResource::Collect(int32 Amount) {
    Super::Collect(Amount);
    // Additional logic for energy collection
}

void UEnergyResource::OnCollected(int32 Amount) {
    // Logic to handle energy-specific behavior
    UE_LOG(LogTemp, Log, TEXT("%d units of energy collected!"), Amount);
}
