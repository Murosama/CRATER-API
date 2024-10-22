#pragma once

#include "CoreMinimal.h"
#include "PopulationManager.generated.h"

// Structure to represent a citizen
USTRUCT(BlueprintType)
struct FCitizen {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Citizen")
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Citizen")
    int32 Age;

    FCitizen() : Name(TEXT("Unnamed")), Age(0) {}
};

// Manager class for handling the population of the city
UCLASS(Blueprintable)
class CITYBUILDER_API UPopulationManager : public UObject {
    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<FCitizen> Citizens;

public:
    UPopulationManager();

    void AddCitizen(const FString& CitizenName, int32 CitizenAge);
    void RemoveCitizen(const FString& CitizenName);
    int32 GetPopulationCount() const;
    TArray<FCitizen> GetCitizens() const;
};
