#pragma once

#include "CoreMinimal.h"
#include "Buildables/FGBuildableResourceExtractor.h"
#include "KhaosGeothermalResourceExtractor.generated.h"

/**
 * Resource extractor for geyser nodes.
 */
UCLASS()
class GEOTHERMALSTEAM_API AKhaosGeothermalResourceExtractor : public AFGBuildableResourceExtractor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Extraction")
	FORCEINLINE TSubclassOf<UFGResourceDescriptor> GetActualResourceClass() const { return mActualResourceClass; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Extraction")
	TSubclassOf<UFGResourceDescriptor> mActualResourceClass;
};
