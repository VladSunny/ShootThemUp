// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "STUPlayerState.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTUPlayerState : public APlayerState
{
    GENERATED_BODY()
public:
    void SetTeamId(int32 ID) { TeamID = ID; }
    int32 GetTeamID() { return TeamID; }

    void SetTeamColor(FLinearColor Color) { TeamColor = Color; }
    FLinearColor GetTeamColor() { return TeamColor; }

    void AddKill() { ++KillsNum; }
    void AddDeath() { ++DeathsNum; }

    void LogInfo();

private:
    int32 TeamID;
    FLinearColor TeamColor;

    int32 KillsNum = 0;
    int32 DeathsNum = 0;
};
