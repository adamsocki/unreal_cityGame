// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT4_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupInputComponent() override;

	bool isMoveForward;

	void MoveForward(float value);
	void MoveBackward(float value);
	void MoveUp(float value);
	void MoveDown(float value);
	void MoveRight(float value);
	void MoveLeft(float value);

	FVector CurrentVelocity;

protected:
	virtual void BeginPlay();

};
