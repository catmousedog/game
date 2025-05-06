#include "PlayingState.hpp"

// ======= Construction ======= //

// ======= State ======= //

void PlayingState::update(double dt) {}

void PlayingState::render(sf::RenderWindow &window) {}

// ======= Keybinds ======= //

GameAction PlayingState::handleAction(ActionID action)
{
    return GameAction::None;
}

const ActionMap PlayingState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Sprint),
    };
}
