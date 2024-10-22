#include "Building.h"

ABuilding::ABuilding() {
    BuildingType = "Generic Building";
    ProductionRate = 1.0f;  // Default rate
    ProducedResource = "Wood";  // Default resource
}

void ABuilding::SetProductionDetails(FString ResourceName, float Rate) {
    ProducedResource = ResourceName;
    ProductionRate = Rate;
}

void ABuilding::ProduceResources(float DeltaTime) {
    float ProducedAmount = ProductionRate * DeltaTime;
    AddResource(ProducedResource, FMath::FloorToInt(ProducedAmount));
    UE_LOG(LogTemp, Warning, TEXT("%s produced %d units of %s"), *BuildingType, FMath::FloorToInt(ProducedAmount), *ProducedResource);
}

void ABuilding::UpdateEntity(float DeltaTime) {
    ProduceResources(DeltaTime);
}

void ABuilding::RenderEntity() {
    // Rendering logic here, for example, updating the visual model of the building
}