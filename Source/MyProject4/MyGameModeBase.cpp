// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyCharacter.h"
#include "MyPawn.h"
#include "UObject/ConstructorHelpers.h"

AMyGameModeBase::AMyGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_MyCharacter.BP_MyCharacter_C"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello"));
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO"))
	}
	//DefaultPawnClass = MyBP;

	PlayerControllerClass = AMyPlayerController::StaticClass();
}