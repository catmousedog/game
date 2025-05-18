#pragma once

#include "State.hpp"
#include "../gui/GuiFrameRate.hpp"

class PlayingState : public State
{
    // =============== Construction =============== //

public:
    PlayingState(Game &game, Configuration &config);

    void setup() override;

    // ================== State =================== //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // =============== SFML Events ================ //

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "Playing"; };

    // ================= Actions ================== //

    void menu();

    // ================ Variables ================= //

private:
    GuiFrameRate _guiFrameRate;
};
