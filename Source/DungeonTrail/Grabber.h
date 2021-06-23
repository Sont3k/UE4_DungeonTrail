// Tsuki 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONTRAIL_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 300.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	void FindPhysicsHandle();
	void SetupInputComponent();

	void Grab();
	void ReleaseGrab();

	FHitResult GetFirstPhysicsBodyInReach() const;

	// Return The Line Trace End
	FVector GetPlayerReach() const;
	FVector GetPlayerWorldPosition() const;
};
