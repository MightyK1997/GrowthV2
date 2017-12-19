// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Mangonel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMangonel() {}
// Cross Module References
	RAPIDPROTOTYPE5_API UClass* Z_Construct_UClass_AMangonel_NoRegister();
	RAPIDPROTOTYPE5_API UClass* Z_Construct_UClass_AMangonel();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_RapidPrototype5();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void AMangonel::StaticRegisterNativesAMangonel()
	{
	}
	UClass* Z_Construct_UClass_AMangonel_NoRegister()
	{
		return AMangonel::StaticClass();
	}
	UClass* Z_Construct_UClass_AMangonel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_RapidPrototype5,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Mangonel.h" },
				{ "ModuleRelativePath", "Mangonel.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_force_MetaData[] = {
				{ "Category", "Mangonel" },
				{ "ModuleRelativePath", "Mangonel.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_force = { UE4CodeGen_Private::EPropertyClass::Float, "force", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AMangonel, force), METADATA_PARAMS(NewProp_force_MetaData, ARRAY_COUNT(NewProp_force_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_pivotActor_MetaData[] = {
				{ "Category", "Mangonel" },
				{ "ModuleRelativePath", "Mangonel.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_pivotActor = { UE4CodeGen_Private::EPropertyClass::Object, "pivotActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AMangonel, pivotActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(NewProp_pivotActor_MetaData, ARRAY_COUNT(NewProp_pivotActor_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_force,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pivotActor,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMangonel>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMangonel::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMangonel, 3826023305);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMangonel(Z_Construct_UClass_AMangonel, &AMangonel::StaticClass, TEXT("/Script/RapidPrototype5"), TEXT("AMangonel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMangonel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
