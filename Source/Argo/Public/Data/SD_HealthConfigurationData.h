// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Definitions/DamageDefinitions.h"
#include "Engine/DataAsset.h"
#include "SD_HealthConfigurationData.generated.h"

/**
 * 
 */
UCLASS()
class ARGO_API USD_HealthConfigurationData : public UDataAsset
{
	GENERATED_BODY()
	
	
public:
	
protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Health Configuration")
	TMap<FGameplayTag, FSD_HealthConfig> HealthConfiguration;
	
};
