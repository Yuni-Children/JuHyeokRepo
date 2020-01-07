// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FTransform;
struct FVector;
#ifdef ONEIMMERSCUSTOM_MCTrackComponent_generated_h
#error "MCTrackComponent.generated.h already included, missing '#pragma once' in MCTrackComponent.h"
#endif
#define ONEIMMERSCUSTOM_MCTrackComponent_generated_h

#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFixInWorldSpace) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_InTrans); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FixInWorldSpace(Z_Param_Out_InTrans); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTrackerTransform) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_OutTrans); \
		P_GET_UBOOL_REF(Z_Param_Out_IsFixed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetTrackerTransform(Z_Param_Out_OutTrans,Z_Param_Out_IsFixed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAnchorLoc) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetAnchorLoc(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAvgVelocity) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetAvgVelocity(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetrieveDeltaLoc) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_DeltaLoc); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RetrieveDeltaLoc(Z_Param_Out_DeltaLoc); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRelease) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Release(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGrab) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Grab(); \
		P_NATIVE_END; \
	}


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFixInWorldSpace) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_InTrans); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FixInWorldSpace(Z_Param_Out_InTrans); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTrackerTransform) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_OutTrans); \
		P_GET_UBOOL_REF(Z_Param_Out_IsFixed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetTrackerTransform(Z_Param_Out_OutTrans,Z_Param_Out_IsFixed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAnchorLoc) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetAnchorLoc(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAvgVelocity) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetAvgVelocity(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetrieveDeltaLoc) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_DeltaLoc); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RetrieveDeltaLoc(Z_Param_Out_DeltaLoc); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRelease) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Release(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGrab) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Grab(); \
		P_NATIVE_END; \
	}


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMCTrackerComponent(); \
	friend struct Z_Construct_UClass_UMCTrackerComponent_Statics; \
public: \
	DECLARE_CLASS(UMCTrackerComponent, UActorComponent, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OneImmersCustom"), NO_API) \
	DECLARE_SERIALIZER(UMCTrackerComponent)


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUMCTrackerComponent(); \
	friend struct Z_Construct_UClass_UMCTrackerComponent_Statics; \
public: \
	DECLARE_CLASS(UMCTrackerComponent, UActorComponent, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OneImmersCustom"), NO_API) \
	DECLARE_SERIALIZER(UMCTrackerComponent)


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMCTrackerComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMCTrackerComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMCTrackerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMCTrackerComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMCTrackerComponent(UMCTrackerComponent&&); \
	NO_API UMCTrackerComponent(const UMCTrackerComponent&); \
public:


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMCTrackerComponent(UMCTrackerComponent&&); \
	NO_API UMCTrackerComponent(const UMCTrackerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMCTrackerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMCTrackerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMCTrackerComponent)


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_PRIVATE_PROPERTY_OFFSET
#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_10_PROLOG
#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_RPC_WRAPPERS \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_INCLASS \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_INCLASS_NO_PURE_DECLS \
	VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID VRTest01_Plugins_SamplePlugin_Sample_Source_OneImmersCustom_Public_MCTrackComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
