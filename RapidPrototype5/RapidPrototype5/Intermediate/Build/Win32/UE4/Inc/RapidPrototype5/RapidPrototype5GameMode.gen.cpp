// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "RapidPrototype5GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRapidPrototype5GameMode() {}
// Cross Module References
	RAPIDPROTOTYPE5_API UClass* Z_Construct_UClass_ARapidPrototype5GameMode_NoRegister();
	RAPIDPROTOTYPE5_API UClass* Z_Construct_UClass_ARapidPrototype5GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RapidPrototype5();
// End Cross Module References
	void ARapidPrototype5GameMode::StaticRegisterNativesARapidPrototype5GameMode()
	{
	}
	UClass* Z_Construct_UClass_ARapidPrototype5GameMode_NoRegister()
	{
		return ARapidPrototype5GameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ARapidPrototype5GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_RapidPrototype5,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RapidPrototype5GameMode.h" },
				{ "ModuleRelativePath", "RapidPrototype5GameMode.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARapidPrototype5GameMode>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARapidPrototype5GameMode::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00880288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARapidPrototype5GameMode, 2773826265);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARapidPrototype5GameMode(Z_Construct_UClass_ARapidPrototype5GameMode, &ARapidPrototype5GameMode::StaticClass, TEXT("/Script/RapidPrototype5"), TEXT("ARapidPrototype5GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARapidPrototype5GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif