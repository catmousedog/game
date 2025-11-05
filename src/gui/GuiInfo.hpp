#pragma once

#include <format>

#include <SFML/Graphics/Text.hpp>

#include "GuiElement.hpp"

class GuiInfo : public GuiElement
{

    // ======= Construction ======= //
public:
    GuiInfo(const sf::Font& font, const Configuration& config);

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window);

    void handleEvent(const sf::RenderWindow& window, const sf::Event &event) override;

    // ======= Concrete ======= //

    void setDt();

private:
    sf::Text _text;
    sf::RectangleShape _box;
};