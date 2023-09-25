// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT4_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	AMyGameModeBase();
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = BPClasses)
	UClass* MyBP;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SomeMesh;

};
