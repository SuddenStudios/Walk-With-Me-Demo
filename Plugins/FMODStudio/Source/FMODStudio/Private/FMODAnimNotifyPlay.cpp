
#include "FMODAnimNotifyPlay.h"
#include "FMODBlueprintStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UFMODAnimNotifyPlay::UFMODAnimNotifyPlay()
    : Super()
{

#if WITH_EDITORONLY_DATA
    NotifyColor = FColor(196, 142, 255, 255);
#endif // WITH_EDITORONLY_DATA
}

void UFMODAnimNotifyPlay::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *AnimSeq)
{
<<<<<<< Updated upstream
    if (Event.IsValid())
=======
    if (Event)
>>>>>>> Stashed changes
    {
        if (bFollow)
        {
            // Play event attached
            UFMODBlueprintStatics::PlayEventAttached(
<<<<<<< Updated upstream
                Event.Get(), MeshComp, *AttachName, FVector(0, 0, 0), EAttachLocation::KeepRelativeOffset, false, true, true);
=======
                Event, MeshComp, *AttachName, FVector(0, 0, 0), EAttachLocation::KeepRelativeOffset, false, true, true);
>>>>>>> Stashed changes
        }
        else
        {
            // Play event at location
<<<<<<< Updated upstream
            UFMODBlueprintStatics::PlayEventAtLocation(MeshComp, Event.Get(), MeshComp->GetComponentTransform(), true);
=======
            UFMODBlueprintStatics::PlayEventAtLocation(MeshComp, Event, MeshComp->GetComponentTransform(), true);
>>>>>>> Stashed changes
        }
    }
}

FString UFMODAnimNotifyPlay::GetNotifyName_Implementation() const
{
<<<<<<< Updated upstream
    if (Event.IsValid())
    {
        return (Event.Get())->GetName();
=======
    if (Event)
    {
        return Event->GetName();
>>>>>>> Stashed changes
    }
    else
    {
        return Super::GetNotifyName_Implementation();
    }
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes
