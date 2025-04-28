#pragma once

#include "State.hpp"

class PlayingState : public State
{
public:
    PlayingState();

    void handleAction(Action action) override;

    void update(float dt) override;

    void render(sf::RenderWindow &window) override;

    When when() const override { return When::Playing; }
};
