#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUIWidget.generated.h"

UCLASS()
class CITYBUILDER_API UMainUIWidget : public UUserWidget {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateUI(int32 PopulationCount, const TMap<FString, int32>& Resources);
    
protected:
    virtual void NativeConstruct() override;

private:
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PopulationText;

    UPROPERTY(meta = (BindWidget))
    class UVerticalBox* ResourceListBox;

    void UpdateResourceList(const TMap<FString, int32>& Resources);
};
