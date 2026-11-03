#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DamageDefinitions.generated.h" 

USTRUCT(BlueprintType)
struct FSD_DamageDefinitions
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	float Damage;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	FGameplayTag DamageType;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	TObjectPtr<AActor> DamageSource;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	TObjectPtr<AActor> Instigator;
	
	FSD_DamageDefinitions():Damage(0.f),DamageSource(nullptr),Instigator(nullptr)
	{}
	
};

USTRUCT(BlueprintType)
struct FSD_DamageResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Result | Damage")
	float TotalHealthDamageTaken;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Result | Damage")
	float TotalShielDamageTaken;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Result | Damage")
	uint8 bBreaksShield : 1;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Result | Damage")
	uint8 bKilled : 1;
	
	FSD_DamageResult():TotalHealthDamageTaken(0.f),TotalShielDamageTaken(0.f),bBreaksShield(false),bKilled(false)
	{}
};
