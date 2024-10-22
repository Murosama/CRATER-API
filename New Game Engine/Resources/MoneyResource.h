#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "MoneyResource.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UMoneyResource : public UResource {
    GENERATED_BODY()

public:
    UMoneyResource();

    virtual void Collect(int32 Amount) override;

    // Use money and check if enough money is available
    UFUNCTION(BlueprintCallable, Category = "Money")
    bool UseMoney(int32 Amount);

protected:
    virtual void OnCollected(int32 Amount) override; // Override for specific behavior
};
