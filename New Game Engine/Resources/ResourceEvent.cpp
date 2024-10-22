#include "ResourceEvent.h"

UResourceEvent::UResourceEvent() {
    EventType = EResourceEventType::ResourceCollected;
    Amount = 0;
    ResourceName = TEXT("Generic Resource");
}

void UResourceEvent::TriggerEvent() {
    // Logic to trigger the event, such as logging or notifying listeners
    switch (EventType) {
        case EResourceEventType::ResourceCollected:
            UE_LOG(LogTemp, Log, TEXT("Collected %d of %s."), Amount, *ResourceName);
            break;
        case EResourceEventType::ResourceUsed:
            UE_LOG(LogTemp, Log, TEXT("Used %d of %s."), Amount, *ResourceName);
            break;
        case EResourceEventType::ResourceDepleted:
            UE_LOG(LogTemp, Log, TEXT("%s is depleted!"), *ResourceName);
            break;
        default:
            break;
    }
}
