// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: 
	class ATank *Tank;

	UPROPERTY(EditDefaultsOnly, Category = "Toon Tanks | Components")
	float FireRange = 700.f;

	FTimerHandle FireRateTimerHandle; // this is the timer. As soon as we set it and it's start running
	float FireRate = 2.0f; // we have 2 seconds to wait
	void CheckFireCondition();  // before the t imer results in calling this function
	bool InFireRange();

	
};
