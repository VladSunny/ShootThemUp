// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"

ASTUPlayerController::ASTUPlayerController() {
    STURespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("STURespawnComponent");
}

void ASTUPlayerController::OnPossess(APawn* InPawn) {
    Super::OnPossess(InPawn);

    OnNewPawn.Broadcast(InPawn);
}
