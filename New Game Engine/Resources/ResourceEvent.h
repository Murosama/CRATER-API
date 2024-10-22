#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceEvent.generated.h"

UENUM(BlueprintType)
enum class EResourceEventType : uint8 {
    ResourceCollected,
    ResourceUsed,
    ResourceDepleted
};

UCLASS(Blueprintable)
class CITYBUILDER_API UResourceEvent : public UObject {
    GENERATED_BODY()

public:
    UResourceEvent();

    // Event type
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Event")
    EResourceEventType EventType;

    // The amount involved in the event
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Event")
    int32 Amount;

    // The resource involved in the event
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Event")
    FString ResourceName;

    // Function to trigger the event
    UFUNCTION(BlueprintCallable, Category = "Resource Event")
    void TriggerEvent();
};
