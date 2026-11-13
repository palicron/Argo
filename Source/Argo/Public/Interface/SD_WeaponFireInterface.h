// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SD_WeaponFireInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USD_WeaponFireInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARGO_API ISD_WeaponFireInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	FVector GetMuzzleLocation();
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	FVector GetMuzzleForwardVector();
	
};
