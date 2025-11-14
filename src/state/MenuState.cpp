#include "MenuState.hpp"

#include "MainMenuState.hpp"
#include "PlayingState.hpp"

#include <SFML/System/InputStream.hpp>

// =============== Construction =============== //

MenuState::MenuState(Game& game) : State(game) {}

// ================== Setup =================== //

void MenuState::setup()
{
	addPress("Resume", std::bind(&MenuState::resume, this));
	addPress("ExitToMainMenu", std::bind(&MenuState::exitToMainMenu, this));

	State::setup();

	loadWidgetsFromFile("resources/TGUI/Menu.txt");
}

// ================== State =================== //

void MenuState::update(GameTime& time)
{
	State::update(time);
}

void MenuState::render(sf::RenderTarget& target)
{
	State::render(target);
}

// =============== SFML Events ================ //

void MenuState::handleEvent(const sf::RenderTarget& target, const sf::Event& event)
{
	State::handleEvent(target, event);
}

// ================= Actions ================== //

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
