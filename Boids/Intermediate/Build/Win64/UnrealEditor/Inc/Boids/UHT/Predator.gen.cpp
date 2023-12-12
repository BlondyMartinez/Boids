// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Boids/Predator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePredator() {}
// Cross Module References
	BOIDS_API UClass* Z_Construct_UClass_APredator();
	BOIDS_API UClass* Z_Construct_UClass_APredator_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	void APredator::StaticRegisterNativesAPredator()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APredator);
	UClass* Z_Construct_UClass_APredator_NoRegister()
	{
		return APredator::StaticClass();
	}
	struct Z_Construct_UClass_APredator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APredator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APredator_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APredator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Predator.h" },
		{ "ModuleRelativePath", "Predator.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APredator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APredator>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APredator_Statics::ClassParams = {
		&APredator::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APredator_Statics::Class_MetaDataParams), Z_Construct_UClass_APredator_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_APredator()
	{
		if (!Z_Registration_Info_UClass_APredator.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APredator.OuterSingleton, Z_Construct_UClass_APredator_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APredator.OuterSingleton;
	}
	template<> BOIDS_API UClass* StaticClass<APredator>()
	{
		return APredator::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APredator);
	APredator::~APredator() {}
	struct Z_CompiledInDeferFile_FID_Users_s1807857_Documents_GitHub_Boids_Boids_Source_Boids_Predator_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s1807857_Documents_GitHub_Boids_Boids_Source_Boids_Predator_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APredator, APredator::StaticClass, TEXT("APredator"), &Z_Registration_Info_UClass_APredator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APredator), 182669993U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s1807857_Documents_GitHub_Boids_Boids_Source_Boids_Predator_h_3257438327(TEXT("/Script/Boids"),
		Z_CompiledInDeferFile_FID_Users_s1807857_Documents_GitHub_Boids_Boids_Source_Boids_Predator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s1807857_Documents_GitHub_Boids_Boids_Source_Boids_Predator_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
