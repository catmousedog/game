#include "MainMenuState.hpp"

#include "Game.hpp"
#include "PlayingState.hpp"

#include <TGUI/Widgets/Tabs.hpp>

// =============== Construction =============== //

MainMenuState::MainMenuState(Game& game) : State(game) {}

// ================== Setup =================== //

void MainMenuState::setup()
{
	addPress("Play", std::bind(&MainMenuState::play, this));
	addPress("Exit", std::bind(&MainMenuState::exit, this));

	State::setup();

	loadWidgetsFromFile("resources/TGUI/MainMenu.txt");
}
// ================== State =================== //

void MainMenuState::update(GameTime& time)
{
	State::update(time);
}

void MainMenuState::render(sf::RenderTarget& target)
{
	State::render(target);
}

// =============== SFML Events ================ //

void MainMenuState::handleEvent(const sf::RenderTarget& target, const sf::Event& event)
{
	State::handleEvent(target, event);
}

// ================= Actions ================== //

void MainMenuState::play()
{
	_game.stateManager().pop<MainMenuState>();
	_game.stateManager().push<PlayingState>();
}

void MainMenuState::exit()
{
	_game.stop();
}