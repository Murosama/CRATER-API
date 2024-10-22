#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "FuelResource.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UFuelResource : public UResource {
    GENERATED_BODY()

public:
    UFuelResource();

    virtual void Collect(int32 Amount) override;

    // Get the fuel efficiency
    UFUNCTION(BlueprintCallable, Category = "Fuel")
    int32 GetFuelEfficiency() const { return FuelEfficiency; }

    // Set the fuel efficiency
    UFUNCTION(BlueprintCallable, Category = "Fuel")
    void SetFuelEfficiency(int32 Value) { FuelEfficiency = Value; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuel")
    int32 FuelEfficiency;

    virtual void OnCollected(int32 Amount) override; // Override for specific behavior
};
