#pragma once

#include "State.hpp"
#include "../gui/GuiFrameRate.hpp"
#include "../gui/GuiButton.hpp"

class MenuState : public State
{
    // ======= Action Enum ======= //
private:
    enum Action
    {
        None = ACTION_NONE,
        Resume
    };

    // ======= Construction ======= //
public:
    MenuState(Game &game, Configuration &config);

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Event ======= //

    void handleAction(ActionID action) override;

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "Menu"; }

private:
    const ActionMap setupActionMap() const override;

    // ======= Actions ======= //

    void resume();

    void menu();

    // ======= Variables ======= //
public:
    GuiButton _resumeButton;
    GuiButton _exitToMainMenuButton;
};