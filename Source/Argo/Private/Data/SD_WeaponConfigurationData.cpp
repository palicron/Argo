// Code Write by JSP


#include "Data/SD_WeaponConfigurationData.h"

bool USD_WeaponConfigurationData::GetWeaponSetUp(FGameplayTag WeaponTag, FSD_WeaponSetUp& OutWeaponSetUp) const
{
	if (!WeaponConfigurationMap.Contains(WeaponTag))
	{
		UE_LOG(LogTemp, Error, TEXT("Weapon preset %s not found"), *WeaponTag.ToString());
		return false;
	}
	
	OutWeaponSetUp = WeaponConfigurationMap[WeaponTag];
	return true;
}
