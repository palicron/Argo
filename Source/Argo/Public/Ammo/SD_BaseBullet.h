// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Interface/SD_PoolableObject.h"
#include "SD_BaseBullet.generated.h"

class UProjectileMovementComponent;

UCLASS()
class ARGO_API ASD_BaseBullet : public AActor, public ISD_PoolableObject
{
	GENERATED_BODY()
	
public:	

	ASD_BaseBullet();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnPoolableObjectTake_Implementation() override;
	
	virtual void OnPoolableObjectReturn_Implementation() override;

	UFUNCTION(blueprintCallable)
	void SetTeamTag(const FGameplayTag NewTeamTag) { TeamTag = NewTeamTag;} ;
	
	UFUNCTION()
	virtual void Fire();
	
protected:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=" Team")
	FGameplayTag TeamTag;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Components | mesh")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Components | Movement")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
	
	virtual void BeginPlay() override;
	




};
