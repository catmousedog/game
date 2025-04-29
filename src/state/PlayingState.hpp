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

    // ======= Setup ======= //
public:
    void setup(const Configuration& config) override;

    // ======= State ======= //

    void update(float dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    GameAction handleAction(ActionID action) override;

    string name() const override { return "Playing"; }

private:
    const ActionMap setupActionMap() const override;
};
