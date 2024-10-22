#include "Resource.h"

UResource::UResource() {
    ResourceAmount = 0;
    ResourceName = TEXT("Generic Resource");
    bIsRenewable = false;
}

void UResource::Collect(int32 Amount) {
    ResourceAmount += Amount;
    OnCollected(Amount);
}

void UResource::Use(int32 Amount) {
    if (ResourceAmount > 0) {
        ResourceAmount = FMath::Max(ResourceAmount - Amount, 0);
        // Additional logic if the resource is consumed completely
        if (IsEmpty()) {
            // Trigger event or notification
        }
    }
}

void UResource::OnCollected(int32 Amount) {
    // Custom logic upon collection, e.g., logging or triggering UI updates
}