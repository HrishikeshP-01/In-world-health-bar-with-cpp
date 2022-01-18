// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dog.generated.h"

UCLASS()
class INGAMEHEALTHBAR_API ADog : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	/* We change the constructor to this in order to be able to 
	intitialize the health widget component withing the code*/
	ADog(const FObjectInitializer& ObjectInitializer);

	// const makes sure that Health can't be modified
	float GetHealth() const { return Health; };
	float GetMaxHealth() const { return MaxHealth; };

	void SetHealth(float val) { Health = val; };
	void SetMaxHealth(float val) { MaxHealth = val; };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float Health;
	float MaxHealth = 100;

	/*We set it to VisibleAnywhere in order to be able to 
	edit its properties*/
	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* HealthWidgetComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
