// Code Write by JSP


#include "Functions/SD_FunctionLibrary.h"

#include "Core/SD_GameInstance.h"

bool USD_FunctionLibrary::GetWeaponPreset(UObject* WorldContextObject,  FGameplayTag WeaponPreset, FSD_WeaponSetUp& OutWeaponPreset)
{
	if (!WorldContextObject)
	{
		return false;
	}
	
	if (USD_GameInstance* GI = Cast<USD_GameInstance>(WorldContextObject->GetWorld()->GetGameInstance()))
	{
		return GI->GetWeaponSetUp(WeaponPreset, OutWeaponPreset);
	}
	
	return false;
}
		
