// Code Write by JSP


#include "Components/UDS_WeaponComponent.h"

#include "Ammo/SD_BaseBullet.h"
#include "Core/SD_GameInstance.h"
#include "Functions/SD_FunctionLibrary.h"
#include "Interface/SD_WeaponFireInterface.h"

UDS_WeaponComponent::UDS_WeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	LastFireTime = true;
}

void UDS_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
	SetUpWeaponPreset(InitialPreset);
}


void UDS_WeaponComponent::SetUpWeaponPreset(const FGameplayTag& PresetTag)
{
	USD_FunctionLibrary::GetWeaponPreset(this,PresetTag,CurrentWeaponSetup);
}

void UDS_WeaponComponent::SetUpWeaponAmmo(ASD_BaseBullet* NewBulletClass)
{
}

void UDS_WeaponComponent::SetUpWeaponFireMode(TSubclassOf<USD_FireModeBase> FireModeClass)
{
}

void UDS_WeaponComponent::SetUpWeaponConfiguration(FSD_WeaponConfiguration NewCurrentWeaponSetup)
{
}

void UDS_WeaponComponent::FireWeapon()
{
	if (!CurrentWeaponSetup.WeaponConfiguration.bStartedFire)
	{
		return;
	}
	
	if (CurrentWeaponSetup.WeaponConfiguration.bAutomatic)
	{
		GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
		FTimerManagerTimerParameters Params;
		Params.bLoop = true;
		Params.bMaxOncePerFrame = true; 
		Params.FirstDelay = 0.f;

		GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &UDS_WeaponComponent::InternalFire, 0.1f, Params);
		return;
	}
	

	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("STAR FIRE"));
	
	InternalFire();
}

void UDS_WeaponComponent::EndWeapon()
{
	if (CurrentWeaponSetup.WeaponConfiguration.bAutomatic)
	{
		GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
	}
	
	if (!CurrentWeaponSetup.WeaponConfiguration.bEndedFire)
	{
		return;
	}
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("End FIRe"));
}

void UDS_WeaponComponent::InternalFire()
{
	if ( LastFireTime != 0 && GetWorld()->GetTimeSeconds() - LastFireTime < CurrentWeaponSetup.WeaponConfiguration.FireCoolDown)
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("CD"));
		return;
	}
	
	if (!IsValid(CurrentWeaponSetup.BulletClass) || !GetOwner()->Implements<USD_WeaponFireInterface>())
	{
		return;
	}

	if(ASD_BaseBullet* Bullet = GetWorld()->SpawnActor<ASD_BaseBullet>(CurrentWeaponSetup.BulletClass))
	{
		Bullet->SetActorLocation(ISD_WeaponFireInterface::Execute_GetMuzzleLocation(GetOwner()));
		Bullet->SetActorRotation(ISD_WeaponFireInterface::Execute_GetMuzzleForwardVector(GetOwner()).Rotation());
		
		//TODO TEMPORAL
		
		Bullet->SetOwner(GetOwner());
		Bullet->Fire();
	}
	
	LastFireTime = GetWorld()->GetTimeSeconds();
	
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("FIRE"));
}



