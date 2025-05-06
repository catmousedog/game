#include <memory>
#include <SFML/System/InputStream.hpp>

#include "MainMenuState.hpp"
#include "../Game.hpp"
#include "../util/Error.hpp"
#include "../gui/GuiText.hpp"
#include "../gui/GuiFrameRate.hpp"

// ======= Construction ======= //

MainMenuState::MainMenuState(const Game &game, Configuration &config) : State(game, config), _guiFrameRate(config.font())
{
}

// ======= Setup ======= //

void MainMenuState::setup()
{
    State::setup();
}

// ======= State ======= //

void MainMenuState::update(double dt)
{
    _guiFrameRate.setDt(_game.getUpdateGoal(), _game.getRenderGoal(), _game.getDt());
    _guiFrameRate.update(dt);
}

void MainMenuState::render(sf::RenderWindow &window)
{
    _guiFrameRate.render(window);
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

const ActionMap MainMenuState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Exit),
    };
}