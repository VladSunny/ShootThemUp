// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/STUGameOverWidget.h"
#include "STUGameModeBase.h"
#include "Player/STUPlayerState.h"
#include "UI/STUPlayerStatRowWidget.h"
#include "Components/VerticalBox.h"
#include "STUUtils.h"

bool USTUGameOverWidget::Initialize()
{
    if (GetWorld())
    {
        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &USTUGameOverWidget::OnMatchStateChanged);
        }
    }
    return Super::Initialize();
}

void USTUGameOverWidget::OnMatchStateChanged(ESTUMatchState State)
{
    if (State == ESTUMatchState::GameOver)
    {
        UpdatePlayersStat();
    }
}

void USTUGameOverWidget::UpdatePlayersStat()
{
    if (!GetWorld() || !PlayerStatBox) return;

    PlayerStatBox->ClearChildren();

    for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        const auto Controller = It->Get();
        if (!Controller) continue;

        const auto PlayerState = Cast<ASTUPlayerState>(Controller->PlayerState);
        if (!PlayerState) continue;

        const auto PlayerStateRowWidget = CreateWidget<USTUPlayerStatRowWidget>(GetWorld(), PlayerStatRowWidgetClass);
        if (!PlayerStateRowWidget) continue;

        PlayerStateRowWidget->SetPlayerName(FText::FromString(PlayerState->GetPlayerName()));
        PlayerStateRowWidget->SetKills(STUUtils::TextFromInt(PlayerState->GetKillsNum()));
        PlayerStateRowWidget->SetDeaths(STUUtils::TextFromInt(PlayerState->GetDeathsNum()));
        PlayerStateRowWidget->SetTeam(STUUtils::TextFromInt(PlayerState->GetTeamID()));
        PlayerStateRowWidget->SetPlayerIndicatorVisibility(Controller->IsPlayerController());

        PlayerStatBox->AddChild(PlayerStateRowWidget);
    }
}
