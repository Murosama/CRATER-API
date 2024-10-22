#include "WaterResource.h"

UWaterResource::UWaterResource() {
    PurityLevel = 100; // Default purity level
    ResourceName = TEXT("Water");
    bIsRenewable = true; // Water resources can be renewable
}

void UWaterResource::Collect(int32 Amount) {
    Super::Collect(Amount);
    // Additional logic for water collection
}

void UWaterResource::OnCollected(int32 Amount) {
    // Logic to handle water-specific behavior
    UE_LOG(LogTemp, Log, TEXT("%d units of water collected!"), Amount);
}
