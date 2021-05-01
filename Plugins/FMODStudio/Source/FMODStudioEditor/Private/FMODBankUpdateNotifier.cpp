// Copyright (c), Firelight Technologies Pty, Ltd. 2012-2021.

#include "FMODBankUpdateNotifier.h"
#include "FMODSettings.h"
#include "HAL/FileManager.h"

#include "FMODStudioEditorPrivatePCH.h"

FFMODBankUpdateNotifier::FFMODBankUpdateNotifier()
    : bUpdateEnabled(true)
    , NextRefreshTime(FDateTime::MinValue())
<<<<<<< Updated upstream
=======
    , FileTime(FDateTime::MinValue())
    , Countdown(0.0f)
>>>>>>> Stashed changes
{
}

void FFMODBankUpdateNotifier::SetFilePath(const FString &InPath)
{
    FilePath = InPath;
    NextRefreshTime = FDateTime::MinValue();
<<<<<<< Updated upstream
    FileTime = FDateTime::MinValue();
}

void FFMODBankUpdateNotifier::Update()
=======
    FileTime = MostRecentFileTime();
}

void FFMODBankUpdateNotifier::Update(float DeltaTime)
>>>>>>> Stashed changes
{
    if (bUpdateEnabled)
    {
        FDateTime CurTime = FDateTime::UtcNow();
<<<<<<< Updated upstream
        if (CurTime >= NextRefreshTime)
        {
            NextRefreshTime = CurTime + FTimespan(0, 0, 1);
            Refresh();
=======

        if (CurTime >= NextRefreshTime)
        {
            Refresh();
            NextRefreshTime = CurTime + FTimespan(0, 0, 1);
        }

        if (Countdown > 0.0f)
        {
            Countdown -= DeltaTime;

            if (Countdown <= 0.0f)
            {
                BanksUpdatedEvent.Broadcast();
            }
>>>>>>> Stashed changes
        }
    }
}

void FFMODBankUpdateNotifier::EnableUpdate(bool bEnable)
{
    bUpdateEnabled = bEnable;

    if (bEnable)
    {
        // Refreshing right after update is enabled is not desirable
        NextRefreshTime = FDateTime::UtcNow() + FTimespan(0, 0, 1);
<<<<<<< Updated upstream
=======

        // Cancel any pending countdown
        Countdown = 0.0f;
>>>>>>> Stashed changes
    }
}

void FFMODBankUpdateNotifier::Refresh()
{
    if (!FilePath.IsEmpty())
    {
<<<<<<< Updated upstream
        const FDateTime NewFileTime = IFileManager::Get().GetTimeStamp(*FilePath);
        if (NewFileTime != FileTime)
        {
            FileTime = NewFileTime;
            UE_LOG(LogFMOD, Log, TEXT("File has changed: %s"), *FilePath);

            BanksUpdatedEvent.Broadcast();
        }
    }
=======
        FDateTime NewFileTime = MostRecentFileTime();

        if (NewFileTime != FileTime)
        {
            const UFMODSettings &Settings = *GetDefault<UFMODSettings>();
            Countdown = (float)Settings.ReloadBanksDelay;
            FileTime = NewFileTime;
        }
    }
}

FDateTime FFMODBankUpdateNotifier::MostRecentFileTime()
{
    // Get the most recent modified timestamp of all the bank files in the directory we are watching.
    FDateTime MostRecent = FDateTime::MinValue();

    TArray<FString> BankPaths;
    IFileManager::Get().FindFilesRecursive(BankPaths, *FilePath, TEXT("*.bank"), true, false, false);

    for (const auto& Path : BankPaths)
    {
        FDateTime ModifiedTime = IFileManager::Get().GetTimeStamp(*Path);

        if (ModifiedTime > MostRecent)
        {
            MostRecent = ModifiedTime;
        }
    }

    return MostRecent;
>>>>>>> Stashed changes
}
