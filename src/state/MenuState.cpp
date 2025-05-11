#include <memory>
#include <SFML/System/InputStream.hpp>

#include "MenuState.hpp"
#include "MainMenuState.hpp"
#include "../Game.hpp"
#include "../util/Error.hpp"

MenuState::MenuState(Game &game, Configuration &config)
    : State(game, config),
      _resumeButton(config),
      _exitToMainMenuButton(config)
{
    _resumeButton.setText("Resume", 30U);
    _resumeButton.setDimensions(config.absPos(0.5f, 0.4f), config.absPos(0.2f, 0.1f));
    _resumeButton.setOnPress([this]()
                             { resume(); });

    _exitToMainMenuButton.setText("Exit to Main Menu", 30U);
    _exitToMainMenuButton.setDimensions(config.absPos(0.5f, 0.6f), config.absPos(0.3f, 0.1f));
    _exitToMainMenuButton.setOnPress([this]()
                                     { menu(); });
}

void MenuState::update(double dt)
{
    _resumeButton.update(dt);
    _exitToMainMenuButton.update(dt);
}

void MenuState::render(sf::RenderWindow &window)
{
    _resumeButton.render(window);
    _exitToMainMenuButton.render(window);
}

void MenuState::handleAction(ActionID action)
{
    switch (action)
    {
    case Resume:
        _game.stateManager().pop();
        break;
    default:
        break;
    }
}

void MenuState::handleEvent(const sf::Event &event)
{
    _resumeButton.handleEvent(event);
    _exitToMainMenuButton.handleEvent(event);
}

const ActionMap MenuState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Resume),
    };
}

void MenuState::resume()
{
    _game.stateManager().pop();
}

void MenuState::menu()
{
    _game.stateManager().set<MainMenuState>();
}