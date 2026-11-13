// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interface/SD_Damageable.h"
#include "Interface/SD_HealthOwner.h"
#include "Interface/SD_WeaponFireInterface.h"
#include "SD_ShipBase.generated.h"

class USD_ShipMovementComponent;

UCLASS(Abstract)
class ARGO_API ASD_ShipBase : public APawn, public ISD_Damageable, public ISD_HealthOwner, public ISD_WeaponFireInterface
{
	GENERATED_BODY()

public:
	ASD_ShipBase();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	
	virtual FSD_DamageResult ApplyDamage_Implementation(FSD_DamageDefinitions Damage) override;
	
	virtual USD_HealthComponent* GetHealthComponent_Implementation() const override;

	//UFUNCTION(BlueprintCallable)
	//virtual FGameplayTag GetTeamTag() const { return TeamTag; }
	
	virtual FVector GetMuzzleLocation_Implementation() override { return PrincipalMuzzleComponent->GetComponentLocation();};
	
	virtual FVector GetMuzzleForwardVector_Implementation() override {return PrincipalMuzzleComponent->GetForwardVector();};
	
	virtual FGameplayTag GetTeamTag_Implementation() override { return TeamTag; }
	
	
protected:
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Root")
	TObjectPtr<USceneComponent> ShipRoot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> ShipMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component")
	TObjectPtr<USD_ShipMovementComponent> MovementComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component")
	TObjectPtr<USD_HealthComponent> HealthComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Component")
	TObjectPtr<USceneComponent> PrincipalMuzzleComponent;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category=" Team")
	FGameplayTag TeamTag;
};
