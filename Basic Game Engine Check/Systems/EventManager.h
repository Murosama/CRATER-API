#pragma once

#include "CoreMinimal.h"
#include "EventManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResourceChange, FString, ResourceName);

UCLASS()
class CITYBUILDER_API UEventManager : public UObject {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Events")
    FOnResourceChange OnResourceChangeEvent;

    void TriggerResourceChange(FString ResourceName) {
        OnResourceChangeEvent.Broadcast(ResourceName);
    }
};
