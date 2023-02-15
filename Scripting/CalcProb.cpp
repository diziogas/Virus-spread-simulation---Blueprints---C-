// Fill out your copyright notice in the Description page of Project Settings.

#include <stdlib.h> 
#include "CalcProb.h"


bool UCalcProb::MultiplyFloats(float ChanceOfImmuneGettingInfected, float ChanceofInfectionPerHour, float DeltaSeconds,
	bool IsImmune, bool IsOutside, bool IsWearingMask, bool HasSymptoms, bool OtherMask)
{
	double result=1.;
   
	if (IsImmune) { result = ChanceOfImmuneGettingInfected; }

	if (IsOutside) { result *= 0.5f;  }

	if (IsWearingMask) { result *= 0.3f; }

	if (OtherMask) { result *= 0.3f; }

	if (!HasSymptoms) { result *= 0.42f;  }
	
	result *= ChanceofInfectionPerHour ;
	result *= DeltaSeconds;
	float random = static_cast <float>( rand()) / static_cast <float>(RAND_MAX);
	//UE_LOG(LogTemp, Warning, TEXT("Result =  % f"), result);
	return (result > random*100 );
}


void UCalcProb::UpdateCounters(int HealthyCounter, int VaccinatedCounter, int ImmuneCounter, int VaccunatedSum, int &HCounter, int &VacCounter, int &ICounter, int &VacSum ) {

	HCounter= HealthyCounter - VaccinatedCounter;
	ICounter = ImmuneCounter + VaccinatedCounter;
	VacSum = VaccunatedSum + VaccinatedCounter;

	
}