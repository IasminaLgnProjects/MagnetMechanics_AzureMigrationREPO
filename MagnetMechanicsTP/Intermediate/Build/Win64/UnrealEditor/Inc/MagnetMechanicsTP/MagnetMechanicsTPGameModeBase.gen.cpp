// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagnetMechanicsTP/MagnetMechanicsTPGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagnetMechanicsTPGameModeBase() {}
// Cross Module References
	MAGNETMECHANICSTP_API UClass* Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_NoRegister();
	MAGNETMECHANICSTP_API UClass* Z_Construct_UClass_AMagnetMechanicsTPGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MagnetMechanicsTP();
// End Cross Module References
	void AMagnetMechanicsTPGameModeBase::StaticRegisterNativesAMagnetMechanicsTPGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMagnetMechanicsTPGameModeBase);
	UClass* Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_NoRegister()
	{
		return AMagnetMechanicsTPGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MagnetMechanicsTP,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MagnetMechanicsTPGameModeBase.h" },
		{ "ModuleRelativePath", "MagnetMechanicsTPGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagnetMechanicsTPGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::ClassParams = {
		&AMagnetMechanicsTPGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagnetMechanicsTPGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AMagnetMechanicsTPGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMagnetMechanicsTPGameModeBase.OuterSingleton, Z_Construct_UClass_AMagnetMechanicsTPGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMagnetMechanicsTPGameModeBase.OuterSingleton;
	}
	template<> MAGNETMECHANICSTP_API UClass* StaticClass<AMagnetMechanicsTPGameModeBase>()
	{
		return AMagnetMechanicsTPGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagnetMechanicsTPGameModeBase);
	struct Z_CompiledInDeferFile_FID_MagnetMechanicsTP_Source_MagnetMechanicsTP_MagnetMechanicsTPGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MagnetMechanicsTP_Source_MagnetMechanicsTP_MagnetMechanicsTPGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMagnetMechanicsTPGameModeBase, AMagnetMechanicsTPGameModeBase::StaticClass, TEXT("AMagnetMechanicsTPGameModeBase"), &Z_Registration_Info_UClass_AMagnetMechanicsTPGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMagnetMechanicsTPGameModeBase), 1805995758U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MagnetMechanicsTP_Source_MagnetMechanicsTP_MagnetMechanicsTPGameModeBase_h_259378402(TEXT("/Script/MagnetMechanicsTP"),
		Z_CompiledInDeferFile_FID_MagnetMechanicsTP_Source_MagnetMechanicsTP_MagnetMechanicsTPGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MagnetMechanicsTP_Source_MagnetMechanicsTP_MagnetMechanicsTPGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
