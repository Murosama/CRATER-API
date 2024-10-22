#pragma once

#include "CoreMinimal.h"
#include "ResourceManager.generated.h"

UCLASS()
class CITYBUILDER_API UResourceManager : public UObject {
    GENERATED_BODY()

private:
    UPROPERTY()
    TMap<FString, FResource> Resources;

public:
    UFUNCTION(BlueprintCallable, Category="Resource Management")
    void AddResource(FString ResourceName, int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Resource Management")
    void RemoveResource(FString ResourceName, int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Resource Management")
    int32 GetResourceAmount(FString ResourceName) const;

    UFUNCTION(BlueprintCallable, Category="Resource Management")
    void InitializeResources();
};
