#include "Holograms/KhaosGeothermalResourceExtractorHologram.h"
#include "Buildables/KhaosGeothermalResourceExtractor.h"
#include "Resources/KhaosGeothermalResourceGeyser.h"
#include "FGResourceNodeGeyser.h"

void AKhaosGeothermalResourceExtractorHologram::ConfigureActor(AFGBuildable* inBuildable) const
{
	AFGResourceNodeGeyser* Geyser = CastChecked<AFGResourceNodeGeyser>(mSnappedExtractableResource.GetObject());
	AKhaosGeothermalResourceExtractor* Extractor = CastChecked<AKhaosGeothermalResourceExtractor>(inBuildable);

	FActorSpawnParameters DecoratorSpawnParameters;
	DecoratorSpawnParameters.Owner = Extractor;
	DecoratorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AKhaosGeothermalResourceGeyser* Decorator = GetWorld()->SpawnActor<AKhaosGeothermalResourceGeyser>(AKhaosGeothermalResourceGeyser::StaticClass(), Geyser->GetActorLocation(), Geyser->GetActorRotation(), DecoratorSpawnParameters);
	Decorator->SetDecoratedNode(Geyser);
	Decorator->SetActualResourceClass(Extractor->GetActualResourceClass());
	Decorator->SetActorHiddenInGame(true);
	Decorator->SetActorEnableCollision(false);
	Decorator->AttachToActor(Extractor, FAttachmentTransformRules::KeepWorldTransform);

	Extractor->SetExtractableResource(Decorator);
}
