// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Character/SD_ShipBase.h"
#include "SD_PlayerShip.generated.h"

class UDS_WeaponComponent;
class ASD_PlayerController;
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
	
	TWeakObjectPtr<ASD_PlayerController> PlayerControllerPtr;
	
	UPROPERTY(EditDefaultsOnly, blueprintReadWrite, Category= "Components | Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditDefaultsOnly, blueprintReadWrite, Category= "Components | Camera")
	TObjectPtr<UCameraComponent> Camera;
	
	UPROPERTY(EditDefaultsOnly, blueprintReadWrite, Category= "Components | Camera")
	TObjectPtr<UDS_WeaponComponent> WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category="Input | Movement")
	UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Input | Movement")
	UInputAction* DashAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Input | Attack")
	UInputAction* FireAction;
	
	UPROPERTY(EditDefaultsOnly	, Category="Input | Aim")
	float AimSpeed;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void MoveShip(const FInputActionValue& Value);
	
	UFUNCTION()
	void DashShip(const FInputActionValue& Value);
	
	UFUNCTION()
	void RotateMeshToFireDirection(const float deltaTime);
	
	UFUNCTION()
	void StarFire(const FInputActionValue& Value);
	
	UFUNCTION()
	void EndFire(const FInputActionValue& Value);
};
