#include "ResourceManager.h"

void UResourceManager::InitializeResources() {
    // Initialize default resources
    Resources.Add("Wood", FResource{"Wood", 100});
    Resources.Add("Stone", FResource{"Stone", 100});
    Resources.Add("Food", FResource{"Food", 100});
}

void UResourceManager::AddResource(FString ResourceName, int32 Amount) {
    if (Resources.Contains(ResourceName)) {
        Resources[ResourceName].Amount += Amount;
    } else {
        Resources.Add(ResourceName, FResource{ResourceName, Amount});
    }
}

void UResourceManager::RemoveResource(FString ResourceName, int32 Amount) {
    if (Resources.Contains(ResourceName)) {
        Resources[ResourceName].Amount = FMath::Max(Resources[ResourceName].Amount - Amount, 0);
    }
}

int32 UResourceManager::GetResourceAmount(FString ResourceName) const {
    return Resources.Contains(ResourceName) ? Resources[ResourceName].Amount : 0;
}