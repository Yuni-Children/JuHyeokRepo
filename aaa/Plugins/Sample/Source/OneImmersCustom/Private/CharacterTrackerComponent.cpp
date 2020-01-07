// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterTrackerComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/Engine.h"

#include "OneImmersCustom.h"

#include "IXRTrackingSystem.h"
#include "IXRCamera.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"



const FName UCharacterTrackerComponent::SocketName(TEXT("CameraTip"));


// Sets default values for this component's properties
UCharacterTrackerComponent::UCharacterTrackerComponent() : EyeHeight(160.0f), Wingspan(170.0f), EyeOffset(0.0f), BodyOffset(0.0f), EyeHeightExtension(20.0f), LockHeight(true), bQuantizedReplication(true)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bTickEvenWhenPaused = true;

	bReplicates = true;

	PrimaryComponentTick.TickGroup = TG_PrePhysics;
}


// Called when the game starts
void UCharacterTrackerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCharacterTrackerComponent::AutonomousConsumeXRCameraTranslation(ACharacter* CharacterOwner)
{
	FVector tmp = GetOwner()->GetRootComponent()->GetComponentTransform().Rotator().RotateVector(DeltaLoc);

	FVector test1 = GetOwner()->GetActorLocation();


	UCharacterMovementComponent* MovementComp = CharacterOwner ? CharacterOwner->GetCharacterMovement() : nullptr;
	if (MovementComp && MovementComp->UpdatedComponent)
	{
		//USkeletalMeshComponent* BodyMesh = PawnOwner->FindComponentByClass<USkeletalMeshComponent>();
		//const FScopedPreventAttachedComponentMove PreventMeshMove(BodyMesh);
		MovementComp->MoveUpdatedComponent(tmp, MovementComp->UpdatedComponent->GetComponentQuat(), false, nullptr, ETeleportType::TeleportPhysics);
		MovementComp->ApplyWorldOffset(tmp, true);
	}
	else
	{
		GetOwner()->AddActorWorldOffset(tmp, false, nullptr, ETeleportType::TeleportPhysics);
	}

	//FVector test2 = GetOwner()->GetActorLocation();
	//UE_LOG(LogOneImmersCustom, Verbose, TEXT("Delta length %3.2f, %3.2f, %3.2f"), tmp.Size(), (test2 - test1).Size(), (TestPrev - test1).Size());
	//UE_LOG(LogOneImmersCustom, Verbose, TEXT("cached pos %s : prev pos %s : next pos %s"), *TestPrev.ToString(), *test1.ToString(), *test2.ToString());
	//TestPrev = test2;
	DeltaLoc = FVector::ZeroVector;
}

