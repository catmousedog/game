#include "MainMenuState.hpp"
#include "../util/Error.hpp"

MainMenuState::MainMenuState() : State() {}

const ActionMap MainMenuState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Exit),
    };
}

GameAction MainMenuState::handleAction(ActionID action)
{
    switch (action)
    {
    case Action::Exit:
        return GameAction::Exit;
    default:
        break;
    }
}

void MainMenuState::update(float dt) {}

void MainMenuState::render(sf::RenderWindow &window) {}