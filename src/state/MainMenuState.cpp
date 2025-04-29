#include "MainMenuState.hpp"
#include "../util/Error.hpp"

// ======= Setup ======= //

void MainMenuState::setup(const Configuration &config)
{
    State::setup(config);
}

// ======= Keybinds ======= //

GameAction MainMenuState::handleAction(ActionID action)
{
    switch (action)
    {
    case Action::Exit:
        return GameAction::Exit;
    default:
        break;
    }
    return GameAction::None;
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::render(sf::RenderWindow &window)
{
}

const ActionMap MainMenuState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Exit),
    };
}