#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "MaterialResource.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UMaterialResource : public UResource {
    GENERATED_BODY()

public:
    UMaterialResource();

    virtual void Collect(int32 Amount) override;

    // Set the durability value
    UFUNCTION(BlueprintCallable, Category = "Material")
    void SetDurability(int32 Value) { Durability = Value; }

    // Get the durability value
    UFUNCTION(BlueprintCallable, Category = "Material")
    int32 GetDurability() const { return Durability; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
    int32 Durability;

    virtual void OnCollected(int32 Amount) override; // Override for specific behavior
};
