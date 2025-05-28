#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

#include "GuiButton.hpp"

#include "../util/Error.hpp"

constexpr auto IDLE_COLOR = sf::Color(100, 100, 150);
constexpr auto HOVER_COLOR = sf::Color(125, 125, 200);
constexpr auto PRESSED_COLOR = sf::Color(125, 200, 200);

GuiButton::GuiButton(const sf::Font &font) : _text(font), _shape()
{
}

void GuiButton::setText(const std::string &text, uint char_size)
{
    _text.setString(text);
    _text.setCharacterSize(char_size);
}

void GuiButton::setDimensions(const sf::Vector2f &position, const sf::Vector2f &size)
{
    _shape.setSize(size);
    _shape.setOrigin(_shape.getLocalBounds().getCenter());
    _shape.setPosition(position);

    _text.setOrigin(_text.getLocalBounds().getCenter());
    _text.setPosition(position);
}

void GuiButton::setOnPress(std::function<void()> onPress)
{
    _onPress = std::move(onPress);
}

void GuiButton::update(double)
{
}

void GuiButton::render(sf::RenderWindow &window)
{
    switch (_buttonState)
    {
    case ButtonState::IDLE:
        _shape.setFillColor(IDLE_COLOR);
        break;
    case ButtonState::HOVER:
        _shape.setFillColor(HOVER_COLOR);
        break;
    case ButtonState::PRESSED:
        _shape.setFillColor(PRESSED_COLOR);
        break;
    }
    window.draw(_shape);
    window.draw(_text);
}

void GuiButton::handleEvent(const sf::RenderWindow& window, const sf::Event &event)
{
    if (event.is<sf::Event::MouseMoved>() && _buttonState != ButtonState::PRESSED)
    {
        auto mouse = event.getIf<sf::Event::MouseMoved>();
        if (_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse->position)))
            _buttonState = ButtonState::HOVER;
        else
            _buttonState = ButtonState::IDLE;
    }
    else if (event.is<sf::Event::MouseButtonPressed>())
    {
        auto mouse = event.getIf<sf::Event::MouseButtonPressed>();
        if (_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse->position)))
        {
            _buttonState = ButtonState::PRESSED;
        }
    }
    else if (event.is<sf::Event::MouseButtonReleased>())
    {
        auto mouse = event.getIf<sf::Event::MouseButtonReleased>();
        if (_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse->position)) && _buttonState == ButtonState::PRESSED)
            _onPress();

        _buttonState = ButtonState::IDLE;
    }
}