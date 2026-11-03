// Code Write by JSP

#include "Character/Player/SD_PlayerShip.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SD_ShipMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASD_PlayerShip::ASD_PlayerShip()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(ShipMesh);
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	
	MovementComponent->bConstrainToPlane = true;
	MovementComponent->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Z);  
	MovementComponent->bSnapToPlaneAtStart = true;
	MovementComponent->SetPlaneConstraintOrigin(FVector(0.f, 0.f, 20.f));  
}

void ASD_PlayerShip::BeginPlay()
{
	Super::BeginPlay();
}

void ASD_PlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASD_PlayerShip::MoveShip);
		EIC->BindAction(DashAction, ETriggerEvent::Started, this, &ASD_PlayerShip::DashShip);
	}
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

 
