#pragma once

#include "State.hpp"

class MainMenuState : public State
{
public:
    MainMenuState();

    void handleAction(Action action) override;

    void update(float dt) override;

    void render(sf::RenderWindow &window) override;

    When when() const override { return When::MainMenu; }
};
