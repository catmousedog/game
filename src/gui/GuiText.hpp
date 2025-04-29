#pragma once

#include <SFML/Graphics/Text.hpp>

#include "GuiElement.hpp"

class GuiText : public GuiElement
{

public:
    GuiText(const sf::Font &font, const std::string &text) : _text(font, text) {}

    void update(float) override {}

    void render(sf::RenderWindow &window) override
    {
        window.draw(_text);
    }

    void handleEvent(const sf::Event &) override {}

private:
    sf::Text _text;
};