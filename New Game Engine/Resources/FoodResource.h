#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "FoodResource.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UFoodResource : public UResource {
    GENERATED_BODY()

public:
    UFoodResource();

    virtual void Collect(int32 Amount) override;

    // Set the nutrition value
    UFUNCTION(BlueprintCallable, Category = "Food")
    void SetNutritionValue(int32 Value) { NutritionValue = Value; }

    // Get the nutrition value
    UFUNCTION(BlueprintCallable, Category = "Food")
    int32 GetNutritionValue() const { return NutritionValue; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
    int32 NutritionValue;

    virtual void OnCollected(int32 Amount) override; // Override for specific behavior
};
