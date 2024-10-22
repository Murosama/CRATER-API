#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "WaterResource.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UWaterResource : public UResource {
    GENERATED_BODY()

public:
    UWaterResource();

    virtual void Collect(int32 Amount) override;

    // Get the water purity level
    UFUNCTION(BlueprintCallable, Category = "Water")
    int32 GetPurityLevel() const { return PurityLevel; }

    // Set the water purity level
    UFUNCTION(BlueprintCallable, Category = "Water")
    void SetPurityLevel(int32 Value) { PurityLevel = Value; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Water")
    int32 PurityLevel;

    virtual void OnCollected(int32 Amount) override; // Override for specific behavior
};
