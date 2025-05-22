#include "Game.hpp"
#include "util/Error.hpp"
#include "state/MainMenuState.hpp"

Game::Game() : _stateManager(*this)
{
}

Game::~Game()
{
}

void Game::setup()
{
    // config
    _config.loadSettings();
    _window = sf::RenderWindow(sf::VideoMode(static_cast<sf::Vector2u>(_config.windowSize())), "game");
    _window.setFramerateLimit(_config.frameRate());

    // resources
    _resources.loadTextures();
    _resources.loadFonts();

    // states
    _stateManager.push<MainMenuState>();
    _stateManager.performQueued();
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

        // Perform queued state changes
        _stateManager.performQueued();

        if (!_stateManager.current())
        {
            PRINT_ERROR("No current state. Exiting game.");
            break;
        }

        // Update logic
        if (updateClock.getElapsedTime().asSeconds() > update_goal)
        {
            updateClock.restart();

            // Update
            clock.restart();
            update(_update_dt);
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
    while (const std::optional optional = _window.pollEvent())
    {
        auto event = optional.value();
        if (event.is<sf::Event::Closed>())
            return;

        if (event.is<KeyPressed>())
        {
            const KeyPressed &SFML_key = *event.getIf<KeyPressed>();
            state->handleKeyPressed(SFML_key);
        }
        else
        {
            state->handleEvent(event);
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
