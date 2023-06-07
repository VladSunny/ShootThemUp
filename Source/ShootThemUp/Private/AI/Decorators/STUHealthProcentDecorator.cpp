// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/Decorators/STUHealthProcentDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"

USTUHealthProcentDecorator::USTUHealthProcentDecorator()
{
    NodeName = "Health Precent";
}

bool USTUHealthProcentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;
    
    const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(Controller->GetPawn());
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    return HealthComponent->GetHealthPrecent() <= HealthPercent;
}
