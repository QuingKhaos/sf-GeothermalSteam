#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resources/FGExtractableResourceInterface.h"
#include "FGSaveInterface.h"
#include "KhaosGeothermalResourceGeyser.generated.h"

class AFGResourceNodeGeyser;

/**
 * Wrapper for geyser nodes to return the given resource.
 */
UCLASS()
class GEOTHERMALSTEAM_API AKhaosGeothermalResourceGeyser : public AActor, public IFGSaveInterface, public IFGExtractableResourceInterface
{
	GENERATED_BODY()

public:
	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;
	virtual void PostUnregisterAllComponents(void) override;
	virtual void PostRegisterAllComponents() override;
	//~ End AActor Interface

	//~ Begin IFGSaveInterface Interface
	virtual bool ShouldSave_Implementation() const override;
	virtual bool NeedTransform_Implementation() override;
	//~ End IFGSaveInterface Interface

	//~ Begin IFGExtractableResourceInterface Interface
	virtual void SetIsOccupied(bool occupied) override;
	virtual bool IsOccupied() const override;
	virtual bool CanBecomeOccupied() const override;
	virtual bool HasAnyResources() const override;
	virtual TSubclassOf<class UFGResourceDescriptor> GetResourceClass() const override;
	virtual bool DoesContainResource(TSubclassOf< class UFGResourceDescriptor > ResourceClass) const;
	virtual int32 ExtractResource(int32 amount) override;
	virtual float GetExtractionSpeedMultiplier() const override;
	virtual FVector GetPlacementLocation(const FVector& hitLocation) const override;
	virtual FRotator GetPlacementRotation(const FVector& hitLocation) const;
	virtual bool CanPlaceResourceExtractor() const override;
	//~ End IFGExtractableResourceInterface Interface

	void SetDecoratedNode(AFGResourceNodeGeyser* DecoratedNode);
	void SetActualResourceClass(TSubclassOf<UFGResourceDescriptor> ResourceClass);

private:
	UPROPERTY(SaveGame)
	AFGResourceNodeGeyser* mDecoratedNode;

	UPROPERTY(SaveGame)
	TSubclassOf<UFGResourceDescriptor> mActualResourceClass;
};
