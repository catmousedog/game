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
    // settings
    _config.loadSettings();
    _window = sf::RenderWindow(sf::VideoMode({_config.windowWidth(), _config.windowHeight()}), "game");
    _window.setFramerateLimit(_config.frameRate());

    // states
    _stateManager.pushState<MainMenuState>(*this, _config);
}

void Game::run()
{
    _running = true;

    // desired dt
    double update_goal = getUpdateGoal();
    double render_goal = getRenderGoal();

    // actual dt
    _SFML_dt = 0.;
    _update_dt = 0.;
    _render_dt = 0.;

    sf::Clock updateClock;
    sf::Clock renderClock;
    sf::Clock clock;

    while (_running)
    {
        // SFML
        clock.restart();
        updateSFML();
        _SFML_dt = clock.getElapsedTime().asSeconds();

        // Update logic
        if (updateClock.getElapsedTime().asSeconds() > update_goal)
        {
            updateClock.restart();

            // Update
            clock.restart();
            for (size_t i = 0; i < 1e6; i++)
            {
                test += i;
            }
            
            if (auto *state = _stateManager.current())
                state->update(_update_dt);
            _update_dt = clock.getElapsedTime().asSeconds();
        }

        // Render logic
        if (renderClock.getElapsedTime().asSeconds() > render_goal)
        {
            renderClock.restart();

            // Render
            clock.restart();
            render();
            _render_dt = clock.getElapsedTime().asSeconds();
        }
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

void Game::update(double dt)
{
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