// Copyright (c), Firelight Technologies Pty, Ltd. 2012-2021.

#pragma once

#include "Containers/UnrealString.h"
#include "Misc/DateTime.h"
#include "Delegates/Delegate.h"

class FFMODBankUpdateNotifier
{
public:
    FFMODBankUpdateNotifier();

    void SetFilePath(const FString &InPath);
<<<<<<< Updated upstream
    void Update();
=======
    void Update(float DeltaTime);
>>>>>>> Stashed changes

    void EnableUpdate(bool bEnable);

    FSimpleMulticastDelegate BanksUpdatedEvent;

private:
    void Refresh();
<<<<<<< Updated upstream
=======
    FDateTime MostRecentFileTime();
>>>>>>> Stashed changes

    bool bUpdateEnabled;
    FString FilePath;
    FDateTime NextRefreshTime;
    FDateTime FileTime;
<<<<<<< Updated upstream
=======
    float Countdown;
>>>>>>> Stashed changes
};
