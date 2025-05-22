#include <memory>
#include <SFML/System/InputStream.hpp>

#include "MenuState.hpp"
#include "playing/PlayingState.hpp"
#include "MainMenuState.hpp"
#include "../Game.hpp"
#include "../util/Error.hpp"

MenuState::MenuState(Game &game)
    : State(game),
      _resumeButton(game.resources().font()),
      _exitToMainMenuButton(game.resources().font())
{
}

void MenuState::setup()
{
    addPress("resume", [this]()
             { this->resume(); });

    State::setup();

    const Configuration &config = _game.config();

    _resumeButton.setText("Resume", 30U);
    _resumeButton.setDimensions(config.absPos(0.5f, 0.4f), config.absPos(0.2f, 0.1f));
    _resumeButton.setOnPress(getPressAction("resume"));

    _exitToMainMenuButton.setText("Exit to Main Menu", 30U);
    _exitToMainMenuButton.setDimensions(config.absPos(0.5f, 0.6f), config.absPos(0.3f, 0.1f));
    _exitToMainMenuButton.setOnPress(std::bind(&MenuState::exitToMainMenu, this));
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

void MenuState::handleEvent(const sf::Event &event)
{
    _resumeButton.handleEvent(event);
    _exitToMainMenuButton.handleEvent(event);
}

void MenuState::resume()
{
    _game.stateManager().pop<MenuState>();
}

void MenuState::exitToMainMenu()
{
    _game.stateManager().pop<MenuState>();
    _game.stateManager().pop<PlayingState>();
    _game.stateManager().push<MainMenuState>();
}
