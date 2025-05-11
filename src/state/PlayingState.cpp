#include "PlayingState.hpp"

PlayingState::PlayingState(Game &game, Configuration &config)
    : State(game, config)
{
}

void PlayingState::setup()
{
    State::setup();
}

void PlayingState::update(double dt) {}

void PlayingState::render(sf::RenderWindow &window) {}

void PlayingState::handleAction(ActionID action) {}

void PlayingState::handleEvent(const sf::Event &event)
{
}

const ActionMap PlayingState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Sprint),
    };
}
