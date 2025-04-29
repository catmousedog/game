#include "PlayingState.hpp"

void PlayingState::setup(const Configuration &config)
{
    State::setup(config);
}

GameAction PlayingState::handleAction(ActionID action)
{
    return GameAction::None;
}

void PlayingState::update(float dt) {}

void PlayingState::render(sf::RenderWindow &window) {}

const ActionMap PlayingState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Sprint),
    };
}