// Called every frame
void UCharacterTrackerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	ACharacter* CharacterOwner = Cast<ACharacter>(GetOwner());
	USkeletalMeshComponent* BodyMesh = nullptr;

	if (CharacterOwner)
	{
		BodyMesh = CharacterOwner->FindComponentByClass<USkeletalMeshComponent>();
	}

	{
		const FScopedPreventAttachedComponentMove PreventMeshMove(BodyMesh);

		if (IsNetMode(NM_Standalone) || ((IsNetMode(NM_Client) || IsNetMode(NM_ListenServer)) && GetOwner()->Role == ROLE_AutonomousProxy))
		{
			if (GEngine && GEngine->XRSystem.IsValid() && GetWorld() && GetWorld()->WorldType != EWorldType::Editor)
			{
				IXRTrackingSystem* XRSystem = GEngine->XRSystem.Get();
				auto XRCamera = XRSystem->GetXRCamera();

				if (XRCamera.IsValid())
				{
					if (XRSystem->IsHeadTrackingAllowed())
					{
						FQuat Orientation;
						FVector Position;
						if (XRCamera->UpdatePlayerCamera(Orientation, Position))
						{
							AutonomousSetHeadTransform(FTransform(Orientation, Position));
						}
					}
				}
			}

			{
				//const FScopedPreventAttachedComponentMove PreventParentMove(GetAttachParent()? GetAttachParent():this);

				AutonomousConsumeXRCameraTranslation(CharacterOwner);
			}

			if (IsNetMode(NM_Client))
			{
				// TODO: optimization : infrequent update
				if (bQuantizedReplication)
				{
					FRotator HeadRot = HeadTrackerTransform.Rotator().GetNormalized();
					FRotator LeftRot = LeftTrackerTransform.Rotator().GetNormalized();
					FRotator RightRot = RightTrackerTransform.Rotator().GetNormalized();

					FVector_NetQuantizeNormal HeadRotCompressed(HeadRot.Pitch / 180.f, HeadRot.Yaw / 180.f, HeadRot.Roll / 180.f);
					FVector_NetQuantizeNormal LeftRotCompressed(LeftRot.Pitch / 180.f, LeftRot.Yaw / 180.f, LeftRot.Roll / 180.f);
					FVector_NetQuantizeNormal RightRotCompressed(RightRot.Pitch / 180.f, RightRot.Yaw / 180.f, RightRot.Roll / 180.f);

					ServerFastSyncTransforms(FVector_NetQuantize10(GetOwner()->GetRootComponent()->GetComponentLocation()), FVector_NetQuantize10(HeadTrackerTransform.GetLocation()), HeadRotCompressed, FVector_NetQuantize10(LeftTrackerTransform.GetLocation()), LeftRotCompressed, FVector_NetQuantize10(RightTrackerTransform.GetLocation()), RightRotCompressed);
				}
				else
				{
					ServerSyncTransforms(GetOwner()->GetRootComponent()->GetComponentLocation(), HeadTrackerTransform, LeftTrackerTransform, RightTrackerTransform);

				}
			}

		}

		FVector tmp = GetAttachParent()->RelativeLocation;
		FVector vecDevicePos = HeadTrackerTransform.GetLocation();
		float	ZOffset = 0.f;

		if (GetAttachParent() != nullptr)
		{
			//const FScopedPreventAttachedComponentMove PreventThisMove(this);

			{
				tmp.Z = LockHeight ? tmp.Z : FMath::Min(HeadTrackerTransform.GetTranslation().Z - EyeHeight + EyeOffset + BodyOffset, EyeHeightExtension);
				GetAttachParent()->SetRelativeLocationAndRotation(tmp, bManualCameraControl ? GetAttachParent()->RelativeRotation : GetBodyRotation(), false, nullptr, ETeleportType::TeleportPhysics);
			}
		}

		//SetRelativeRotation(GetHeadRotation(), false, nullptr, ETeleportType::TeleportPhysics);
		SetRelativeLocationAndRotation(LockHeight?RelativeLocation:FVector(RelativeLocation.X, RelativeLocation.Y, EyeHeight), bManualCameraControl?GetBodyRotation():FRotator::ZeroRotator, false, nullptr, ETeleportType::TeleportPhysics);
	}

	if (BodyMesh)
	{
		USceneComponent* Parent = BodyMesh->GetAttachParent();
		if (Parent)
		{
			FTransform DesiredTransform = FTransform(CharacterOwner->GetBaseRotationOffset(), CharacterOwner->GetBaseTranslationOffset()) * Parent->GetSocketTransform(BodyMesh->GetAttachSocketName());

			const FVector DesiredDelta = FTransform::SubtractTranslations(DesiredTransform, BodyMesh->GetComponentTransform());

			BodyMesh->MoveComponent(DesiredDelta, DesiredTransform.GetRotation(), false, nullptr, MOVECOMP_SkipPhysicsMove, ETeleportType::TeleportPhysics);
		}
	}

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCharacterTrackerComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UCharacterTrackerComponent, HeadTrackerTransform, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(UCharacterTrackerComponent, LeftTrackerTransform, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(UCharacterTrackerComponent, RightTrackerTransform, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(UCharacterTrackerComponent, GhostMode, COND_SimulatedOnly);
	DOREPLIFETIME(UCharacterTrackerComponent, Wingspan);
	DOREPLIFETIME(UCharacterTrackerComponent, EyeHeight);
	DOREPLIFETIME(UCharacterTrackerComponent, EyeOffset);
	DOREPLIFETIME(UCharacterTrackerComponent, BodyOffset);
}


const FTransform UCharacterTrackerComponent::GetHeadWorldTransform() const
{
	return GetSocketTransform(SocketName);
}

const FTransform UCharacterTrackerComponent::GetTrackerWorldTransform(const FTransform& InTrans) const
{
	return InTrans * HeadTrackerTransform.Inverse() * GetHeadWorldTransform();
}

const FTransform UCharacterTrackerComponent::GetLeftWorldTransform() const
{
	return GetTrackerWorldTransform(LeftTrackerTransform);
}

const FTransform UCharacterTrackerComponent::GetRightWorldTransform() const
{
	return GetTrackerWorldTransform(RightTrackerTransform);
}

const FRotator UCharacterTrackerComponent::GetBodyRotation() const
{
	return FRotator(0, HeadTrackerTransform.Rotator().Yaw, 0);
}

const FRotator UCharacterTrackerComponent::GetHeadRotation() const
{
	return FRotator(HeadTrackerTransform.Rotator().Pitch, 0, HeadTrackerTransform.Rotator().Roll);
}

const FTransform UCharacterTrackerComponent::GetNeckTransform() const
{
	return GetRelativeTransform().Inverse() * FTransform(GetBodyRotation(), HeadTrackerTransform.GetTranslation());
}

void UCharacterTrackerComponent::AutonomousSetHeadTransform(const FTransform& InTrans)
{
	LocalSetHeadTransform(InTrans);

	FTransform tmp = GetNeckTransform();
	DeltaLoc += FVector::VectorPlaneProject(tmp.GetTranslation() - PrevNeckTrans.GetTranslation(), FVector::UpVector);
	PrevNeckTrans = tmp;
}

void UCharacterTrackerComponent::AutonomousSetLeftTransform(const FTransform& InTrans, const bool WorldSpace)
{
	FTransform tmp = WorldSpace ? InTrans * GetHeadWorldTransform().Inverse() * HeadTrackerTransform : InTrans;
	LocalSetLeftTransform(tmp);
}

void UCharacterTrackerComponent::AutonomousSetRightTransform(const FTransform& InTrans, const bool WorldSpace)
{
	FTransform tmp = WorldSpace ? InTrans * GetHeadWorldTransform().Inverse() * HeadTrackerTransform : InTrans;
	LocalSetRightTransform(tmp);
}

void UCharacterTrackerComponent::AutonomousSetHandTransforms(const FTransform& InLeft, const bool IsLeftWorldSpace, const FTransform& InRight, const bool IsRightWorldSpace)
{
	FTransform tmpLeft = IsLeftWorldSpace ? InLeft * GetHeadWorldTransform().Inverse() * HeadTrackerTransform : InLeft;
	LocalSetLeftTransform(tmpLeft);

	FTransform tmpRight = IsRightWorldSpace ? InRight * GetHeadWorldTransform().Inverse() * HeadTrackerTransform : InRight;
	LocalSetRightTransform(tmpRight);
}

void UCharacterTrackerComponent::AutonomousSetTransforms(const FTransform& InHead, const FTransform& InLeft, const FTransform& InRight, const bool WorldSpace)
{
	LocalSetHeadTransform(InHead);

	FTransform tmp = GetNeckTransform();
	DeltaLoc += FVector::VectorPlaneProject(tmp.GetTranslation() - PrevNeckTrans.GetTranslation(), FVector::UpVector);
	PrevNeckTrans = tmp;

	FTransform tmpLeft = WorldSpace ? InLeft * GetHeadWorldTransform().Inverse() * HeadTrackerTransform : InLeft;
	LocalSetLeftTransform(tmpLeft);

	FTransform tmpRight = WorldSpace ? InRight * GetHeadWorldTransform().Inverse() * HeadTrackerTransform : InRight;
	LocalSetRightTransform(tmpRight);
}

void UCharacterTrackerComponent::ServerFastSyncTransforms_Implementation(const FVector_NetQuantize10 & InLoc, const FVector_NetQuantize10 & InHeadPos, const FVector_NetQuantizeNormal & InHeadRot, const FVector_NetQuantize10 & InLeftPos, const FVector_NetQuantizeNormal & InLeftRot, const FVector_NetQuantize10 & InRightPos, const FVector_NetQuantizeNormal & InRightRot)
{
	GetOwner()->SetActorLocation(InLoc, false, nullptr, ETeleportType::TeleportPhysics);

	LocalSetHeadTransform(FTransform(FRotator(InHeadRot.X * 180.f, InHeadRot.Y * 180.f, InHeadRot.Z * 180.f), InHeadPos));
	LocalSetLeftTransform(FTransform(FRotator(InLeftRot.X * 180.f, InLeftRot.Y * 180.f, InLeftRot.Z * 180.f), InLeftPos));
	LocalSetRightTransform(FTransform(FRotator(InRightRot.X * 180.f, InRightRot.Y * 180.f, InRightRot.Z * 180.f), InRightPos));
}

bool UCharacterTrackerComponent::ServerFastSyncTransforms_Validate(const FVector_NetQuantize10 & InLoc, const FVector_NetQuantize10 & InHeadPos, const FVector_NetQuantizeNormal & InHeadRot, const FVector_NetQuantize10 & InLeftPos, const FVector_NetQuantizeNormal & InLeftRot, const FVector_NetQuantize10 & InRightPos, const FVector_NetQuantizeNormal & InRightRot)
{
	return true;
}

void UCharacterTrackerComponent::ServerSyncTransforms_Implementation(const FVector & InLoc, const FTransform& InHead, const FTransform& InLeft, const FTransform& InRight)
{
	GetOwner()->SetActorLocation(InLoc, false, nullptr, ETeleportType::TeleportPhysics);

	LocalSetHeadTransform(InHead);
	LocalSetLeftTransform(InLeft);
	LocalSetRightTransform(InRight);
}

bool UCharacterTrackerComponent::ServerSyncTransforms_Validate(const FVector & InLoc, const FTransform& InHead, const FTransform& InLeft, const FTransform& InRight)
{
	return true;
}

void UCharacterTrackerComponent::LocalSetHeadTransform(const FTransform& InTrans)
{
	HeadTrackerTransform = InTrans;
}
void UCharacterTrackerComponent::LocalSetLeftTransform(const FTransform& InTrans)
{
	LeftTrackerTransform = InTrans;
}
void UCharacterTrackerComponent::LocalSetRightTransform(const FTransform& InTrans)
{
	RightTrackerTransform = InTrans;
}

void UCharacterTrackerComponent::AutonomousSetGhostMode(const bool InGhostMode)
{
	GhostMode = InGhostMode;
	OnRep_GhostMode(InGhostMode);
	if (IsNetMode(NM_Client))
	{
		ServerSetGhostMode(GhostMode);
	}
}

void UCharacterTrackerComponent::OnRep_GhostMode(bool InGhostMode)
{
	// UpdateGhostMode();
	OnGhostModeChanged.Broadcast(GhostMode);
}

void UCharacterTrackerComponent::UpdateGhostMode()
{
	if (CollisionComponent)
	{
		CollisionComponent->SetCollisionResponseToChannel(ECC_WorldStatic, GhostMode? ECollisionResponse::ECR_Ignore :ECollisionResponse::ECR_Block);
		CollisionComponent->SetEnableGravity(!GhostMode);
	}
}

void UCharacterTrackerComponent::ServerSetGhostMode_Implementation(bool InGhostMode)
{
	GhostMode = InGhostMode;
	OnRep_GhostMode(GhostMode);
}

bool UCharacterTrackerComponent::ServerSetGhostMode_Validate(bool InGhostMode)
{
	return true;
}

void UCharacterTrackerComponent::AutonomousSetBrakingMode(const bool InBrakingMode)
{
	BrakingMode = InBrakingMode;
	OnRep_BrakingMode(InBrakingMode);
	if (IsNetMode(NM_Client))
	{
		ServerSetBrakingMode(BrakingMode);
	}
}

void UCharacterTrackerComponent::OnRep_BrakingMode(bool InBrakingMode)
{
	OnBrakingModeChanged.Broadcast(BrakingMode);
}

void UCharacterTrackerComponent::ServerSetBrakingMode_Implementation(bool InBrakingMode)
{
	BrakingMode = InBrakingMode;
}

bool UCharacterTrackerComponent::ServerSetBrakingMode_Validate(bool InBrakingMode)
{
	return true;
}

void UCharacterTrackerComponent::ServerSetWingSpan_Implementation(const float InWingSpan)
{
	Wingspan = InWingSpan;
}

bool UCharacterTrackerComponent::ServerSetWingSpan_Validate(const float InWingSpan)
{
	return true;
}

void UCharacterTrackerComponent::ServerSetEyeHeight_Implementation(const float InEyeHeight)
{
	EyeHeight = InEyeHeight;
}

bool UCharacterTrackerComponent::ServerSetEyeHeight_Validate(const float InEyeHeight)
{
	return true;
}

void UCharacterTrackerComponent::ServerSetEyeOffset_Implementation(const float InEyeOffset)
{
	EyeOffset = InEyeOffset;
}

bool UCharacterTrackerComponent::ServerSetEyeOffset_Validate(const float InEyeOffset)
{
	return true;
}

void UCharacterTrackerComponent::ServerSetBodyOffset_Implementation(const float InBodyOffset)
{
	BodyOffset = InBodyOffset;
}

bool UCharacterTrackerComponent::ServerSetBodyOffset_Validate(const float InBodyOffset)
{
	return true;
}

void UCharacterTrackerComponent::AddDeltaLoc(const FVector& InDeltaLoc)
{
	DeltaLoc += InDeltaLoc;
}

void UCharacterTrackerComponent::AutonomousMoveOwnerActor()
{
	
}

void UCharacterTrackerComponent::AutonomousSetOwnerVelocity(const FVector & InVel, const bool bAddToCurrent)
{
	if (CollisionComponent)
	{
		CollisionComponent->SetPhysicsLinearVelocity(InVel, bAddToCurrent);
		if (IsNetMode(NM_Client))
			ServerSetOwnerVelocity(InVel, bAddToCurrent);
	}
}

void UCharacterTrackerComponent::ServerSetOwnerVelocity_Implementation(const FVector & InVel, const bool bAddToCurrent)
{
	if (CollisionComponent)
	{
		CollisionComponent->SetPhysicsLinearVelocity(InVel, bAddToCurrent);
	}
}

bool UCharacterTrackerComponent::ServerSetOwnerVelocity_Validate(const FVector & InVel, const bool bAddToCurrent)
{
	return true;
}

void UCharacterTrackerComponent::UpdateRelatedTransforms(const float Delta)
{

}

FTransform UCharacterTrackerComponent::GetSocketTransform(FName InSocketName, ERelativeTransformSpace TransformSpace) const
{
	if (InSocketName == SocketName)
	{
		FTransform RelativeTransform(GetHeadRotation(), FVector::ZeroVector);
		if (bManualCameraControl)
		{
			if (!bPrevManual)
			{
				PivotLocForManual = HeadTrackerTransform.GetLocation();
			}
			RelativeTransform = FTransform(HeadTrackerTransform.Rotator(), HeadTrackerTransform.GetLocation() - PivotLocForManual) * ManualCameraTransform.GetRelativeTransform(GetComponentTransform());
		}

		bPrevManual = bManualCameraControl;
		
		switch (TransformSpace)
		{
		case RTS_World:
		{
			return RelativeTransform * GetComponentTransform();
			break;
		}
		case RTS_Actor:
		{
			if (const AActor* Actor = GetOwner())
			{
				FTransform SocketTransform = RelativeTransform * GetComponentTransform();
				return SocketTransform.GetRelativeTransform(Actor->GetTransform());
			}
			break;
		}
		case RTS_Component:
		{
			return RelativeTransform;
		}
		}
		return RelativeTransform;
	}

	return Super::GetSocketTransform(InSocketName, TransformSpace);
}

bool UCharacterTrackerComponent::HasAnySockets() const
{
	return true;
}

void UCharacterTrackerComponent::QuerySupportedSockets(TArray<FComponentSocketDescription>& OutSockets) const
{
	new (OutSockets) FComponentSocketDescription(SocketName, EComponentSocketType::Socket);
}
