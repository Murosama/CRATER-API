#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceNotification.generated.h"

UCLASS(Blueprintable)
class CITYBUILDER_API UResourceNotification : public UObject {
    GENERATED_BODY()

public:
    UResourceNotification();

    // Notify resource changes
    UFUNCTION(BlueprintCallable, Category = "Resource Notification")
    void NotifyResourceChange(const FString& ResourceName, int32 Amount, bool bIsAdded);
};
