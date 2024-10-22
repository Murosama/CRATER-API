#include "EventManager.h"

void UEventManager::TriggerResourceChange(FString ResourceName) {
    // Broadcast the resource change event
    OnResourceChangeEvent.Broadcast(ResourceName);
}
