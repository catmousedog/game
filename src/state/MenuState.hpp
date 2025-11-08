#pragma once

#include "State.hpp"

class MenuState : public State
{
    // =============== Construction =============== //

public:
    MenuState(Game &game);

    void setup() override;

    // ================== State =================== //

    void update(double dt) override;

    void render(sf::RenderTarget &target) override;

    // =============== SFML Events ================ //

    void handleEvent(const sf::RenderTarget &target, const sf::Event &event) override;

    string name() const override { return "Menu"; };

    // ================= Actions ================== //

    void resume();

    void exitToMainMenu();

    // ================ Variables ================= //

private:
};