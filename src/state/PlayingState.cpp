#include "PlayingState.hpp"

#include "../Game.hpp"
#include "MenuState.hpp"

// =============== Construction =============== //

PlayingState::PlayingState(Game &game)
    : State(game), _world(game.config(), game.resources())
{
}

void PlayingState::setup()
{
    addPress("Menu", std::bind(&PlayingState::menu, this));
    addPress("Exit", std::bind(&PlayingState::exit, this));

    State::setup();
}

// ================== State =================== //

void PlayingState::update(double dt)
{
    State::update(dt);
}

void PlayingState::render(sf::RenderWindow &window)
{
    State::render(window);

    _renderer.render(window);

    _world.render(window);

    // UI
    // window.setView(window.getDefaultView());
    // _guiInfo.render(window);
    // _guiFrameRate.render(window);
}

// =============== SFML Events ================ //

void PlayingState::handleEvent(const sf::RenderWindow &window, const sf::Event &event)
{
    State::handleEvent(window, event);

    _renderer.handleEvent(window, event);
}

// ================= Actions ================== //

void PlayingState::menu()
{
    _game.stateManager().push<MenuState>();
}

void PlayingState::exit()
{
    _game.stop();
}