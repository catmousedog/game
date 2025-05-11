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
    _playButton.setText("Play", 30U);
    _playButton.setDimensions(config.absPos(0.5f, 0.5f), config.absPos(0.2f, 0.1f));
    _playButton.setOnPress([this]()
                           { play(); });

    _exitButton.setText("Exit", 30U);
    _exitButton.setDimensions(config.absPos(0.5f, 0.6f), config.absPos(0.2f, 0.1f));
    _exitButton.setOnPress([this]()
                           { exit(); });
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

void MainMenuState::handleAction(ActionID action)
{
    switch (action)
    {
    case Action::Exit:
        exit();
    default:
        break;
    }
}

void MainMenuState::handleEvent(const sf::Event &event)
{
    _playButton.handleEvent(event);
    _exitButton.handleEvent(event);
}

const ActionMap MainMenuState::setupActionMap() const
{
    return {
        ACTIONMAP_ENTRY(None),
        ACTIONMAP_ENTRY(Exit),
    };
}

void MainMenuState::play()
{
    _game.stateManager().replace<PlayingState>();
}

void MainMenuState::exit()
{
    _game.stop();
}