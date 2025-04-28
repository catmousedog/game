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

    // this can probably be cleaned up? maybe move code to State?
    std::unique_ptr<State> mainMenu = std::make_unique<MainMenuState>();
    mainMenu->setup(_config);
    _stateManager.push(std::move(mainMenu));

    _window = sf::RenderWindow(sf::VideoMode({_config.windowWidth(), _config.windowHeight()}), "game");
}

void Game::run()
{
    bool running = true;
    while (running)
    {
        _window.clear();
        if (!updateSFML())
            running = false;
        if (!update())
            running = false;
        if (!render())
            running = false;
        _window.display();
    }
    _window.close();
}

bool Game::updateSFML()
{
    State *state = _stateManager.current();
    while (const std::optional event = _window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            return false;

        if (event->is<KeyPressed>())
        {
            const KeyPressed &SFML_key = *event->getIf<KeyPressed>();
            ActionID action = state->getAction(SFML_key);

            if (action != ACTION_NONE)
            {
                state->handleAction(action);

                // global actions here?
            }
        }
    }
    return true;
}

bool Game::update()
{
    static sf::Clock clock;
    float dt = clock.restart().asSeconds();

    if (auto *state = _stateManager.current())
        state->update(dt);

    return !_stateManager.empty();
}

bool Game::render()
{
    _window.clear();
    if (auto *state = _stateManager.current())
        state->render(_window);
    _window.display();
    return true;
}