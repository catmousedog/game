#include "PlayingState.hpp"

#include "../../Game.hpp"
#include "../MenuState.hpp"

// =============== Construction =============== //

PlayingState::PlayingState(Game &game)
    : State(game),
      _grid(game.config(), game.resources(), 10),
      _guiFrameRate(game.resources().font())
{
}

void PlayingState::setup()
{
    addPress("menu", std::bind(&PlayingState::menu, this));
    addPress("exit", std::bind(&PlayingState::exit, this));

    State::setup();

    _view.setCenter({100, 100});
    _view.setSize({200, 200});
}

// ================== State =================== //

void PlayingState::update(double dt)
{
    _guiFrameRate.setDt(_game.getUpdateGoal(), _game.getRenderGoal(), _game.getDt());

    _guiFrameRate.update(dt);
}

void PlayingState::render(sf::RenderWindow &window)
{
    window.setView(_view);
    
    _grid.render(window);
    _guiFrameRate.render(window);
}

// =============== SFML Events ================ //

void PlayingState::handleEvent(const sf::Event &event)
{
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