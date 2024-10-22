#pragma once

#include "CoreMinimal.h"
#include "Resource.h"
#include "ResourceManager.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UResourceManager : public UObject {
    GENERATED_BODY()

public:
    UResourceManager();

    // Function to manage resources
    UFUNCTION(BlueprintCallable, Category = "Resource Management")
    void AddResource(UResource* Resource);

    UFUNCTION(BlueprintCallable, Category = "Resource Management")
    void RemoveResource(UResource* Resource);

    // Get total resource count
    UFUNCTION(BlueprintCallable, Category = "Resource Management")
    int32 GetTotalResourceCount() const;

protected:
    UPROPERTY()
    TArray<UResource*> Resources;

    void NotifyResourceChange(const FString& ResourceName, int32 Amount, bool bIsAdded);
};