// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOneImmersCustom_init() {}
	ONEIMMERSCUSTOM_API UFunction* Z_Construct_UDelegateFunction_OneImmersCustom_OnGhostModeChanged__DelegateSignature();
	ONEIMMERSCUSTOM_API UFunction* Z_Construct_UDelegateFunction_OneImmersCustom_OnBrakingModeChanged__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OneImmersCustom()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_OneImmersCustom_OnGhostModeChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OneImmersCustom_OnBrakingModeChanged__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/OneImmersCustom",
				PKG_CompiledIn | 0x00000000,
				0xBDC33CAE,
				0x597E8882,
				SingletonFuncArray, ARRAY_COUNT(SingletonFuncArray),
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
