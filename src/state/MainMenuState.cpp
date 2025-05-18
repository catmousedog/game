#include <memory>
#include <SFML/System/InputStream.hpp>

#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "../Game.hpp"
#include "../util/Error.hpp"

MainMenuState::MainMenuState(Game &game, Configuration &config)
    : State(game, config),
      _guiFrameRate(config),
      _playButton(config),
      _exitButton(config)
{
}

void MainMenuState::setup()
{
    addPress("play", [this]()
             { play(); });
    addPress("exit", [this]()
             { exit(); });

    State::setup();

    _playButton.setText("Play", 30U);
    _playButton.setDimensions(_config.absPos(0.5f, 0.5f), _config.absPos(0.2f, 0.1f));
    _playButton.setOnPress(getPressAction("play"));

    _exitButton.setText("Exit", 30U);
    _exitButton.setDimensions(_config.absPos(0.5f, 0.6f), _config.absPos(0.2f, 0.1f));
    _exitButton.setOnPress(getPressAction("exit"));
}

void MainMenuState::update(double dt)
{
    _guiFrameRate.setDt(_game.getUpdateGoal(), _game.getRenderGoal(), _game.getDt());

    _guiFrameRate.update(dt);
    _playButton.update(dt);
    _exitButton.update(dt);
}

void MainMenuState::render(sf::RenderWindow &window)
{
    _guiFrameRate.render(window);
    _playButton.render(window);
    _exitButton.render(window);
}

void MainMenuState::handleEvent(const sf::Event &event)
{
    _playButton.handleEvent(event);
    _exitButton.handleEvent(event);
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