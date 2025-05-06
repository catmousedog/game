#pragma once

#include <format>

#include <SFML/Graphics/Text.hpp>

#include "GuiElement.hpp"

class GuiFrameRate : public GuiElement
{

public:
    GuiFrameRate(const sf::Font &font) : _text(font, "frames")
    {
        _text.setStyle(sf::Text::Bold);
        _text.setFillColor(sf::Color::Red);
        _text.setCharacterSize(18);
    }

    void update(double dt) override {}

    void render(sf::RenderWindow &window) override
    {
        window.draw(_text);
    }

    void handleEvent(const sf::Event &) override {}

    void setDt(double updateGoal, double renderGoal, const array<double, 3> &dt)
    {
        double SFML = dt[0];
        double update = dt[1] / updateGoal * 100.;
        double render = dt[2] / renderGoal * 100.;
        string str = std::vformat("SFML:\t{:.2f}ms\nupdate:\t{:.2f}ms\t{:.1f}%\nrender:\t{:.2f}ms\t{:.1f}%",
                                  std::make_format_args(updateGoal, renderGoal, SFML, update, render));
        _text.setString(str);
    }

private:
    sf::Text _text;
};