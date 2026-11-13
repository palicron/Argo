// Code Write by JSP


#include "Core/SD_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Definitions/Definitions.h"

ASD_PlayerController::ASD_PlayerController()
{
}



void ASD_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	BindMappingContext(DefaultMappingContexts, 0);
	
	bShowMouseCursor = true;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASD_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateGetMousePosition();
}

void ASD_PlayerController::UpdateGetMousePosition()
{
	FHitResult Hit;

	if (GetHitResultUnderCursor(SD_AIMSURFACE, false, Hit))
	{
		MouseWorldPoint = Hit.Location;
		
		DrawDebugSphere(GetWorld(), MouseWorldPoint, 10.f, 10, FColor::Red);
	}
	
}

void ASD_PlayerController::BindMappingContext(UInputMappingContext* NewMapping, int32 NewMappingPriority)
{
	if (!NewMapping)
	{
		return;
	}
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(NewMapping, NewMappingPriority);
	}
}

FVector ASD_PlayerController::GetAimDirection(const FVector& FireLocation) const
{
	return (MouseWorldPoint - FireLocation).GetSafeNormal2D();
}
