#include "RenderingEngine.h"

ARenderingEngine::ARenderingEngine() {
    PrimaryActorTick.bCanEverTick = true;
}

void ARenderingEngine::RenderScene() {
    // Unreal manages rendering, so this function will handle scene management
}