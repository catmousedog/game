#include <memory>
#include <SFML/System/InputStream.hpp>

#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "../Game.hpp"
#include "../util/Error.hpp"

MainMenuState::MainMenuState(Game &game) : State(game) {}

void MainMenuState::setup()
{
    addPress("Play", std::bind(&MainMenuState::play, this));
    addPress("Exit", std::bind(&MainMenuState::exit, this));
    
    State::setup();

    loadWidgetsFromFile("resources/TGUI/MainMenu.txt");
}

void MainMenuState::update(double dt)
{
    State::update(dt);
}

void MainMenuState::render(sf::RenderWindow &window)
{
    State::render(window);
}

void MainMenuState::handleEvent(const sf::RenderWindow &window, const sf::Event &event)
{
    State::handleEvent(window, event);
}

void MainMenuState::play()
{
    _game.stateManager().pop<MainMenuState>();
    _game.stateManager().push<PlayingState>();
}

void MainMenuState::exit()
{
    _game.stop();
}