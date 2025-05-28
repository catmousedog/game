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

    _cameraView.initView(_game.config().windowSize());
}

// ================== State =================== //

void PlayingState::update(double dt)
{
    _guiFrameRate.setDt(_game.getUpdateGoal(), _game.getRenderGoal(), _game.getDt());

    _guiFrameRate.update(dt);
}

void PlayingState::render(sf::RenderWindow &window)
{
    _cameraView.setView(window);

    _grid.render(window);

    // UI
    window.setView(window.getDefaultView());
    _guiFrameRate.render(window);
}

// =============== SFML Events ================ //

void PlayingState::handleEvent(const sf::RenderWindow& window, const sf::Event &event)
{
    _cameraView.handleEvent(window, event);
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