#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RenderingEngine.generated.h"

UCLASS()
class YOURPROJECT_API ARenderingEngine : public AActor {
    GENERATED_BODY()

public:
    ARenderingEngine();

    void RenderScene();
};