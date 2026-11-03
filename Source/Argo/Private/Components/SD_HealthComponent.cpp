// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SD_HealthComponent.h"


USD_HealthComponent::USD_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void USD_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

}


void USD_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

