// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	void HandleDestruction();


protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Toon Tanks | Components")
	class UCapsuleComponent * CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Toon Tanks | Components")
	UStaticMeshComponent * BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Toon Tanks | Components")
	UStaticMeshComponent * TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Toon Tanks | Components")
	USceneComponent * ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	float RotationSpeed = 5.f;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	class UParticleSystem * DeathParticles;

	UPROPERTY(EditDefaultsOnly, Category = "Toon Tanks | Components")
	TSubclassOf<class AProjectile> ProjectileClass; // this allows us to have a C++ variable that represents a class type. The type can be based on a project 

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	class USoundBase * DeathSound;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	TSubclassOf<class UCameraShakeBase>  DeathCameraShakeClass;};
