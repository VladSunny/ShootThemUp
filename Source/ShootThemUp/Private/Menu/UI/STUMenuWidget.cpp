// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/STUMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUMenuWidget, All, All);

void USTUMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &USTUMenuWidget::OnStartGame);
    }
    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &USTUMenuWidget::OnQuitGame);
    }
}

void USTUMenuWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
    //Super::OnAnimationFinished_Implementation(Animation);

    if (Animation != HideAnimation) return;
    
    if (!GetWorld()) return;

    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstance) return;

    if (STUGameInstance->GetStartupLevelName().IsNone())
    {
        UE_LOG(LogSTUMenuWidget, Error, TEXT("Level name is NONE"));
        return;
    }
    
    UGameplayStatics::OpenLevel(this, STUGameInstance->GetStartupLevelName());
}

void USTUMenuWidget::OnStartGame()
{
    PlayAnimation(HideAnimation);
}

void USTUMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
