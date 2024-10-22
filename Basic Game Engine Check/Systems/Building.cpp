#include "Building.h"
#include "ResourceManager.h"

ABuilding::ABuilding() {
    // Default building type and production rate
    BuildingType = "Generic Building";
    ProductionRate = 0.0f;
}

void ABuilding::SetProductionDetails(FString NewResource, float NewRate) {
    ProducingResource = NewResource;
    ProductionRate = NewRate;
}

FString ABuilding::GetBuildingType() const {
    return BuildingType;
}

void ABuilding::ProduceResources(UResourceManager* ResourceManager) {
    if (ResourceManager) {
        ResourceManager->AddResource(ProducingResource, static_cast<int32>(ProductionRate));
    }
}

void ABuilding::UpdateEntity(float DeltaTime) {
    ProduceResources(/* ResourceManager reference here */);
}
