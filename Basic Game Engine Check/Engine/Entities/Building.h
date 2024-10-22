#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "Building.generated.h"

UCLASS()
class CITYBUILDER_API ABuilding : public AEntity {
    GENERATED_BODY()

private:
    FString BuildingType;
    float ProductionRate;  // How fast the building produces resources (per second)
    FString ProducedResource;  // What resource this building produces

public:
    ABuilding();
    virtual void UpdateEntity(float DeltaTime) override;
    virtual void RenderEntity() override;

    UFUNCTION(BlueprintCallable, Category="Building")
    void SetProductionDetails(FString ResourceName, float Rate);

    UFUNCTION(BlueprintCallable, Category="Building")
    void ProduceResources(float DeltaTime);
};