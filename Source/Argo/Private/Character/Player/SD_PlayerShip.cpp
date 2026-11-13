// Code Write by JSP

#include "Character/Player/SD_PlayerShip.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/UDS_WeaponComponent.h"
#include "Components/SD_ShipMovementComponent.h"
#include "Core/SD_PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

ASD_PlayerShip::ASD_PlayerShip()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(ShipMesh);
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	SpringArm->SetUsingAbsoluteRotation(true);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	
	
	WeaponComponent = CreateDefaultSubobject<UDS_WeaponComponent>(TEXT("Weapon Component"));
	AimSpeed = 100.f;
}

void ASD_PlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerControllerPtr = Cast<ASD_PlayerController>(GetController());
}



void ASD_PlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASD_PlayerShip::MoveShip);
		EIC->BindAction(DashAction, ETriggerEvent::Started, this, &ASD_PlayerShip::DashShip);
		EIC->BindAction(FireAction, ETriggerEvent::Started, this, &ASD_PlayerShip::StarFire);
		EIC->BindAction(FireAction, ETriggerEvent::Completed, this, &ASD_PlayerShip::EndFire);
	}
}

void ASD_PlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateMeshToFireDirection(DeltaTime);
}

void ASD_PlayerShip::MoveShip(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();
	AddMovementInput(FVector(Input.Y, Input.X, 0.f));
}

void ASD_PlayerShip::DashShip(const FInputActionValue& Value)
{
	MovementComponent->Dash();
}

void ASD_PlayerShip::RotateMeshToFireDirection(const float deltaTime)
{
	if (!PlayerControllerPtr.IsValid())
	{
		return;
	}
	
	if (PlayerControllerPtr->GetAimDirection(GetActorLocation()).IsNearlyZero())
	{
		return;
	}
	const float TargetYaw =  PlayerControllerPtr->GetAimDirection(GetActorLocation()).Rotation().Yaw;
	
	FRotator Rot = ShipMesh->GetComponentRotation();
	Rot.Yaw = FMath::FixedTurn(Rot.Yaw, TargetYaw, AimSpeed * deltaTime); 
	ShipMesh->SetWorldRotation(Rot);

}

void ASD_PlayerShip::StarFire(const FInputActionValue& Value)
{
	WeaponComponent->FireWeapon();
}

void ASD_PlayerShip::EndFire(const FInputActionValue& Value)
{
	WeaponComponent->EndWeapon();
}

