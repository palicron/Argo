// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SD_ShipMovementComponent.h"


USD_ShipMovementComponent::USD_ShipMovementComponent()
{
	bDashing = false;
	DashElapsed = 0.f;
	LastDashEndTime = BufferedDashTime = -10000.f;
	DashDirection = BufferedDashDirection = FVector::ZeroVector;
}

bool USD_ShipMovementComponent::Dash()
{
	const FVector Dir = Velocity.GetSafeNormal();
	if (Dir.IsNearlyZero())
	{
		return false;
	}
	
	const float CurrentTime = GetWorld()->GetTimeSeconds();
	if (bDashing)
	{
		return false;
	}
	
	if (CurrentTime - LastDashEndTime < DashConfiguration.DashCoolDown)
	{
		BufferedDashTime = CurrentTime;
		BufferedDashDirection = Dir;
		return false;
	}
	
	StartDash(Dir);
	return true;
}

void USD_ShipMovementComponent::StartDash(const FVector& Direction)
{
	bDashing = true;
	DashDirection = Direction;
	DashElapsed = 0.f;
	BufferedDashTime = -10000.f;
	OnDashStartedDelegate.Broadcast(DashDirection,GetOwner());
}

void USD_ShipMovementComponent::EndDash()
{
	bDashing = false;
	LastDashEndTime = GetWorld()->GetTimeSeconds();
	Velocity = DashDirection * GetMaxSpeed() * DashConfiguration.DashExitsSpeedRatio;
	OnDashEndedDelegate.Broadcast(GetOwner());
}

void USD_ShipMovementComponent::ApplyControlInputToVelocity(float DeltaTime)
{
	const float NowTime = GetWorld()->GetTimeSeconds();

	if (!bDashing && NowTime - BufferedDashTime <= DashConfiguration.DashBufferTime && NowTime - LastDashEndTime >=
		DashConfiguration.DashCoolDown)
	{
		StartDash(BufferedDashDirection);
	}

	if (!bDashing)
	{
		Super::ApplyControlInputToVelocity(DeltaTime);
	
		return;
	}

	DashElapsed += DeltaTime;
	const float Alpha = FMath::Clamp(DashElapsed / (DashConfiguration.DashDuration > 0.f ? DashConfiguration.DashDuration : 1.f), 0.f, 1.f);
	const float CurveValue = DashConfiguration.DashCurve ? DashConfiguration.DashCurve->GetFloatValue(Alpha) : 1.f;
	Velocity = DashDirection * (DashConfiguration.DashDistance / (DashConfiguration.DashDuration > 0.f ? DashConfiguration.DashDuration : 1.f) ) * CurveValue;

	ConsumeInputVector();

	if (Alpha >= 1.f)
	{
		EndDash();
	}
}
