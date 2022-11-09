#pragma once

#include "CoreTypes.h"
#include "IncludesGEOS.h"

class LIBGEOS_API FGEOSLineStringReader
{
public:

	FGEOSLineStringReader();

	/*
	* Parses WKT LineStrings into an array of points
	*/
	TArray<FVector> ReadWKT(const FString& WKTString);

private:
	std::unique_ptr<Geometry> ConvertToGeometry_(const FString& WKTString);

	geos::geom::GeometryFactory::Ptr Factory_{};
	geos::io::WKTReader WKTReader_{};
};