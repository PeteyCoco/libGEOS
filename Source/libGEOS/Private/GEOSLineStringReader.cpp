#include "..\Public\GEOSLineStringReader.h"
#include "IncludesGEOS.h"
#include "libGEOS.h"

FGEOSLineStringReader::FGEOSLineStringReader() 
{
	Factory_ = geos::geom::GeometryFactory::create();
	WKTReader_ = geos::io::WKTReader(*Factory_);
}

TArray<FVector> FGEOSLineStringReader::ReadWKT(FString& WKTString)
{
	std::unique_ptr<geos::geom::Geometry> Geom(ConvertToGeometry_(WKTString));
	std::unique_ptr<CoordinateSequence> Coordinates(Geom->getCoordinates());

	TArray<FVector> Result;

	for (int i = 0; i < Coordinates->getSize(); i++) 
	{
		Result.Emplace(FVector(Coordinates->getX(i), Coordinates->getY(i), 0.0f));
	}

	return Result;
}

std::unique_ptr<Geometry> FGEOSLineStringReader::ConvertToGeometry_(FString& WKTString)
{

	return WKTReader_.read(TCHAR_TO_UTF8(*WKTString));

}

