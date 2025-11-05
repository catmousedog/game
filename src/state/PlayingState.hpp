#pragma once

#include <SFML/Graphics/View.hpp>

#include "State.hpp"
#include "../world/World.hpp"
#include "../ui/UIManager.hpp"
#include "../ui/Input.hpp"
#include "../render/Renderer.hpp"

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

    void handleEvent(const sf::RenderWindow &window, const sf::Event &event) override;

    string name() const override { return "Playing"; };

    // ================= Actions ================== //

    void menu();

    void exit();

    // ================ Variables ================= //

private:
    World _world;
    Renderer _renderer;
    Input _input;
    UIManager _uiManager;
};
