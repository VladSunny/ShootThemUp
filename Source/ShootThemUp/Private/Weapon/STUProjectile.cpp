// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"

ASTUProjectile::ASTUProjectile()
{
    PrimaryActorTick.bCanEverTick = false;
    
    CollisionComponent = CreateDefaultSubobject<USphereComponent>("USphereComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionComponent);
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();
}
