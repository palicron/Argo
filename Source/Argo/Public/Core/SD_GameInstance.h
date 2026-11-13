// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/GameInstance.h"
#include "SD_GameInstance.generated.h"

struct FSD_WeaponSetUp;
class USD_WeaponConfigurationData;
/**
 * 
 */
UCLASS()
class ARGO_API USD_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	
public:
	
	UFUNCTION(BlueprintCallable)
	bool GetWeaponSetUp(FGameplayTag WeaponTag, FSD_WeaponSetUp& OutWeaponSetUp) const;
	
protected:
	
	UPROPERTY(EditDefaultsOnly,blueprintreadwrite,Category="Data | Weapon")
	TObjectPtr<USD_WeaponConfigurationData> WeaponConfigurationDataClass;
	
	
	
};
