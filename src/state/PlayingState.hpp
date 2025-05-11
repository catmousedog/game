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
    PlayingState(Game &game, Configuration &config);

    // ======= State ======= //

    void setup() override;

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Keybinds ======= //

    void handleAction(ActionID action) override;

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "Playing"; }

private:
    const ActionMap setupActionMap() const override;
};
