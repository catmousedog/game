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
    GuiElement(Configuration &config) : _config(config) {}

    virtual ~GuiElement() = default;

    // ======= State ======= //

    virtual void update(double dt) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    virtual void handleEvent(const sf::Event &event) = 0;
    // ======= Getters ======= //
public:
    Configuration &config() { return _config; }

    // ======= Variables ======= //
protected:
    Configuration &_config;
};
