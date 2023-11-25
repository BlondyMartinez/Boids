// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Boids/BoidManagerParameters.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidManagerParameters() {}
// Cross Module References
	BOIDS_API UClass* Z_Construct_UClass_UBoidManagerParameters();
	BOIDS_API UClass* Z_Construct_UClass_UBoidManagerParameters_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	void UBoidManagerParameters::StaticRegisterNativesUBoidManagerParameters()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBoidManagerParameters);
	UClass* Z_Construct_UClass_UBoidManagerParameters_NoRegister()
	{
		return UBoidManagerParameters::StaticClass();
	}
	struct Z_Construct_UClass_UBoidManagerParameters_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_spawnCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_spawnCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_spawnRadius_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_spawnRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_neighbourhoodRadius_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_neighbourhoodRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_separationWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_separationWeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_cohesionWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_cohesionWeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_alignmentWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_alignmentWeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_containmentForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_containmentForce;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBoidManagerParameters_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BoidManagerParameters.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnCount_MetaData[] = {
		{ "Category", "Spawn Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// SPAWN SETTINGS\n" },
#endif
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SPAWN SETTINGS" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnCount = { "spawnCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, spawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnCount_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnRadius_MetaData[] = {
		{ "Category", "Spawn Settings" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnRadius = { "spawnRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, spawnRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnRadius_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "Boid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BOID SETTINGS\n" },
#endif
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BOID SETTINGS" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_speed_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_neighbourhoodRadius_MetaData[] = {
		{ "Category", "Boid Settings" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_neighbourhoodRadius = { "neighbourhoodRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, neighbourhoodRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_neighbourhoodRadius_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_neighbourhoodRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_separationWeight_MetaData[] = {
		{ "Category", "Boid Settings" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_separationWeight = { "separationWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, separationWeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_separationWeight_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_separationWeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_cohesionWeight_MetaData[] = {
		{ "Category", "Boid Settings" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_cohesionWeight = { "cohesionWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, cohesionWeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_cohesionWeight_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_cohesionWeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_alignmentWeight_MetaData[] = {
		{ "Category", "Boid Settings" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_alignmentWeight = { "alignmentWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, alignmentWeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_alignmentWeight_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_alignmentWeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_containmentForce_MetaData[] = {
		{ "Category", "Boid Settings" },
		{ "ModuleRelativePath", "BoidManagerParameters.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_containmentForce = { "containmentForce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoidManagerParameters, containmentForce), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_containmentForce_MetaData), Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_containmentForce_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBoidManagerParameters_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_spawnRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_neighbourhoodRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_separationWeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_cohesionWeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_alignmentWeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoidManagerParameters_Statics::NewProp_containmentForce,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBoidManagerParameters_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBoidManagerParameters>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBoidManagerParameters_Statics::ClassParams = {
		&UBoidManagerParameters::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBoidManagerParameters_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::Class_MetaDataParams), Z_Construct_UClass_UBoidManagerParameters_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBoidManagerParameters_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBoidManagerParameters()
	{
		if (!Z_Registration_Info_UClass_UBoidManagerParameters.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBoidManagerParameters.OuterSingleton, Z_Construct_UClass_UBoidManagerParameters_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBoidManagerParameters.OuterSingleton;
	}
	template<> BOIDS_API UClass* StaticClass<UBoidManagerParameters>()
	{
		return UBoidManagerParameters::StaticClass();
	}
	UBoidManagerParameters::UBoidManagerParameters(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBoidManagerParameters);
	UBoidManagerParameters::~UBoidManagerParameters() {}
	struct Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManagerParameters_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManagerParameters_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBoidManagerParameters, UBoidManagerParameters::StaticClass, TEXT("UBoidManagerParameters"), &Z_Registration_Info_UClass_UBoidManagerParameters, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBoidManagerParameters), 1478929764U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManagerParameters_h_636427116(TEXT("/Script/Boids"),
		Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManagerParameters_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManagerParameters_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
