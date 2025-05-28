#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "../config/Configuration.hpp"
#include "../util/Basic.hpp"

/**
 * @brief An abstract GUI element.
 */
class GuiElement
{

    // ======= Construction ======= //
public:
    virtual ~GuiElement() = default;

    // ======= State ======= //

    virtual void update(double dt) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    virtual void handleEvent(const sf::RenderWindow& window, const sf::Event &event) = 0;
};
