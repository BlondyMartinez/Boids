// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodetest_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_test;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_test()
	{
		if (!Z_Registration_Info_UPackage__Script_test.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/test",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x7D32989A,
				0x1D6F08D5,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_test.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_test.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_test(Z_Construct_UPackage__Script_test, TEXT("/Script/test"), Z_Registration_Info_UPackage__Script_test, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7D32989A, 0x1D6F08D5));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
