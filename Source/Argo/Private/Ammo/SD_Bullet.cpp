// Code Write by JSP


#include "Ammo/SD_Bullet.h"

#include "Components/SphereComponent.h"
#include "Interface/SD_Damageable.h"

ASD_Bullet::ASD_Bullet()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(RootComponent);
	
}

void ASD_Bullet::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this,&ASD_Bullet::OnOverlapBegin);
}

void ASD_Bullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->Implements<USD_Damageable>())
	{
		//TODO: this shousl no be destroy shoudl send bak to the pool
		Destroy();
		return;
	}

	FGameplayTag OwnerTeamTag = ISD_Damageable::Execute_GetTeamTag(OtherActor);
	if (!OwnerTeamTag.IsValid() && OwnerTeamTag.MatchesTagExact(TeamTag))
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
		return;
	}

	FSD_DamageDefinitions DamageDefinition;
	DamageDefinition.Damage = 10;
	ISD_Damageable::Execute_ApplyDamage(OtherActor, DamageDefinition);

	Destroy();
}
