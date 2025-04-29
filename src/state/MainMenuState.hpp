#pragma once

#include "State.hpp"
#include "../gui/GuiContainer.hpp"

class MainMenuState : public State
{
    // ======= Action Enum ======= //
private:
    enum Action
    {
        None = ACTION_NONE,
        Exit,
    };

    // ======= Setup ======= //
public:
    void setup(const Configuration &config) override;

    // ======= State ======= //

    void update(float dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    GameAction handleAction(ActionID action) override;

    string name() const override { return "MainMenu"; }

private:
    const ActionMap setupActionMap() const override;

    // ======= Variables ======= //
    GuiContainer _gui;
};
