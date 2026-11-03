// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Definitions/MovementDefinitions.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "SD_ShipMovementComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDS_OnDashStartedSignature,const FVector&, Direction, const AActor*, Owner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDS_OnDashEndedSignature,const AActor*, Owner);
/**
 * 
 */
UCLASS()
class ARGO_API USD_ShipMovementComponent : public UFloatingPawnMovement
{
	GENERATED_BODY()
	
	
public:
	USD_ShipMovementComponent();

	UPROPERTY(BlueprintAssignable)
	FDS_OnDashStartedSignature OnDashStartedDelegate;

	UPROPERTY(BlueprintAssignable)
	FDS_OnDashEndedSignature OnDashEndedDelegate;

	UFUNCTION(BlueprintCallable)
	bool Dash();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Configuration | Dash")
	FSD_DashConfiguration DashConfiguration;

	virtual void ApplyControlInputToVelocity(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartDash(const FVector& Direction);

	UFUNCTION(BlueprintCallable)
	void EndDash();

private:
	FVector DashDirection;
	FVector BufferedDashDirection;
	float DashElapsed;
	float LastDashEndTime;
	float BufferedDashTime;
	uint8 bDashing : 1;

};
