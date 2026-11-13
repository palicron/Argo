// Code Write by JSP

#pragma once

#include "CoreMinimal.h"
#include "Ammo/SD_BaseBullet.h"
#include "SD_Bullet.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class ARGO_API ASD_Bullet : public ASD_BaseBullet
{
	GENERATED_BODY()
	
	
public:
	
	ASD_Bullet();
	
	
	
protected:
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Collision")
	TObjectPtr<USphereComponent> CollisionComponent;
	
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
};
