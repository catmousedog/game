#pragma once

#include <format>

#include <SFML/Graphics/Text.hpp>

#include "GuiElement.hpp"

class GuiFrameRate : public GuiElement
{

    // ======= Construction ======= //
public:
    GuiFrameRate(Configuration &config);

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window);

    void handleEvent(const sf::Event &) override;

    // ======= Concrete ======= //

    void setDt(double updateGoal, double renderGoal, const array<double, 3> &dt);

private:
    sf::Text _text;
};