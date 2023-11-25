// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoids_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Boids;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Boids()
	{
		if (!Z_Registration_Info_UPackage__Script_Boids.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Boids",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x8D50EAEC,
				0xC1178E11,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Boids.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Boids.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Boids(Z_Construct_UPackage__Script_Boids, TEXT("/Script/Boids"), Z_Registration_Info_UPackage__Script_Boids, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x8D50EAEC, 0xC1178E11));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
