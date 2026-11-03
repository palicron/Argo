// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SD_ShipBase.h"

#include "Components/SD_HealthComponent.h"
#include "Components/SD_ShipMovementComponent.h"

ASD_ShipBase::ASD_ShipBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ShipRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Ship Root"));
	SetRootComponent(ShipRoot);

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>("Ship Mesh");
	ShipMesh->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<USD_ShipMovementComponent>("Ship Movement Component");
	
	HealthComponent = CreateDefaultSubobject<USD_HealthComponent>("Ship Health Component");
}

void ASD_ShipBase::BeginPlay()
{
	Super::BeginPlay();
	
	ensureMsgf(MovementComponent && !MovementComponent->IsTemplate(),
	TEXT("%s: MovementComponent is null or a CDO template (%s). Recreate the Blueprint."),
	*GetName(), *GetPathNameSafe(MovementComponent));
}

FSD_DamageResult ASD_ShipBase::ApplyDamage_Implementation(FSD_DamageDefinitions Damage)
{
	return FSD_DamageResult();
}

USD_HealthComponent* ASD_ShipBase::GetHealthComponent_Implementation() const
{
	return HealthComponent;
}

void ASD_ShipBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASD_ShipBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

