// Fill out your copyright notice in the Description page of Project Settings.

#include "STUGameModeBase.h"
#include "Player/STUPlayerController.h"
#include "Player/STUBaseCharacter.h"

ASTUGameModeBase::ASTUGameModeBase()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();

}