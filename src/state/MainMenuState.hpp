#pragma once

#include "State.hpp"
#include "../gui/GuiFrameRate.hpp"
#include "../gui/GuiButton.hpp"

class MainMenuState : public State
{
    // =============== Construction =============== //

public:
    MainMenuState(Game &game, Configuration &config);

    void setup() override;

    // ================== State =================== //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // =============== SFML Events ================ //

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "MainMenu"; };

    // ================= Actions ================== //

    void play();

    void exit();

    // ================ Variables ================= //

private:
    GuiFrameRate _guiFrameRate;
    GuiButton _playButton;
    GuiButton _exitButton;
};
