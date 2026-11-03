// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interface/SD_Damageable.h"
#include "Interface/SD_HealthOwner.h"
#include "SD_ShipBase.generated.h"

class USD_ShipMovementComponent;

UCLASS(Abstract)
class ARGO_API ASD_ShipBase : public APawn, public ISD_Damageable, public ISD_HealthOwner
{
	GENERATED_BODY()

public:
	ASD_ShipBase();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	
	virtual FSD_DamageResult ApplyDamage_Implementation(FSD_DamageDefinitions Damage) override;
	
	virtual USD_HealthComponent* GetHealthComponent_Implementation() const override;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Root")
	TObjectPtr<USceneComponent> ShipRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> ShipMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	TObjectPtr<USD_ShipMovementComponent> MovementComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	TObjectPtr<USD_HealthComponent> HealthComponent;
};
