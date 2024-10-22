#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Resource.generated.h"

UCLASS(Blueprintable, Abstract)
class CITYBUILDER_API UResource : public UObject {
    GENERATED_BODY()

public:
    UResource();

    // Collect resources
    UFUNCTION(BlueprintCallable, Category = "Resource")
    virtual void Collect(int32 Amount);

    // Use resources
    UFUNCTION(BlueprintCallable, Category = "Resource")
    virtual void Use(int32 Amount);

    // Get current resource amount
    UFUNCTION(BlueprintCallable, Category = "Resource")
    virtual int32 GetAmount() const { return ResourceAmount; }

    // Check if the resource is empty
    UFUNCTION(BlueprintCallable, Category = "Resource")
    virtual bool IsEmpty() const { return ResourceAmount <= 0; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
    int32 ResourceAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
    FString ResourceName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
    bool bIsRenewable; // Indicates if the resource can regenerate over time

    
    virtual void OnCollected(int32 Amount);
};