#pragma once

#include "State.hpp"
#include "render/RenderManager.hpp"
#include "universe/Universe.hpp"

class PlayingState : public State
{
    // =============== Construction =============== //

  public:
    PlayingState(Game& game);

    void setup() override;

    // ================== State =================== //

    void update(GameTime& time) override;

    void render(sf::RenderTarget& target) override;

    // =============== SFML Events ================ //

    void handleEvent(const sf::RenderTarget& target, const sf::Event& event) override;

    string name() const override
    {
        return "Playing";
    };

    // ================= Actions ================== //

    void menu();

    void exit();

    // ================ Variables ================= //

  private:
    Universe _universe;
    RenderManager _renderManager;
};
