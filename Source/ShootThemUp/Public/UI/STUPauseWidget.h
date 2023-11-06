// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUPauseWidget.generated.h"

class UButton;

UCLASS()
class SHOOTTHEMUP_API USTUPauseWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeOnInitialized() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* ClearPauseButton;

    UPROPERTY(meta = (BindWidget))
    UButton* BackToMenuButton;

private:
    UFUNCTION()
    void OnClearPause();

    UFUNCTION()
    void OnBackToMenu();
};
