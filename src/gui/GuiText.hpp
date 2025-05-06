#pragma once

#include <SFML/Graphics/Text.hpp>

#include "GuiElement.hpp"

class GuiText : public GuiElement
{

public:
    GuiText(const sf::Font &font, const std::string &text, unsigned int char_size = 30U) : _text(font, text, char_size) {}

    void update(double) override {}

    void render(sf::RenderWindow &window) override
    {
        _text.setStyle(sf::Text::Bold);
        _text.setFillColor(sf::Color::Red);
        window.draw(_text);
    }

    void handleEvent(const sf::Event &) override {}

private:
    sf::Text _text;
};