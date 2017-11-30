// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef RAPID5_Push_generated_h
#error "Push.generated.h already included, missing '#pragma once' in Push.h"
#endif
#define RAPID5_Push_generated_h

#define Rapid5_Source_Rapid5_Push_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPushBack) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_origin); \
		P_GET_STRUCT(FVector,Z_Param_target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PushBack(Z_Param_origin,Z_Param_target); \
		P_NATIVE_END; \
	}


#define Rapid5_Source_Rapid5_Push_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPushBack) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_origin); \
		P_GET_STRUCT(FVector,Z_Param_target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PushBack(Z_Param_origin,Z_Param_target); \
		P_NATIVE_END; \
	}


#define Rapid5_Source_Rapid5_Push_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPush(); \
	friend RAPID5_API class UClass* Z_Construct_UClass_UPush(); \
public: \
	DECLARE_CLASS(UPush, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Rapid5"), NO_API) \
	DECLARE_SERIALIZER(UPush) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Rapid5_Source_Rapid5_Push_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUPush(); \
	friend RAPID5_API class UClass* Z_Construct_UClass_UPush(); \
public: \
	DECLARE_CLASS(UPush, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Rapid5"), NO_API) \
	DECLARE_SERIALIZER(UPush) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Rapid5_Source_Rapid5_Push_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPush(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPush) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPush); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPush); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPush(UPush&&); \
	NO_API UPush(const UPush&); \
public:


#define Rapid5_Source_Rapid5_Push_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPush(UPush&&); \
	NO_API UPush(const UPush&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPush); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPush); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPush)


#define Rapid5_Source_Rapid5_Push_h_17_PRIVATE_PROPERTY_OFFSET
#define Rapid5_Source_Rapid5_Push_h_14_PROLOG
#define Rapid5_Source_Rapid5_Push_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Rapid5_Source_Rapid5_Push_h_17_PRIVATE_PROPERTY_OFFSET \
	Rapid5_Source_Rapid5_Push_h_17_RPC_WRAPPERS \
	Rapid5_Source_Rapid5_Push_h_17_INCLASS \
	Rapid5_Source_Rapid5_Push_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Rapid5_Source_Rapid5_Push_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Rapid5_Source_Rapid5_Push_h_17_PRIVATE_PROPERTY_OFFSET \
	Rapid5_Source_Rapid5_Push_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Rapid5_Source_Rapid5_Push_h_17_INCLASS_NO_PURE_DECLS \
	Rapid5_Source_Rapid5_Push_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Rapid5_Source_Rapid5_Push_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
