#pragma once

#include "CoreMinimal.h"
#include "Resource.generated.h"

USTRUCT(BlueprintType)
struct FResource {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resource")
    FString ResourceName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resource")
    int32 Amount;

    FResource() : ResourceName("Unknown"), Amount(0) {}
};
