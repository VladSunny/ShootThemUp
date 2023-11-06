// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/STUPauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUPauseWidget, All, All);

void USTUPauseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &USTUPauseWidget::OnClearPause);
    }

    if (BackToMenuButton)
    {
        BackToMenuButton->OnClicked.AddDynamic(this, &USTUPauseWidget::OnBackToMenu);
    }
}

void USTUPauseWidget::OnClearPause()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}

void USTUPauseWidget::OnBackToMenu()
{
    if (!GetWorld()) return;

    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstance) return;

    if (STUGameInstance->GetMenuLevelName().IsNone())
    {
        UE_LOG(LogSTUPauseWidget, Error, TEXT("Level name is NONE"));
        return;
    }

    UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
}
