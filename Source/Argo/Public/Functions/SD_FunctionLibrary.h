// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Definitions/WeaponDefinitions.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SD_FunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ARGO_API USD_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
public:
	
	UFUNCTION(BlueprintCallable)
	static bool GetWeaponPreset(UObject* WorldContextObject,const FGameplayTag WeaponPreset, FSD_WeaponSetUp& OutWeaponPreset);
	
};
