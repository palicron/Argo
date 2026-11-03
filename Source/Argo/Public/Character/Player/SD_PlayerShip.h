// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Character/SD_ShipBase.h"
#include "SD_PlayerShip.generated.h"

class UInputAction;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class ARGO_API ASD_PlayerShip : public ASD_ShipBase
{
	GENERATED_BODY()
	
public:
	
	ASD_PlayerShip();
	
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category= "Components | Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, blueprintReadWrite, Category= "Components | Camera")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, Category="Input | Movement")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category="Input | Movement")
	UInputAction* DashAction;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
	void MoveShip(const FInputActionValue& Value);
	
	UFUNCTION()
	void DashShip(const FInputActionValue& Value);
	
	
};
