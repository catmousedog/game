#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

/**
 * @brief An abstract GUI element.
 */
class GuiElement
{
public:
    virtual void update(double dt) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    virtual void handleEvent(const sf::Event &event) = 0;

    virtual ~GuiElement() = default;
};
