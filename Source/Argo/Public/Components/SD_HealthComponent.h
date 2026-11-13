// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Definitions/DamageDefinitions.h"
#include "SD_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARGO_API USD_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	USD_HealthComponent();
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	FSD_DamageResult TakeDamage(const FSD_DamageDefinitions& DamageData);
	
protected:
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FSD_HealthConfig HealthConfig;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float CurrentLife;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float CurrentShield;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	uint8 bUsePresetAtStart : 1;
	
	FGameplayTag OwnerTeamTag;
	
	

	
	


};
