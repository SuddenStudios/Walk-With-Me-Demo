// Copyright (c), Firelight Technologies Pty, Ltd. 2012-2021.

#include "FMODEventControlSection.h"
<<<<<<< Updated upstream
#include "FMODEventControlSectionTemplate.h"
=======
>>>>>>> Stashed changes
#include "Channels/MovieSceneChannelProxy.h"
#include "UObject/SequencerObjectVersion.h"
#include "UObject/Package.h"

FFMODEventControlChannel::FFMODEventControlChannel()
{
<<<<<<< Updated upstream
    SetEnum(FindObject<UEnum>(ANY_PACKAGE, TEXT("EFMODEventControlKey")));
=======
    SetEnum(StaticEnum<EFMODEventControlKey>());
>>>>>>> Stashed changes
}

UFMODEventControlSection::UFMODEventControlSection(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
    SetRange(TRange<FFrameNumber>::All());

    int32 LinkerCustomVersion = GetLinkerCustomVersion(FSequencerObjectVersion::GUID);
    EMovieSceneCompletionMode CompletionMode;

    if (LinkerCustomVersion < FSequencerObjectVersion::WhenFinishedDefaultsToRestoreState)
    {
        CompletionMode = EMovieSceneCompletionMode::KeepState;
    }
    else if (LinkerCustomVersion < FSequencerObjectVersion::WhenFinishedDefaultsToProjectDefault)
    {
        CompletionMode = EMovieSceneCompletionMode::RestoreState;
    }
    else
    {
        CompletionMode = EMovieSceneCompletionMode::ProjectDefault;
    }

<<<<<<< Updated upstream
=======
    EvalOptions.EnableAndSetCompletionMode(CompletionMode);

>>>>>>> Stashed changes
#if WITH_EDITOR

    ChannelProxy = MakeShared<FMovieSceneChannelProxy>(ControlKeys, FMovieSceneChannelMetaData(), TMovieSceneExternalValue<uint8>());

#else

    ChannelProxy = MakeShared<FMovieSceneChannelProxy>(ControlKeys);

#endif
}
