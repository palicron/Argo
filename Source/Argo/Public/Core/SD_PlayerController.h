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
	
	UFUNCTION(BlueprintCallable)
	FVector GetAimDirection(const FVector& FireLocation) const;
protected:
	
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	UInputMappingContext* DefaultMappingContexts;
	
	UPROPERTY(Transient)
	FVector MouseWorldPoint;
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
	void UpdateGetMousePosition();
	
	UFUNCTION(blueprintCallable)
	void BindMappingContext(UInputMappingContext* NewMapping, int32 NewMappingPriority);
	
};
