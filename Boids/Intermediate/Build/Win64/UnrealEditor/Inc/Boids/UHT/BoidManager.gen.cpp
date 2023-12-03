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
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	DEFINE_FUNCTION(ABoidManager::execClearObstacles)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearObstacles();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidManager::execRemoveLastObstacle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveLastObstacle();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidManager::execAddObstacle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddObstacle();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidManager::execDeactivateRibbon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeactivateRibbon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidManager::execActivateRibbon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ActivateRibbon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidManager::execHideContainmentSphere)
	{
		P_GET_UBOOL(Z_Param_hide);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HideContainmentSphere(Z_Param_hide);
		P_NATIVE_END;
	}
	void ABoidManager::StaticRegisterNativesABoidManager()
	{
		UClass* Class = ABoidManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActivateRibbon", &ABoidManager::execActivateRibbon },
			{ "AddObstacle", &ABoidManager::execAddObstacle },
			{ "ClearObstacles", &ABoidManager::execClearObstacles },
			{ "DeactivateRibbon", &ABoidManager::execDeactivateRibbon },
			{ "HideContainmentSphere", &ABoidManager::execHideContainmentSphere },
			{ "RemoveLastObstacle", &ABoidManager::execRemoveLastObstacle },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABoidManager_ActivateRibbon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidManager_ActivateRibbon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Boid Behavior" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidManager_ActivateRibbon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidManager, nullptr, "ActivateRibbon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_ActivateRibbon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoidManager_ActivateRibbon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABoidManager_ActivateRibbon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoidManager_ActivateRibbon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidManager_AddObstacle_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidManager_AddObstacle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Simulation Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidManager_AddObstacle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidManager, nullptr, "AddObstacle", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_AddObstacle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoidManager_AddObstacle_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABoidManager_AddObstacle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoidManager_AddObstacle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidManager_ClearObstacles_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidManager_ClearObstacles_Statics::Function_MetaDataParams[] = {
		{ "Category", "Simulation Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidManager_ClearObstacles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidManager, nullptr, "ClearObstacles", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_ClearObstacles_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoidManager_ClearObstacles_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABoidManager_ClearObstacles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoidManager_ClearObstacles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidManager_DeactivateRibbon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidManager_DeactivateRibbon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Boid Behavior" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidManager_DeactivateRibbon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidManager, nullptr, "DeactivateRibbon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_DeactivateRibbon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoidManager_DeactivateRibbon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABoidManager_DeactivateRibbon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoidManager_DeactivateRibbon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics
	{
		struct BoidManager_eventHideContainmentSphere_Parms
		{
			bool hide;
		};
		static void NewProp_hide_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_hide;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::NewProp_hide_SetBit(void* Obj)
	{
		((BoidManager_eventHideContainmentSphere_Parms*)Obj)->hide = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::NewProp_hide = { "hide", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BoidManager_eventHideContainmentSphere_Parms), &Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::NewProp_hide_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::NewProp_hide,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::Function_MetaDataParams[] = {
		{ "Category", "Boid Behavior" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = \"Settings\")\n\x09""class Grid* grid;*/" },
#endif
		{ "ModuleRelativePath", "BoidManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = \"Settings\")\n       class Grid* grid;" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidManager, nullptr, "HideContainmentSphere", nullptr, nullptr, Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::BoidManager_eventHideContainmentSphere_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::BoidManager_eventHideContainmentSphere_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ABoidManager_HideContainmentSphere()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoidManager_HideContainmentSphere_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidManager_RemoveLastObstacle_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidManager_RemoveLastObstacle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Simulation Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidManager_RemoveLastObstacle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidManager, nullptr, "RemoveLastObstacle", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidManager_RemoveLastObstacle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoidManager_RemoveLastObstacle_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABoidManager_RemoveLastObstacle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoidManager_RemoveLastObstacle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoidManager);
	UClass* Z_Construct_UClass_ABoidManager_NoRegister()
	{
		return ABoidManager::StaticClass();
	}
	struct Z_Construct_UClass_ABoidManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_obstacles_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_obstacles_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_obstacles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_parameters_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_parameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_containmentSphereClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_containmentSphereClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_obstacle_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_obstacle;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_materials_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_materials_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_materials;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ribbons_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ribbons_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ribbons;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoidManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoidManager_ActivateRibbon, "ActivateRibbon" }, // 1112136504
		{ &Z_Construct_UFunction_ABoidManager_AddObstacle, "AddObstacle" }, // 3342915981
		{ &Z_Construct_UFunction_ABoidManager_ClearObstacles, "ClearObstacles" }, // 4203223544
		{ &Z_Construct_UFunction_ABoidManager_DeactivateRibbon, "DeactivateRibbon" }, // 2034455755
		{ &Z_Construct_UFunction_ABoidManager_HideContainmentSphere, "HideContainmentSphere" }, // 668160256
		{ &Z_Construct_UFunction_ABoidManager_RemoveLastObstacle, "RemoveLastObstacle" }, // 3556214132
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoidManager.h" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles_Inner = { "obstacles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles = { "obstacles", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, obstacles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles_MetaData) };
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacle_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacle = { "obstacle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, obstacle), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacle_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacle_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_Inner = { "materials", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_materials = { "materials", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, materials), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons_Inner = { "ribbons", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons = { "ribbons", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, ribbons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoidManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_parameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_containmentSphereClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_obstacle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_materials_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_materials,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_ribbons,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoidManager_Statics::ClassParams = {
		&ABoidManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABoidManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_ABoidManager, ABoidManager::StaticClass, TEXT("ABoidManager"), &Z_Registration_Info_UClass_ABoidManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoidManager), 3228484889U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_4014567521(TEXT("/Script/Boids"),
		Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Blondy_Documents_GitHub_CT5108_Boids_Boids_Source_Boids_BoidManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
