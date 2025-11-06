#include <memory>
#include <SFML/System/InputStream.hpp>

#include "MenuState.hpp"
#include "PlayingState.hpp"
#include "MainMenuState.hpp"
#include "../Game.hpp"
#include "../util/Error.hpp"

MenuState::MenuState(Game &game)
    : State(game)
{
}

void MenuState::setup()
{
    addPress("Resume", std::bind(&MenuState::resume, this));
    addPress("ExitToMainMenu", std::bind(&MenuState::exitToMainMenu, this));

    State::setup();

    loadWidgetsFromFile("resources/TGUI/Menu.txt");
}

void MenuState::update(double dt)
{
    State::update(dt);
}

void MenuState::render(sf::RenderWindow &window)
{
    State::render(window);
}

void MenuState::handleEvent(const sf::RenderWindow &window, const sf::Event &event)
{
    State::handleEvent(window, event);
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
