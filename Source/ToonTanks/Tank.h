// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Toon Tanks | Components")
	class UCameraComponent * Camera;

	UPROPERTY(VisibleAnywhere, Category = "Toon Tanks | Components")
	class USpringArmComponent * SpringArm;

	UPROPERTY(EditAnywhere, Category = "Toon Tanks | Components")
	float Speed = 400.f;

	UPROPERTY(EditAnywhere,  Category = "Toon Tanks | Components")
	float TurnRate = 45.f;

	APlayerController * PlayerController;

	void Move(float Value);
	void Turn(float Value);

	
	
};
