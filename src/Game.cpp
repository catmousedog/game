#include "Game.hpp"
#include "util/Error.hpp"
#include "state/MainMenuState.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::setup()
{
    _config.loadSettings();

    _stateManager.pushState<MainMenuState>(_config);

    _window = sf::RenderWindow(sf::VideoMode({_config.windowWidth(), _config.windowHeight()}), "game");
}

void Game::run()
{
    _running = true;
    while (_running)
    {
        _window.clear();
        updateSFML();
        update();
        render();
        _window.display();
    }
    _window.close();
}

void Game::stop()
{
    _running = false;
}

void Game::updateSFML()
{
    State *state = _stateManager.current();
    while (const std::optional event = _window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            return;

        if (event->is<KeyPressed>())
        {
            const KeyPressed &SFML_key = *event->getIf<KeyPressed>();
            ActionID action = state->getAction(SFML_key);

            if (action != ACTION_NONE)
            {
                GameAction gameAction = state->handleAction(action);
                // handle global actions indirectly invoked by the State
                handleAction(gameAction);
            }
        }
    }
}

void Game::update()
{
    static sf::Clock clock;
    float dt = clock.restart().asSeconds();

    if (auto *state = _stateManager.current())
        state->update(dt);
}

void Game::render()
{
    _window.clear();
    if (auto *state = _stateManager.current())
        state->render(_window);

    

    _window.display();
}

void Game::handleAction(GameAction gameAction)
{
    switch (gameAction)
    {
    case GameAction::None:
        break;
    case GameAction::Exit:
        stop();
        break;
    default:
        break;
    }
}