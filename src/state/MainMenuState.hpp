#pragma once

#include "State.hpp"
#include "../gui/GuiFrameRate.hpp"
#include "../gui/GuiButton.hpp"

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
    MainMenuState(Game &game, Configuration &config);

    // ======= State ======= //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // ======= Event ======= //

    void handleAction(ActionID action) override;

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "MainMenu"; }

private:
    const ActionMap setupActionMap() const override;

    // ======= Actions ======= //

    void play();

    void exit();

    // ======= Variables ======= //
    
    GuiFrameRate _guiFrameRate;
    GuiButton _playButton;
    GuiButton _exitButton;
};
