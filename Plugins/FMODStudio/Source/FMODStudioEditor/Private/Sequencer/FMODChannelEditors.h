#pragma once

#include "KeyDrawParams.h"
#include "Channels/MovieSceneChannelHandle.h"
#include "Sequencer/FMODEventControlSection.h"

<<<<<<< Updated upstream
#include "FMODChannelEditors.generated.h"

/** KeyStruct overrides */
TSharedPtr<FStructOnScope> GetKeyStruct(const TMovieSceneChannelHandle<FFMODEventControlChannel> &Channel, FKeyHandle InHandle);

/** Key drawing overrides */
void DrawKeys(FFMODEventControlChannel *Channel, TArrayView<const FKeyHandle> InKeyHandles, TArrayView<FKeyDrawParams> OutKeyDrawParams);

USTRUCT()
struct FFMODEventControlKeyStruct : public FMovieSceneKeyTimeStruct
{
    GENERATED_BODY();

    UPROPERTY(EditAnywhere, Category = "Key")
    EFMODEventControlKey Value;
};

template <>
struct TStructOpsTypeTraits<FFMODEventControlKeyStruct> : public TStructOpsTypeTraitsBase2<FFMODEventControlKeyStruct>
{
    enum
    {
        WithCopy = false
    };
};
=======
/** Key editor overrides */
bool CanCreateKeyEditor(const FFMODEventControlChannel* Channel);

TSharedRef<SWidget> CreateKeyEditor(const TMovieSceneChannelHandle<FFMODEventControlChannel>& Channel, UMovieSceneSection* Section,
    const FGuid& InObjectBindingID, TWeakPtr<FTrackInstancePropertyBindings> PropertyBindings, TWeakPtr<ISequencer> InSequencer);

/** Key drawing overrides */
void DrawKeys(FFMODEventControlChannel *Channel, TArrayView<const FKeyHandle> InKeyHandles, const UMovieSceneSection* InOwner, TArrayView<FKeyDrawParams> OutKeyDrawParams);
>>>>>>> Stashed changes
