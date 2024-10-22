#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputHandler.generated.h"

UCLASS()
class YOURPROJECT_API AInputHandler : public APlayerController {
    GENERATED_BODY()

public:
    AInputHandler();

protected:
    virtual void SetupInputComponent() override;
};