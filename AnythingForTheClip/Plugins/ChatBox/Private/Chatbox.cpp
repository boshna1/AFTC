#include "ChatBoxManager.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Math/UnrealMathUtility.h" // For FMath::RandRange

FText UChatBoxManager::GetRandomMessage()
{
    if (Messages.Num() == 0)
    {
        return FText::FromString(TEXT("No messages available"));
    }

}

UChatBoxManager::UChatBoxManager()
{
    Messages.Add(FText::FromString("Yooooo"));
    Messages.Add(FText::FromString("W"));
    Messages.Add(FText::FromString("L"));
    Messages.Add(FText::FromString("Monka"));
}

void UChatBoxManager::DisplayMessage(UUserWidget* Widget)
{
    if (!Widget) return;

    UScrollBox* ScrollBox = Cast<UScrollBox>(Widget->GetWidgetFromName(TEXT("ChatScrollBox")));
    if (!ScrollBox) return;

    FText Message = GetRandomMessage();

    UTextBlock* TextBlock = NewObject<UTextBlock>(Widget);
    if (!TextBlock) return;

    TextBlock->SetText(Message);

    ScrollBox->AddChild(TextBlock);
}
