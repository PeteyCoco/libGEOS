#pragma once

#include "../Public/GEOSLineStringReader.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FReadFString, "libGEOS.GEOSLineStringReader.Reading WKT FString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

bool FReadFString::RunTest(FString const& Parameters) {

	FGEOSLineStringReader LineStringReader{};
	FString WKTString{ TEXT("LINESTRING(30 10, 10 30, 40 40)") };
	TArray<FVector> LineString = LineStringReader.ReadWKT(WKTString);

	TestEqual("Correct length:", LineString.Num(), 3);

	const auto Tolerance{ KINDA_SMALL_NUMBER };

	TestEqual("Correct value:", LineString[0], FVector(30.f, 10.f, 0.0f), Tolerance);

	return true;
}

#endif