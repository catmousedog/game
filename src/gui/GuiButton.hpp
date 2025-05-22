#pragma once

#include <functional>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GuiElement.hpp"

class GuiButton : public GuiElement
{
    // ======= Enum ======= //
private:
    enum class ButtonState
    {
        IDLE,
        HOVER,
        PRESSED,
        RELEASED
    };

    // ======= Construction ======= //
public:
    GuiButton(const sf::Font& font);

    void setText(const std::string &text, uint char_size = 30U);

    void setDimensions(const sf::Vector2f &position, const sf::Vector2f &size);

    void setOnPress(std::function<void()> onPress);

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    void handleEvent(const sf::Event &event) override;

private:
    std::function<void()> _onPress;
    sf::RectangleShape _shape;
    sf::Text _text;

    ButtonState _buttonState = ButtonState::IDLE;
};
