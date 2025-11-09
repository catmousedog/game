#include "PlayingState.hpp"

#include "Game.hpp"
#include "MenuState.hpp"

// =============== Construction =============== //

PlayingState::PlayingState(Game& game)
    : State(game), _universe(game),
      _renderManager(game, _universe, _gui) // test if error if universe last
{
}

// ================== Setup =================== //

void PlayingState::setup()
{
    addPress("Menu", std::bind(&PlayingState::menu, this));
    addPress("Exit", std::bind(&PlayingState::exit, this));

    State::setup();

    _universe.setup();
    _renderManager.setup();
}

// ================== State =================== //

void PlayingState::update(GameTime& time)
{
    State::update(time);
    _renderManager.update(time);
}

void PlayingState::render(sf::RenderTarget& target)
{
    _renderManager.render(target);

    State::render(target);
}

// =============== SFML Events ================ //

void PlayingState::handleEvent(const sf::RenderTarget& target, const sf::Event& event)
{
    State::handleEvent(target, event);

    _renderManager.handleEvent(target, event);
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