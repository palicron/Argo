#pragma once

#include "CoreMinimal.h"
#include "WeaponDefinitions.generated.h"


class USD_FireModeBase;
class ASD_BaseBullet;

USTRUCT(blueprinttype)
struct FSD_WeaponConfiguration
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | Damage")
	float BonusDamages;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | Fire")
	uint8 bAutomatic : 1;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Weapon | Reaction")
	uint8 bStartedFire : 1;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Weapon | Reaction")
	uint8 bEndedFire :1;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Weapon | Reaction")
	float FireCoolDown;
	
	FSD_WeaponConfiguration() : BonusDamages(0),
	                            bAutomatic(true),
	                            bStartedFire(true),
	                            bEndedFire(false),
	                            FireCoolDown(0.4f)
	{
	};
};


USTRUCT(blueprinttype)
struct FSD_WeaponSetUp
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | SetUp")
	FSD_WeaponConfiguration WeaponConfiguration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | SetUp")
	TSubclassOf<ASD_BaseBullet> BulletClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon | SetUp")
	TSubclassOf<USD_FireModeBase> FireMode;
	
};
