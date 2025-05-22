#pragma once

#include <SFML/Graphics/View.hpp>

#include "../State.hpp"
#include "../../gui/GuiFrameRate.hpp"
#include "Grid.hpp"

class PlayingState : public State
{
    // =============== Construction =============== //

public:
    PlayingState(Game &game);

    void setup() override;

    // ================== State =================== //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // =============== SFML Events ================ //

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "Playing"; };

    // ================= Actions ================== //

    void menu();

    void exit();

    // ================ Variables ================= //

private:
    GuiFrameRate _guiFrameRate;
    Grid _grid;

    sf::View _view;
};
