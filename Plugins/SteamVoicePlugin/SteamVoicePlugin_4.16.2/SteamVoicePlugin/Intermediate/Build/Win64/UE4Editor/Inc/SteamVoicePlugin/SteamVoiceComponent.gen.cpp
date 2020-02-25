// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SteamVoicePlugin/Public/SteamVoiceComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSteamVoiceComponent() {}
// Cross Module References
	STEAMVOICEPLUGIN_API UClass* Z_Construct_UClass_USteamVoiceComponent_NoRegister();
	STEAMVOICEPLUGIN_API UClass* Z_Construct_UClass_USteamVoiceComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_SteamVoicePlugin();
	STEAMVOICEPLUGIN_API UFunction* Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice();
	STEAMVOICEPLUGIN_API UFunction* Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice();
// End Cross Module References
	void USteamVoiceComponent::StaticRegisterNativesUSteamVoiceComponent()
	{
		UClass* Class = USteamVoiceComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "StartSteamVoice", &USteamVoiceComponent::execStartSteamVoice },
			{ "StopSteamVoice", &USteamVoiceComponent::execStopSteamVoice },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice_Statics::Function_MetaDataParams[] = {
		{ "Category", "Steam Voice Plugin" },
		{ "ModuleRelativePath", "Public/SteamVoiceComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USteamVoiceComponent, nullptr, "StartSteamVoice", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice_Statics::Function_MetaDataParams[] = {
		{ "Category", "Steam Voice Plugin" },
		{ "ModuleRelativePath", "Public/SteamVoiceComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USteamVoiceComponent, nullptr, "StopSteamVoice", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USteamVoiceComponent_NoRegister()
	{
		return USteamVoiceComponent::StaticClass();
	}
	struct Z_Construct_UClass_USteamVoiceComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USteamVoiceComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SteamVoicePlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USteamVoiceComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USteamVoiceComponent_StartSteamVoice, "StartSteamVoice" }, // 3303063351
		{ &Z_Construct_UFunction_USteamVoiceComponent_StopSteamVoice, "StopSteamVoice" }, // 2600505031
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USteamVoiceComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "SteamVoicePlugin" },
		{ "IncludePath", "SteamVoiceComponent.h" },
		{ "ModuleRelativePath", "Public/SteamVoiceComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USteamVoiceComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USteamVoiceComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USteamVoiceComponent_Statics::ClassParams = {
		&USteamVoiceComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USteamVoiceComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USteamVoiceComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USteamVoiceComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USteamVoiceComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USteamVoiceComponent, 293506895);
	template<> STEAMVOICEPLUGIN_API UClass* StaticClass<USteamVoiceComponent>()
	{
		return USteamVoiceComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USteamVoiceComponent(Z_Construct_UClass_USteamVoiceComponent, &USteamVoiceComponent::StaticClass, TEXT("/Script/SteamVoicePlugin"), TEXT("USteamVoiceComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USteamVoiceComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
