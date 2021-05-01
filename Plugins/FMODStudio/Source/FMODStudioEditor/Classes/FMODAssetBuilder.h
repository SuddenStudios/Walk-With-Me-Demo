// Copyright (c), Firelight Technologies Pty, Ltd.

#pragma once

#include "CoreMinimal.h"

namespace FMOD
{
namespace Studio
{
class System;
}
} // namespace FMOD

class UFMODAsset;
class UFMODBankLookup;
class UFMODSettings;

class FFMODAssetBuilder
{
public:
    ~FFMODAssetBuilder();

    /** Create studio system for asset building */
    void Create();

    /** Process FMOD banks into UE4 assets */
    void ProcessBanks();

    /** Path of strings bank */
    FString GetMasterStringsBankPath();

private:
    struct AssetCreateInfo
    {
        UClass *Class;
        FGuid Guid;
        FString StudioPath;
        FString AssetName;
        FString PackagePath;
        FString Path;
    };

<<<<<<< Updated upstream
    void BuildBankLookup(const FString &AssetName, const FString &PackagePath, const UFMODSettings &InSettings);
    void BuildAssets(const UFMODSettings &InSettings);
    void BuildAssetLookup(const FString &AssetName, const FString &PackagePath);

    FString GetAssetClassName(UClass *AssetClass);
    bool MakeAssetCreateInfo(const FGuid &AssetGuid, const FString &StudioPath, AssetCreateInfo *CreateInfo);
    UFMODAsset *CreateAsset(const AssetCreateInfo& CreateInfo);
    void DeleteAsset(UObject *Asset);

    TMap<FString, TWeakObjectPtr<UFMODAsset>> NameLookup;
=======
    void BuildBankLookup(const FString &AssetName, const FString &PackagePath, const UFMODSettings &InSettings, TArray<UObject*>& AssetsToSave);
    void BuildAssets(const UFMODSettings &InSettings, const FString &AssetLookupName, const FString &AssetLookupPath, TArray<UObject*>& AssetsToSave,
        TArray<UObject*>& AssetsToDelete);

    FString GetAssetClassName(UClass *AssetClass);
    bool MakeAssetCreateInfo(const FGuid &AssetGuid, const FString &StudioPath, AssetCreateInfo *CreateInfo);
    UFMODAsset *CreateAsset(const AssetCreateInfo& CreateInfo, TArray<UObject*>& AssetsToSave);
    void SaveAssets(TArray<UObject*>& AssetsToSave);
    void DeleteAssets(TArray<UObject*>& AssetsToDelete);

>>>>>>> Stashed changes
    FMOD::Studio::System *StudioSystem{};
    UFMODBankLookup *BankLookup{};
};
