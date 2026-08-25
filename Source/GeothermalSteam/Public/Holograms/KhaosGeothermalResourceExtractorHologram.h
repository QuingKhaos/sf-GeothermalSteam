#pragma once

#include "CoreMinimal.h"
#include "Hologram/FGGeoThermalGeneratorHologram.h"
#include "KhaosGeothermalResourceExtractorHologram.generated.h"

/**
 * Hologram for Geothermal Resource Extractor, which can only be placed (snapped) on geyser resource nodes.
 */
UCLASS()
class GEOTHERMALSTEAM_API AKhaosGeothermalResourceExtractorHologram : public AFGGeoThermalGeneratorHologram
{
	GENERATED_BODY()

protected:
	// Begin AFGBuildableHologram Interface
	virtual void ConfigureActor(AFGBuildable* inBuildable) const override;
	// End AFGBuildableHologram Interface
};
