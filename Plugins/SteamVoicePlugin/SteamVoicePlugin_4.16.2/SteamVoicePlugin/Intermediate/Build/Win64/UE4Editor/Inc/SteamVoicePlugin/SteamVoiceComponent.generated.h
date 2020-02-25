// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef STEAMVOICEPLUGIN_SteamVoiceComponent_generated_h
#error "SteamVoiceComponent.generated.h already included, missing '#pragma once' in SteamVoiceComponent.h"
#endif
#define STEAMVOICEPLUGIN_SteamVoiceComponent_generated_h

#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopSteamVoice) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StopSteamVoice(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartSteamVoice) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartSteamVoice(); \
		P_NATIVE_END; \
	}


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopSteamVoice) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StopSteamVoice(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartSteamVoice) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartSteamVoice(); \
		P_NATIVE_END; \
	}


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSteamVoiceComponent(); \
	friend struct Z_Construct_UClass_USteamVoiceComponent_Statics; \
public: \
	DECLARE_CLASS(USteamVoiceComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SteamVoicePlugin"), NO_API) \
	DECLARE_SERIALIZER(USteamVoiceComponent)


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUSteamVoiceComponent(); \
	friend struct Z_Construct_UClass_USteamVoiceComponent_Statics; \
public: \
	DECLARE_CLASS(USteamVoiceComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SteamVoicePlugin"), NO_API) \
	DECLARE_SERIALIZER(USteamVoiceComponent)


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USteamVoiceComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USteamVoiceComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USteamVoiceComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USteamVoiceComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USteamVoiceComponent(USteamVoiceComponent&&); \
	NO_API USteamVoiceComponent(const USteamVoiceComponent&); \
public:


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USteamVoiceComponent(USteamVoiceComponent&&); \
	NO_API USteamVoiceComponent(const USteamVoiceComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USteamVoiceComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USteamVoiceComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USteamVoiceComponent)


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_PRIVATE_PROPERTY_OFFSET
#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_12_PROLOG
#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_RPC_WRAPPERS \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_INCLASS \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_INCLASS_NO_PURE_DECLS \
	SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEAMVOICEPLUGIN_API UClass* StaticClass<class USteamVoiceComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SteamVoiceExample_Plugins_SteamVoicePlugin_master_SteamVoicePlugin_4_16_2_SteamVoicePlugin_Source_SteamVoicePlugin_Public_SteamVoiceComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
