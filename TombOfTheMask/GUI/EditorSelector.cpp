#include "EditorSelector.h"
#include "Base/TextBlock.h"
#include "Base/Image.h"
#include "Core/GameSubsystems/ResourceSubsystem.h"

#include "GameStates/LevelEditor.h"
#include "GUI/Base/Image.h"

void UEditorSelector::ChangeEditorSelect()
{
    if (editor != nullptr)
        editor->SelectByID(selectorID);
}

UEditorSelector::UEditorSelector(UUserWidget* parent) : UButton(parent)
{
    ButtonImage->SetAlignment(EHorizontalAlignment::Left, EVerticalAlignment::Bottom);
    ButtonText->SetText("");
    onButtonPressed.Add(this, &UEditorSelector::ChangeEditorSelect);
}

void UEditorSelector::UpdateSelector(ULevelEditor* currentEditor, int ID)
{
    editor = currentEditor;
    selectorID = ID;

    auto name = GetResourceSubsystem()->GetTextureNameByID(selectorID);
    ButtonImage->SetTextureByName(name);
}

UEditorSelectorPanel::UEditorSelectorPanel(UUserWidget* parent) : UUserWidget(parent)
{
    background = std::make_unique<UImage>(this);
    background->SetTextureByName("selector");
    background->SetAlignment(EHorizontalAlignment::Center, EVerticalAlignment::Bottom);
    background->SetScreenPosition({ 0.0f, -48.0f });
}

bool UEditorSelectorPanel::IsHoveredByMouse(int xMousePos, int yMousePos)
{
    return background->ContainsMouse({ (float)xMousePos, (float)yMousePos });
}

void UEditorSelectorPanel::UpdateSelectorPanel(ULevelEditor* currentEditor)
{
    editor = currentEditor;

    int index = 0;
    for (auto id : GetResourceSubsystem()->GetStaticObjectsID())
    {
        selectors.emplace_back(editor->ConstructButton<UEditorSelector>(this, ""));

        auto& selector = selectors[index];
        selector->SetScreenPosition({ (float)index * SPRITE_GAME_SIZE + 196.0f, -48.0f });
        selector->UpdateSelector(editor, id);

        index++;
    }
}
