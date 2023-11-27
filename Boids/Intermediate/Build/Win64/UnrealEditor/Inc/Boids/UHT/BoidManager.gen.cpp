// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Boids/BoidManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidManager() {}
// Cross Module References
	BOIDS_API UClass* Z_Construct_UClass_ABoidManager();
	BOIDS_API UClass* Z_Construct_UClass_ABoidManager_NoRegister();
	BOIDS_API UClass* Z_Construct_UClass_UBoidManagerParameters_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	void ABoidManager::StaticRegisterNativesABoidManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoidManager);
	UClass* Z_Construct_UClass_ABoidManager_NoRegister()
	{
		return ABoidManager::StaticClass();
	}
	struct Z_Construct_UClass_ABoidManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_parameters_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_parameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_containmentSphereClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_containmentSphereClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_materials_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_materials_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_materials;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoidManager.h" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_parameters_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_parameters = { "parameters", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, parameters), Z_Construct_UClass_UBoidManagerParameters_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_parameters_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_parameters_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_containmentSphereClass_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_containmentSphereClass = { "containmentSphereClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, containmentSphereClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_containmentSphereClass_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_containmentSphereClass_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_Inner = { "materials", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_materials = { "materials", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, materials), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoidManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_parameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_containmentSphereClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_materials,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoidManager_Statics::ClassParams = {
		&ABoidManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABoidManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABoidManager()
	{
		if (!Z_Registration_Info_UClass_ABoidManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoidManager.OuterSingleton, Z_Construct_UClass_ABoidManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoidManager.OuterSingleton;
	}
	template<> BOIDS_API UClass* StaticClass<ABoidManager>()
	{
		return ABoidManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoidManager);
	ABoidManager::~ABoidManager() {}
	struct Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoidManager, ABoidManager::StaticClass, TEXT("ABoidManager"), &Z_Registration_Info_UClass_ABoidManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoidManager), 2382112164U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_561729327(TEXT("/Script/Boids"),
		Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
