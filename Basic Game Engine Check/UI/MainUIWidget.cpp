#include "MainUIWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UMainUIWidget::NativeConstruct() {
    Super::NativeConstruct();
    // Initialize UI elements here if necessary
}

void UMainUIWidget::UpdateUI(int32 PopulationCount, const TMap<FString, int32>& Resources) {
    if (PopulationText) {
        PopulationText->SetText(FText::AsNumber(PopulationCount));
    }
    
    UpdateResourceList(Resources);
}

void UMainUIWidget::UpdateResourceList(const TMap<FString, int32>& Resources) {
    // Clear existing resource entries
    ResourceListBox->ClearChildren();

    // Populate the resource list
    for (const auto& Resource : Resources) {
        UTextBlock* ResourceText = NewObject<UTextBlock>();
        ResourceText->SetText(FText::FromString(FString::Printf(TEXT("%s: %d"), *Resource.Key, Resource.Value)));
        ResourceListBox->AddChild(ResourceText);
    }
}
