#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MovementDefinitions.generated.h"


USTRUCT(BlueprintType)
struct FSD_DashConfiguration
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Dash")
	float DashDuration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Dash")
	float DashDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Dash")
	float DashCoolDown;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Dash")
	float DashExitsSpeedRatio;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Dash")
	float DashBufferTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Dash")
	TObjectPtr<UCurveFloat> DashCurve;
	
	FSD_DashConfiguration():
		DashDuration(0.2f),
		DashDistance(1000.f),
		DashCoolDown(0.5f),
		DashExitsSpeedRatio(0.8f),
		DashBufferTime(0.1f),
		DashCurve(nullptr)
	{}
};
