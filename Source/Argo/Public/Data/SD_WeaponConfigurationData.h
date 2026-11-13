// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Definitions/WeaponDefinitions.h"
#include "Engine/DataAsset.h"
#include "SD_WeaponConfigurationData.generated.h"


/**
 * 
 */
UCLASS()
class ARGO_API USD_WeaponConfigurationData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	bool GetWeaponSetUp(FGameplayTag WeaponTag, FSD_WeaponSetUp& OutWeaponSetUp) const;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Weapon Configuration")
	TMap<FGameplayTag, FSD_WeaponSetUp> WeaponConfigurationMap;
	
};
