#pragma once
#include "Core/UObject.h"
#include "GUI/Base/UserWidget.h"

class UButton;

class UGameState : public UObject
{
public:
    UGameState();
    virtual ~UGameState() = default;
    virtual void BeginPlay() override {};
    virtual void Update(float deltaTime) override;

    std::vector<UButton*> Buttons;

    template <typename T>
    std::unique_ptr<T> ConstructButton(UUserWidget* parent, std::string buttonText)
    {
        static_assert(std::is_base_of_v<UButton, T>, "T must be a subclass of UButton");

        auto ptr = Construct<T>(parent);
        ptr->SetButtonText(buttonText);
        Buttons.push_back(ptr.get());

        return ptr;
    }

protected:
    int xMousePos, yMousePos;

    FDelegate<> onLeftMouseButtonPressed;
    FDelegate<> onMiddleMouseButtonPressed;
    FDelegate<> onRightMouseButtonPressed;
    FDelegate<> onEnterPressed;
    FDelegate<> onEscapePressed;

    void CheckAllButtonsPressed();
    void ReturnToMainMenu();
};
