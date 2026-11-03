// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SD_PlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class ARGO_API ASD_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	ASD_PlayerController();
	
	virtual void BeginPlay() override;
	
protected:
	
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	UInputMappingContext* DefaultMappingContexts;
	
	UFUNCTION(blueprintCallable)
	void BindMappingContext(UInputMappingContext* NewMapping, int32 NewMappingPriority);
	
};
