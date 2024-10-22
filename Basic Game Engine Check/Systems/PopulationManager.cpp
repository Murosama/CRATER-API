#include "PopulationManager.h"

UPopulationManager::UPopulationManager() {
    // Initialize the population manager
}

void UPopulationManager::AddCitizen(const FString& CitizenName, int32 CitizenAge) {
    Citizens.Add(FCitizen{CitizenName, CitizenAge});
}

void UPopulationManager::RemoveCitizen(const FString& CitizenName) {
    Citizens.RemoveAll([CitizenName](const FCitizen& Citizen) {
        return Citizen.Name == CitizenName;
    });
}

int32 UPopulationManager::GetPopulationCount() const {
    return Citizens.Num();
}

TArray<FCitizen> UPopulationManager::GetCitizens() const {
    return Citizens;
}
