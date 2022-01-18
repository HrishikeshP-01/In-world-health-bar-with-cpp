// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>

void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!OwnerDog.IsValid())
		return;

	Health_Bar->SetPercent(OwnerDog->GetHealth() / OwnerDog->GetMaxHealth());
	
	/* Health & Max health are floats but we want to display them  
	as numbers in the text blocks so we first convert them to int */
	FNumberFormattingOptions Opts;
	Opts.SetMaximumFractionalDigits(0);
	CurrentHealthLabel->SetText(FText::AsNumber(OwnerDog->GetHealth(), &Opts));
	MaxHealthLabel->SetText(FText::AsNumber(OwnerDog->GetMaxHealth(), &Opts));
}
