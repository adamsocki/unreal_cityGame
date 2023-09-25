// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//// Set size for collision capsule
	//GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//GetCharacterMovement()->MaxWalkSpeed = 500.f;

	UStaticMeshComponent* myMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	// Load the Cube mesh
	UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;

	// Set the component's mesh
	myMeshComponent->SetStaticMesh(cubeMesh);


	//// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	FollowCamera->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	//TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	
	// Set as root component
	RootComponent = myMeshComponent;

	/*FRotator initRotation =GetActorRotation();
	initRotation.Yaw += 180.f;*/
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);




}



void AMyPawn::MoveForward()
{
	isMoving = true;
}

void AMyPawn::MoveStop()
{
	isMoving = false;
}

