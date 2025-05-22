#pragma once

#include <SFML/Graphics/Text.hpp>

#include "GuiElement.hpp"

class GuiText : public GuiElement
{

    // ======= Construction ======= //
public:
    GuiText(Configuration &config,
            const std::string &text,
            uint char_size = 30U)
        : GuiElement(config),
          _text(config.font(), text, char_size)
    {
        _text.setStyle(sf::Text::Bold);
        _text.setFillColor(sf::Color::Red);
    }

    // ======= State ======= //

    void update(double) override {}

    void render(sf::RenderWindow &window) override
    {
        window.draw(_text);
    }

    void handleEvent(const sf::Event &) override {}

private:
    sf::Text _text;
};