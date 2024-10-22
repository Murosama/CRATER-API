#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "Building.generated.h"

UCLASS()
class CITYBUILDER_API ABuilding : public AEntity {
    GENERATED_BODY()

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building", meta=(AllowPrivateAccess="true"))
    FString BuildingType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building", meta=(AllowPrivateAccess="true"))
    float ProductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building", meta=(AllowPrivateAccess="true"))
    FString ProducingResource;

public:
    ABuilding();

    virtual void UpdateEntity(float DeltaTime) override;

    void SetProductionDetails(FString NewResource, float NewRate);
    FString GetBuildingType() const;
    void ProduceResources(UResourceManager* ResourceManager);
};