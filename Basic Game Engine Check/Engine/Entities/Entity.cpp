#include "Entity.h"

AEntity::AEntity() {
    PrimaryActorTick.bCanEverTick = true;
    Position = FVector(0.0f, 0.0f, 0.0f);

    // mesh  (e.g., building model)
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
}

void AEntity::AddComponent(UActorComponent* NewComponent) {
    if (NewComponent) {
        NewComponent->RegisterComponent();
        AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    }
}

void AEntity::AddResource(FString ResourceName, int32 Amount) {
    if (Resources.Contains(ResourceName)) {
        Resources[ResourceName] += Amount;
    } else {
        Resources.Add(ResourceName, Amount);
    }
}

int32 AEntity::GetResource(FString ResourceName) {
    if (Resources.Contains(ResourceName)) {
        return Resources[ResourceName];
    }
    return 0;  // Return 0 if resource doesn't exist
}

void AEntity::InteractWithEntity(AEntity* OtherEntity) {
    if (OtherEntity) {
        UE_LOG(LogTemp, Warning, TEXT("Interacting with %s"), *OtherEntity->GetName());
        // interaction logic 
    }
}