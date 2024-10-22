#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Entity.generated.h"

UCLASS(Abstract)
class CITYBUILDER_API AEntity : public AActor {
    GENERATED_BODY()

protected:
    FVector Position;
    UStaticMeshComponent* MeshComponent;
    TMap<FString, int32> Resources;  // Tracks resource counts (e.g., wood, stone)
    
public:
    AEntity();

    // Modular component system for adding behavior dynamically
    UFUNCTION(BlueprintCallable, Category="Entity")
    virtual void AddComponent(UActorComponent* NewComponent);

    // Resource management functions
    UFUNCTION(BlueprintCallable, Category="Entity")
    virtual void AddResource(FString ResourceName, int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Entity")
    virtual int32 GetResource(FString ResourceName);

    // Interaction system for interacting with other entities
    UFUNCTION(BlueprintCallable, Category="Entity")
    virtual void InteractWithEntity(AEntity* OtherEntity);

    // Abstract methods to implement in child classes
    virtual void UpdateEntity(float DeltaTime) PURE_VIRTUAL(AEntity::UpdateEntity, );
    virtual void RenderEntity() PURE_VIRTUAL(AEntity::RenderEntity, );
};