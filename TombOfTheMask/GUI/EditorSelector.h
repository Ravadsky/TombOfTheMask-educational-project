#pragma once
#include "Button.h"

class ULevelEditor;

class UEditorSelector : public UButton
{
private:
    int selectorID = -1;
    ULevelEditor* editor;

    void ChangeEditorSelect();

public:
    UEditorSelector(UUserWidget* parent);

    void UpdateSelector(ULevelEditor* currentEditor, int ID);
};

class UEditorSelectorPanel : public UUserWidget
{
private:
    std::vector<std::unique_ptr<UEditorSelector>> selectors;
    std::unique_ptr<UImage> background;

    ULevelEditor* editor;

public:
    UEditorSelectorPanel(UUserWidget* parent);

    bool IsHoveredByMouse(int xMousePos, int yMousePos);
    void UpdateSelectorPanel(ULevelEditor* currentEditor);
};