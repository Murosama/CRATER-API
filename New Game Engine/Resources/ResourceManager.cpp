#include "ResourceManager.h"

UResourceManager::UResourceManager() {
    // Initialization
}

void UResourceManager::AddResource(UResource* Resource) {
    Resources.Add(Resource);
    NotifyResourceChange(Resource->GetResourceName(), Resource->GetResourceAmount(), true);
}

void UResourceManager::RemoveResource(UResource* Resource) {
    Resources.Remove(Resource);
    NotifyResourceChange(Resource->GetResourceName(), Resource->GetResourceAmount(), false);
}

int32 UResourceManager::GetTotalResourceCount() const {
    int32 Total = 0;
    for (const UResource* Resource : Resources) {
        Total += Resource->GetResourceAmount();
    }
    return Total;
}

void UResourceManager::NotifyResourceChange(const FString& ResourceName, int32 Amount, bool bIsAdded) {
    // Notify about resource changes
    UResourceNotification* Notification = NewObject<UResourceNotification>();
    Notification->NotifyResourceChange(ResourceName, Amount, bIsAdded);
}
