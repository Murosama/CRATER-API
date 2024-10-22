#include "MaterialResource.h"

UMaterialResource::UMaterialResource() {
    Durability = 100; // Default durability
    ResourceName = TEXT("Material");
    bIsRenewable = false; // Materials are generally non-renewable
}

void UMaterialResource::Collect(int32 Amount) {
    Super::Collect(Amount);
    // Additional logic for material collection
}

void UMaterialResource::OnCollected(int32 Amount) {
    // Logic to handle material-specific behavior
    UE_LOG(LogTemp, Log, TEXT("%d units of material collected!"), Amount);
}
