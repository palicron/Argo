// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SD_HealthOwner.generated.h"

class USD_HealthComponent;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USD_HealthOwner : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARGO_API ISD_HealthOwner
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category = "Health")
	USD_HealthComponent* GetHealthComponent() const;
	
};
