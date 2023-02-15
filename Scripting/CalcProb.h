// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CalcProb.generated.h"

/**
 * 
 */
UCLASS()
class DIPLOMATIKI_2_API UCalcProb : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	UFUNCTION(BlueprintPure, Category = "MyMath")
	static bool MultiplyFloats(float ChanceOfImmuneGettingInfected, float ChanceofInfectionPerHour, float DeltaSeconds,
		bool IsImmune, bool IsOutside, bool IsWearingMask, bool HasSymptoms, bool OtherMask);

	UFUNCTION(BlueprintCallable, Category = "MyMath")
		static void UpdateCounters(int HealthyCounter, int VaccinatedCounter, int ImmuneCounter, int VaccunatedSum, int& HCounter, int& VacCounter, int& ICounter, int& VacSum);
};
