// Fill out your copyright notice in the Description page of Project Settings.


#include "Dog.h"
#include <Components/WidgetComponent.h>
#include "HealthBar.h"

// Sets default values
ADog::ADog(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* We create a root component so that we can use it as 
	the parent for our health widget which would ensure that the widget
	would stay with the dog even when it moves.
	We first check if a root component has aldready been set. If not
	then we create a scene component and set it as the root component*/
	if (RootComponent == nullptr)
	{
		RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	}

	Health = MaxHealth;

	// Set up the health widget component
	HealthWidgetComp = ObjectInitializer.CreateDefaultSubobject<UWidgetComponent>(this, TEXT("HealthBar"));
	// Attach the health widget to the root component
	HealthWidgetComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();

	// Assign the dog actor object to the health widget's DogOwner variable
	UHealthBar* HealthBar = Cast<UHealthBar>(HealthWidgetComp->GetUserWidgetObject());
	HealthBar->SetOwnerDog(this);
	
}

// Called every frame
void ADog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* Setting random health values to visualize the health updation in health bar*/
	SetHealth(FMath::FRandRange(0.0f, MaxHealth));

}

