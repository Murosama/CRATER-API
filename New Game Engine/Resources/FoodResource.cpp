#include "FoodResource.h"

UFoodResource::UFoodResource() {
    NutritionValue = 10; // Default nutrition value
    ResourceName = TEXT("Food");
    bIsRenewable = true; // Food can be replenished
}

void UFoodResource::Collect(int32 Amount) {
    Super::Collect(Amount);
    // Additional logic for food collection
}

void UFoodResource::OnCollected(int32 Amount) {
    // Logic to handle food-specific behavior, like updating UI or statistics
    UE_LOG(LogTemp, Log, TEXT("%d units of food collected!"), Amount);
}
