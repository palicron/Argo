// Code Write by JSP


#include "Core/SD_PlayerController.h"
#include "EnhancedInputSubsystems.h"

ASD_PlayerController::ASD_PlayerController()
{
}

void ASD_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	BindMappingContext(DefaultMappingContexts, 0);
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
