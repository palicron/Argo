// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SD_HealthComponent.h"


USD_HealthComponent::USD_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	CurrentLife = 100.f;
	CurrentShield = 100.f;
}


void USD_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

}

FSD_DamageResult USD_HealthComponent::TakeDamage(const FSD_DamageDefinitions& DamageData)
{
	if (DamageData.Damage <= 0)
	{
		return FSD_DamageResult();
	}
	
	FSD_DamageResult NewDamageResult;
	
	float LifeDamage = DamageData.Damage;
	
	if (CurrentShield > 0 && CurrentShield - LifeDamage <= 0)
	{
		LifeDamage -= CurrentShield;
		NewDamageResult.TotalShielDamageTaken = CurrentShield;
		NewDamageResult.bBreaksShield = true;
		CurrentShield = 0;
	}
	else if (CurrentShield > 0)
	{
		CurrentShield -= LifeDamage;
		NewDamageResult.TotalShielDamageTaken = LifeDamage;
		NewDamageResult.bBreaksShield = false;
		
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(99, 15.0f, FColor::Yellow, 
				FString::Printf(TEXT("Shield Take Damage %f"), NewDamageResult.TotalShielDamageTaken));
		return NewDamageResult;
	}
	
	NewDamageResult.TotalHealthDamageTaken = LifeDamage;
	
	CurrentLife = FMath::Max(CurrentLife - LifeDamage, 0.0f);
	
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(99, 15.0f, FColor::Yellow, 
			FString::Printf(TEXT("Life Take Damage %f"), NewDamageResult.TotalHealthDamageTaken));
	if (CurrentLife <= 0)
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Death!"));	
		NewDamageResult.bKilled = true;
	}
	
	return  NewDamageResult;
}


