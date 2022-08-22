// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Toon Tanks | Components")
	UStaticMeshComponent * ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Toon Tanks | Components")
	class UParticleSystemComponent *ProjectileTrail;

	UPROPERTY(VisibleAnywhere, Category = "Toon Tanks | Components")
	class UProjectileMovementComponent *ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	class UParticleSystem* HitParticles;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	USoundBase * LaunchSound;
	
	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	USoundBase * HitSound;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	TSubclassOf<class UCameraShakeBase>  HitCameraShakeClass;
};
