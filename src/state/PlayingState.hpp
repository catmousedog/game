#pragma once

#include "State.hpp"

class PlayingState : public State
{
    // ======= Action Enum ======= //
private:
    enum Action
    {
        None = ACTION_NONE,
        Sprint,
    };

    // ======= Construction ======= //
public:

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    GameAction handleAction(ActionID action) override;

    string name() const override { return "Playing"; }

private:
    const ActionMap setupActionMap() const override;
};
