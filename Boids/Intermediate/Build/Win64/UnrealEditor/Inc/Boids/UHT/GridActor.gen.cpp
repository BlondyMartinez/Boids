// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Boids/GridActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridActor() {}
// Cross Module References
	BOIDS_API UClass* Z_Construct_UClass_AGridActor();
	BOIDS_API UClass* Z_Construct_UClass_AGridActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	void AGridActor::StaticRegisterNativesAGridActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGridActor);
	UClass* Z_Construct_UClass_AGridActor_NoRegister()
	{
		return AGridActor::StaticClass();
	}
	struct Z_Construct_UClass_AGridActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GridActor.h" },
		{ "ModuleRelativePath", "GridActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridActor_Statics::ClassParams = {
		&AGridActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridActor_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AGridActor()
	{
		if (!Z_Registration_Info_UClass_AGridActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridActor.OuterSingleton, Z_Construct_UClass_AGridActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGridActor.OuterSingleton;
	}
	template<> BOIDS_API UClass* StaticClass<AGridActor>()
	{
		return AGridActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridActor);
	AGridActor::~AGridActor() {}
	struct Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_GridActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_GridActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGridActor, AGridActor::StaticClass, TEXT("AGridActor"), &Z_Registration_Info_UClass_AGridActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridActor), 1633904382U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_GridActor_h_82639836(TEXT("/Script/Boids"),
		Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_GridActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_GridActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
