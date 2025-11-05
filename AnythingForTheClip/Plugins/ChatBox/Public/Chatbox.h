#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChatBoxManager.generated.h"

USTRUCT(BlueprintType)
struct FChatMessage
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chat")
    FText MessageText;
};

UCLASS(Blueprintable, BlueprintType)
class CHATBOXPLUGIN_API UChatBoxManager : public UObject
{
    GENERATED_BODY()

public:


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chat")
    TArray<FText> Messages;


    UFUNCTION(BlueprintCallable, Category = "Chat")
    FText GetRandomMessage();


    UFUNCTION(BlueprintCallable, Category = "Chat")
    void DisplayMessage(class UUserWidget* Widget);


    UChatBoxManager();
};
