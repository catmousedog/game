#include "PlayingState.hpp"

#include "../Game.hpp"
#include "../state/MenuState.hpp"

PlayingState::PlayingState(Game &game, Configuration &config)
    : State(game, config),
      _guiFrameRate(config)
{
}

void PlayingState::setup()
{
    addPress("menu", [this]()
             { menu(); });

    State::setup();
}

void PlayingState::update(double dt)
{
    _guiFrameRate.setDt(_game.getUpdateGoal(), _game.getRenderGoal(), _game.getDt());

    _guiFrameRate.update(dt);
}

void PlayingState::render(sf::RenderWindow &window)
{
    _guiFrameRate.render(window);
}

void PlayingState::handleEvent(const sf::Event &event)
{
}

void PlayingState::menu()
{
    _game.stateManager().push<MenuState>();
}