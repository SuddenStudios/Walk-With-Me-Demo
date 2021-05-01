// Copyright (c), Firelight Technologies Pty, Ltd. 2012-2021.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MovieSceneNameableTrack.h"
<<<<<<< Updated upstream
=======
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
>>>>>>> Stashed changes
#include "FMODEventControlTrack.generated.h"

/** Handles control of an FMOD Event */
UCLASS(MinimalAPI)
<<<<<<< Updated upstream
class UFMODEventControlTrack : public UMovieSceneNameableTrack
=======
class UFMODEventControlTrack : public UMovieSceneNameableTrack, public IMovieSceneTrackTemplateProducer
>>>>>>> Stashed changes
{
    GENERATED_UCLASS_BODY()

public:
    virtual TArray<UMovieSceneSection *> GetAllControlSections() const { return ControlSections; }

public:
    // Begin UMovieSceneTrack interface
<<<<<<< Updated upstream
    virtual void RemoveAllAnimationData() override;
=======
>>>>>>> Stashed changes
    virtual bool HasSection(const UMovieSceneSection &Section) const override;
    virtual void AddSection(UMovieSceneSection &Section) override;
    virtual void RemoveSection(UMovieSceneSection &Section) override;
    virtual bool IsEmpty() const override;
    virtual const TArray<UMovieSceneSection *> &GetAllSections() const override;
    virtual void AddNewSection(FFrameNumber SectionTime);
<<<<<<< Updated upstream
    virtual UMovieSceneSection *CreateNewSection() override;
// End UMovieSceneTrack interface
=======
    virtual bool SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const override;
    virtual UMovieSceneSection *CreateNewSection() override;
    // End UMovieSceneTrack interface

    // IMovieSceneTrackTemplateProducer interface
    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const override;
>>>>>>> Stashed changes

#if WITH_EDITORONLY_DATA
    virtual FText GetDefaultDisplayName() const override;
#endif

private:
    /** List of all event control sections. */
    UPROPERTY()
    TArray<UMovieSceneSection *> ControlSections;
};
