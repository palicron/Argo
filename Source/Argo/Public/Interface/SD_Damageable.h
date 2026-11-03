// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "Definitions/DamageDefinitions.h"
#include "UObject/Interface.h"
#include "SD_Damageable.generated.h"


UINTERFACE(MinimalAPI)
class USD_Damageable : public UInterface
{
	GENERATED_BODY()
};

class ARGO_API ISD_Damageable
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	FSD_DamageResult ApplyDamage(FSD_DamageDefinitions Damage);
};
