// Code Write by JSP


#include "Core/SD_GameInstance.h"

#include "Data/SD_WeaponConfigurationData.h"

bool USD_GameInstance::GetWeaponSetUp(FGameplayTag WeaponTag, FSD_WeaponSetUp& OutWeaponSetUp) const
{
	return WeaponConfigurationDataClass->GetWeaponSetUp(WeaponTag, OutWeaponSetUp);
}
