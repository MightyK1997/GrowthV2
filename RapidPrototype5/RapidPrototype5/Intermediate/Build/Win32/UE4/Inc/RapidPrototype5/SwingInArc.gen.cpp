// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "SwingInArc.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSwingInArc() {}
// Cross Module References
	RAPIDPROTOTYPE5_API UClass* Z_Construct_UClass_USwingInArc_NoRegister();
	RAPIDPROTOTYPE5_API UClass* Z_Construct_UClass_USwingInArc();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RapidPrototype5();
// End Cross Module References
	void USwingInArc::StaticRegisterNativesUSwingInArc()
	{
	}
	UClass* Z_Construct_UClass_USwingInArc_NoRegister()
	{
		return USwingInArc::StaticClass();
	}
	UClass* Z_Construct_UClass_USwingInArc()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RapidPrototype5,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "IncludePath", "SwingInArc.h" },
				{ "ModuleRelativePath", "SwingInArc.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<USwingInArc>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&USwingInArc::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
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
	IMPLEMENT_CLASS(USwingInArc, 1571092007);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USwingInArc(Z_Construct_UClass_USwingInArc, &USwingInArc::StaticClass, TEXT("/Script/RapidPrototype5"), TEXT("USwingInArc"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USwingInArc);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
