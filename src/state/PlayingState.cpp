#include "PlayingState.hpp"

PlayingState::PlayingState() : State() {}

const ActionMap PlayingState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Sprint),
    };
}

GameAction PlayingState::handleAction(ActionID action)
{
    return GameAction::None;
}

void PlayingState::update(float dt) {}

void PlayingState::render(sf::RenderWindow &window) {}