#include "Widget.h"
#include "assert.h"

Widget::Widget(sf::Vector2f position, std::string fileName, std::string widgetText)
{
   assert(WidgetTexture.loadFromFile(RESOURCES_PATH + "GUI/" + fileName + ".png"));
    WidgetSprite = std::make_unique<SpriteComponent>(WidgetTexture, position);
    WidgetSprite->SetDrawType(DrawType::Widget);
    WidgetText = std::make_unique<TextBox>(widgetText, position + sf::Vector2f(128.f, 0.f));
}

void Widget::BeginPlay()
{
}

void Widget::Update()
{
}

void Widget::UpdateState(std::string newString)
{
    WidgetText->ChangeText(newString);
}
