#pragma once

#include "State.hpp"
#include "../gui/GuiButton.hpp"

class MenuState : public State
{
    // =============== Construction =============== //

public:
    MenuState(Game &game);

    void setup() override;

    // ================== State =================== //

    void update(double dt) override;

    void render(sf::RenderWindow &window) override;

    // =============== SFML Events ================ //

    void handleEvent(const sf::Event &event) override;

    string name() const override { return "Menu"; };

    // ================= Actions ================== //

    void resume();

    void exitToMainMenu();

    // ================ Variables ================= //

private:
    GuiButton _resumeButton;
    GuiButton _exitToMainMenuButton;
};