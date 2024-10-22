#include "MoneyResource.h"

UMoneyResource::UMoneyResource() {
    ResourceName = TEXT("Money");
    bIsRenewable = false; // Money is not renewable
}

void UMoneyResource::Collect(int32 Amount) {
    Super::Collect(Amount);
    // Additional logic for money collection
}

bool UMoneyResource::UseMoney(int32 Amount) {
    if (ResourceAmount >= Amount) {
        Use(Amount);
        return true; // Successfully used money
    }
    return false; // Not enough money
}

void UMoneyResource::OnCollected(int32 Amount) {
    // Logic to handle money-specific behavior
    UE_LOG(LogTemp, Log, TEXT("%d money collected!"), Amount);
}
