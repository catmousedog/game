#include "MainMenuState.hpp"
#include "../util/Error.hpp"

MainMenuState::MainMenuState() : State() {}

const ActionMap MainMenuState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Test),
    };
}

void MainMenuState::handleAction(ActionID action)
{
    PRINT_DEBUG("MainMenuState::handleAction: {}", action);
}

void MainMenuState::update(float dt) {}

void MainMenuState::render(sf::RenderWindow &window) {}