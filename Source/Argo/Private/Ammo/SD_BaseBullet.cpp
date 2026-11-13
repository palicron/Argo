// Code Write by JSP


#include "Ammo/SD_BaseBullet.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASD_BaseBullet::ASD_BaseBullet()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMeshComponent"));
	SetRootComponent(MeshComponent);
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
}


// Called when the game starts or when spawned
void ASD_BaseBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASD_BaseBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASD_BaseBullet::Fire()
{
	ProjectileMovementComponent->SetUpdatedComponent(MeshComponent); 
	const FVector Dir = GetActorForwardVector();
	const FVector ShipVelocity = GetOwner() ? GetOwner()->GetVelocity() : FVector::ZeroVector;
	
	const FVector FinalDir = FVector::DotProduct(ShipVelocity.GetSafeNormal(), Dir) < -0.15f ? Dir : (ShipVelocity + Dir).GetSafeNormal();
	
	const float InheritedSpeed = FMath::Max(0.f, FVector::DotProduct(ShipVelocity, FinalDir));
	ProjectileMovementComponent->Velocity =  FinalDir * (ProjectileMovementComponent->InitialSpeed + InheritedSpeed);
	ProjectileMovementComponent->ClearPendingForce(true);
	//TODO MAGE homming
	ProjectileMovementComponent->SetComponentTickEnabled(true);
	ProjectileMovementComponent->Activate();
	ProjectileMovementComponent->UpdateComponentVelocity();
}

void ASD_BaseBullet::OnPoolableObjectTake_Implementation()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void ASD_BaseBullet::OnPoolableObjectReturn_Implementation()
{
	ProjectileMovementComponent->StopMovementImmediately();
	ProjectileMovementComponent->Deactivate();
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}


