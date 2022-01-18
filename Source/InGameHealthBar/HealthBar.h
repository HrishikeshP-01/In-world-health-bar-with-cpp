// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Dog.h"
#include "HealthBar.generated.h"

/**
 * Making the class abstract ensures that you wont accidentaly
 * pick them from the drop-down list while chosing user widgets in the viewport
 * as abstract classes can't be instantiated but only be subclassed.
 * It is used to provide a common, implemented functionality among all 
 * implementations of the component.
 */
UCLASS(Abstract)
class INGAMEHEALTHBAR_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
		// Fn to set the dog object ptr. Make it public to be able to access it from the dog class
		void SetOwnerDog(ADog* InDog) { OwnerDog = InDog; };
	
protected:
	// tick fn to get updated health values
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// We use a weak object ptr for the dog actor that owns the widget
	/*Instead of using UPROPERTY ptr, we use a weak object ptr so that 
	the widget wont have a UPROPERTY's pointer to the dog actor
	The dog is the owner of the health bar widget and if the health bar
	widget has a pointer back to the dog then a circular dependency will arise
	which isn't a good programming practice.
	The priorty is given to the dog actor so the widget has a weak obj ptr*/
	TWeakObjectPtr<ADog> OwnerDog;
	// Bind these widgets to the pointers of the same name
	UPROPERTY(meta = ( BindWidget ))
		class UProgressBar* Health_Bar;
	UPROPERTY(meta = ( BindWidget ))
		class UTextBlock* CurrentHealthLabel;
	UPROPERTY(meta = ( BindWidget ))
		class UTextBlock* MaxHealthLabel;
};
