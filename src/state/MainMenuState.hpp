#pragma once

#include "State.hpp"
#include "../gui/GuiFrameRate.hpp"

class MainMenuState : public State
{
    // ======= Action Enum ======= //
private:
    enum Action
    {
        None = ACTION_NONE,
        Exit,
    };

    // ======= Construction ======= //
public:
    MainMenuState(const Game &game, Configuration &config);

    // ======= Setup ======= //
public:
    void setup() override;

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    GameAction handleAction(ActionID action) override;

    string name() const override { return "MainMenu"; }

private:
    const ActionMap setupActionMap() const override;

    // ======= Variables ======= //
public:
    GuiFrameRate _guiFrameRate;
};
