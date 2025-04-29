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
    PlayingState();

    const ActionMap setupActionMap() const override;

    // ======= Update ======= //

    void update(float dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    GameAction handleAction(ActionID action) override;

    string name() const override { return "Playing"; }
};
