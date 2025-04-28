#include "PlayingState.hpp"

PlayingState::PlayingState() : State() {}

const ActionMap PlayingState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Sprint),
    };
}

void PlayingState::handleAction(ActionID action)
{
    //
}

void PlayingState::update(float dt) {}

void PlayingState::render(sf::RenderWindow &window) {}