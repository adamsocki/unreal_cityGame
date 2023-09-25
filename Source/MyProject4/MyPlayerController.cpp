// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyPawn.h"

#include "GameFramework/CharacterMovementComponent.h"

AMyPlayerController::AMyPlayerController()
{
	isMoveForward = false;
	this->SetActorTickEnabled(true);

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

}


void AMyPlayerController::Tick(float DeltaTime)
{

	//GetPawn()->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	if (ACharacter* MyCharacter = Cast<ACharacter>(GetPawn()))
	{
		MyCharacter->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
	
	FVector NewLocation = GetPawn()->GetActorLocation() + (CurrentVelocity * DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Vel in tick: %f"), CurrentVelocity.Y);
	GetPawn()->SetActorLocation(NewLocation, true);
	CurrentVelocity = FVector::ZeroVector;
	


}

void AMyPlayerController::SetupInputComponent() {

	Super::SetupInputComponent();

	check(InputComponent);

	if (InputComponent != NULL)
	{
		InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
		InputComponent->BindAxis("MoveBackward", this, &AMyPlayerController::MoveForward);
		InputComponent->BindAxis("MoveUp", this, &AMyPlayerController::MoveUp);
		InputComponent->BindAxis("MoveDown", this, &AMyPlayerController::MoveUp);
		InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
		InputComponent->BindAxis("MoveLeft", this, &AMyPlayerController::MoveRight);
	}
}


void AMyPlayerController::MoveForward(float value)
{
	APawn* MyCharacter = GetPawn();
	if (MyCharacter)
	{
		MyCharacter->AddMovementInput(FVector::ForwardVector, value * 1000.0f);
	}
}


void AMyPlayerController::MoveUp(float value)
{

	APawn* MyCharacter = GetPawn();
	if (MyCharacter)
	{

		MyCharacter->AddMovementInput(FVector::UpVector, value*1000.0f);
	}
}



void AMyPlayerController::MoveRight(float value)
{

	APawn* MyCharacter = GetPawn();
	if (MyCharacter)
	{
		MyCharacter->AddMovementInput(FVector::RightVector, value);
	}

}