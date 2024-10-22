#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "EnergyResource.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UEnergyResource : public UResource {
    GENERATED_BODY()

public:
    UEnergyResource();

    virtual void Collect(int32 Amount) override;

    // Set the energy output value
    UFUNCTION(BlueprintCallable, Category = "Energy")
    void SetEnergyOutput(int32 Value) { EnergyOutput = Value; }

    // Get the energy output value
    UFUNCTION(BlueprintCallable, Category = "Energy")
    int32 GetEnergyOutput() const { return EnergyOutput; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Energy")
    int32 EnergyOutput;

    virtual void OnCollected(int32 Amount) override; // Override for specific behavior
};
