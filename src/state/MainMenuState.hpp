#pragma once

#include "State.hpp"

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
    MainMenuState();

    const ActionMap setupActionMap() const override;

    // ======= Update ======= //

    void update(float dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    GameAction handleAction(ActionID action) override;

    string name() const override { return "MainMenu"; }
};
