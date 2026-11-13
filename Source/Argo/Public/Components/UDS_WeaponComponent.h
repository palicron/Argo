// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Definitions/WeaponDefinitions.h"
#include "UDS_WeaponComponent.generated.h"


class USD_FireModeBase;
class ASD_BaseBullet;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARGO_API UDS_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UDS_WeaponComponent();
	
	UFUNCTION(BlueprintCallable,Category="Weapon")
	void SetUpWeaponPreset(const FGameplayTag& PresetTag);
	
	UFUNCTION(BlueprintCallable,Category="Weapon")
	void SetUpWeaponAmmo(ASD_BaseBullet* NewBulletClass);
	
	UFUNCTION(BlueprintCallable,Category="Weapon")
	void SetUpWeaponFireMode(TSubclassOf<USD_FireModeBase> FireModeClass);
	
	UFUNCTION(BlueprintCallable,Category="Weapon")
	void SetUpWeaponConfiguration(FSD_WeaponConfiguration NewCurrentWeaponSetup);

	UFUNCTION(BlueprintCallable,Category="Weapon")
	void FireWeapon();
	
	UFUNCTION(BlueprintCallable,Category="Weapon")
	void EndWeapon();
	
	virtual void BeginPlay() override;
	
protected:
	

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Preset")
	FGameplayTag InitialPreset;
	
	UPROPERTY(BlueprintReadOnly,Category="Weapon")
	FSD_WeaponSetUp CurrentWeaponSetup;
	
	UFUNCTION()
	void InternalFire();

private: 
	
	float LastFireTime;
	
	FTimerHandle FireTimerHandle;
	
		
};
