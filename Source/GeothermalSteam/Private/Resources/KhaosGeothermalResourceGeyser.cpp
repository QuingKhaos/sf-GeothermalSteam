#include "Resources/KhaosGeothermalResourceGeyser.h"
#include "FGResourceNodeGeyser.h"

void AKhaosGeothermalResourceGeyser::SetDecoratedNode(AFGResourceNodeGeyser* DecoratedNode)
{
	mDecoratedNode = DecoratedNode;
}

void AKhaosGeothermalResourceGeyser::SetActualResourceClass(TSubclassOf<UFGResourceDescriptor> ResourceClass)
{
	mActualResourceClass = ResourceClass;
}

//~ Begin AActor Interface
void AKhaosGeothermalResourceGeyser::BeginPlay()
{
	if (mDecoratedNode) {
		mDecoratedNode->BeginPlay();
	}
}

void AKhaosGeothermalResourceGeyser::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	if (mDecoratedNode) {
		mDecoratedNode->EndPlay(endPlayReason);
	}
}

void AKhaosGeothermalResourceGeyser::PostUnregisterAllComponents(void)
{
	if (mDecoratedNode) {
		mDecoratedNode->PostUnregisterAllComponents();
	}
}

void AKhaosGeothermalResourceGeyser::PostRegisterAllComponents()
{
	if (mDecoratedNode) {
		mDecoratedNode->PostRegisterAllComponents();
	}
}
//~ End AActor Interface

//~ Begin IFGSaveInterface Interface
bool AKhaosGeothermalResourceGeyser::ShouldSave_Implementation() const
{
	return true;
}

bool AKhaosGeothermalResourceGeyser::NeedTransform_Implementation()
{
	return true;
}
//~ End IFGSaveInterface Interface

//~ Begin IFGExtractableResourceInterface Interface
void AKhaosGeothermalResourceGeyser::SetIsOccupied(bool occupied)
{
	mDecoratedNode->SetIsOccupied(occupied);
}

bool AKhaosGeothermalResourceGeyser::IsOccupied() const
{
	return mDecoratedNode->IsOccupied();
}

bool AKhaosGeothermalResourceGeyser::CanBecomeOccupied() const
{
	return mDecoratedNode->CanBecomeOccupied();
}

bool AKhaosGeothermalResourceGeyser::HasAnyResources() const
{
	return mDecoratedNode->HasAnyResources();
}

TSubclassOf<class UFGResourceDescriptor> AKhaosGeothermalResourceGeyser::GetResourceClass() const
{
	return mActualResourceClass;
}

bool AKhaosGeothermalResourceGeyser::DoesContainResource(TSubclassOf<class UFGResourceDescriptor> ResourceClass) const
{
	return mDecoratedNode->DoesContainResource(ResourceClass);
}

int32 AKhaosGeothermalResourceGeyser::ExtractResource(int32 amount)
{
	return mDecoratedNode->ExtractResource(amount);
}

float AKhaosGeothermalResourceGeyser::GetExtractionSpeedMultiplier() const
{
	return mDecoratedNode->GetExtractionSpeedMultiplier();
}

FVector AKhaosGeothermalResourceGeyser::GetPlacementLocation(const FVector& hitLocation) const
{
	return mDecoratedNode->GetPlacementLocation(hitLocation);
}

FRotator AKhaosGeothermalResourceGeyser::GetPlacementRotation(const FVector& hitLocation) const
{
	return mDecoratedNode->GetPlacementRotation(hitLocation);
}

bool AKhaosGeothermalResourceGeyser::CanPlaceResourceExtractor() const
{
	return mDecoratedNode->CanPlaceResourceExtractor();
}
//~ End IFGExtractableResourceInterface Interface
