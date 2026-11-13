// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SD_PoolableObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USD_PoolableObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARGO_API ISD_PoolableObject
{
	GENERATED_BODY()


public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void OnPoolableObjectTake();
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void OnPoolableObjectReturn();
	
	
};
