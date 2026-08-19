#pragma once
#include "Core/UObject.h"

enum class EHorizontalAlignment : uint8_t
{
    Left,
    Center,
    Right
};
enum class EVerticalAlignment : uint8_t
{
    Top,
    Center,
    Bottom
};

class UUserWidget : public UObject
{
protected:
    sf::Vector2f screenPosition = { 0.0f, 0.0f };
    UUserWidget* parentWidget;
    EHorizontalAlignment horizontalAlignment = EHorizontalAlignment::Center;
    EVerticalAlignment verticalAlignment = EVerticalAlignment::Center;

    sf::Vector2f GetAlignmentOffset();

public:
    UUserWidget(UUserWidget* parent);
    virtual ~UUserWidget();

    inline void SetScreenPosition(sf::Vector2f newPosition) { screenPosition = newPosition; };
    sf::Vector2f GetScreenPosition();

    void SetAlignment(EHorizontalAlignment horizontal, EVerticalAlignment vertical);

    virtual void Render() {};
};

template <typename T>
std::unique_ptr<T> Construct(UUserWidget* parent)
{
    static_assert(std::is_base_of_v<UUserWidget, T>, "T must be a subclass of UUserWidget");

    auto ptr = std::make_unique<T>(parent);
    ptr->BeginPlay();
    return ptr;
};