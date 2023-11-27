// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Boids/Boid.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoid() {}
// Cross Module References
	BOIDS_API UClass* Z_Construct_UClass_ABoid();
	BOIDS_API UClass* Z_Construct_UClass_ABoid_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	void ABoid::StaticRegisterNativesABoid()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoid);
	UClass* Z_Construct_UClass_ABoid_NoRegister()
	{
		return ABoid::StaticClass();
	}
	struct Z_Construct_UClass_ABoid_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Boid.h" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::NewProp_mesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_mesh = { "mesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoid, mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::NewProp_mesh_MetaData), Z_Construct_UClass_ABoid_Statics::NewProp_mesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoid>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoid_Statics::ClassParams = {
		&ABoid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABoid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABoid()
	{
		if (!Z_Registration_Info_UClass_ABoid.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoid.OuterSingleton, Z_Construct_UClass_ABoid_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoid.OuterSingleton;
	}
	template<> BOIDS_API UClass* StaticClass<ABoid>()
	{
		return ABoid::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoid);
	ABoid::~ABoid() {}
	struct Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_Boid_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_Boid_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoid, ABoid::StaticClass, TEXT("ABoid"), &Z_Registration_Info_UClass_ABoid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoid), 4090110418U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_Boid_h_2312946232(TEXT("/Script/Boids"),
		Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_Boid_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_Boid_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
