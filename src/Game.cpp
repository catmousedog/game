#include "Game.hpp"
#include "Error.hpp"

Game::Game() : _config()
{
    sf::Vector2u windowSize = {_config.windowWidth(), _config.windowHeight()};
    _window = sf::RenderWindow(sf::VideoMode(windowSize), "game");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    bool running = true;
    while (_window.isOpen() && running)
    {
        if (!updateSFML())
            running = false;
        if (!update())
            running = false;
        if (!render())
            running = false;
        _window.clear();
        _window.draw(shape);
        _window.display();
    }
    _window.close();
}

Game::~Game()
{
    // Destructor implementation
}

bool Game::updateSFML()
{
    while (const std::optional event = _window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            return false;

        if (event->is<sf::Event::KeyPressed>())
        {
            const sf::Event::KeyPressed *SFML_key = event->getIf<sf::Event::KeyPressed>();
            Action action = _config.getKeybind(*SFML_key);

            if (action != Action::None)
            {
                // perform action
                PRINT_DEBUG("{}", (int)action);

                if (action == Action::Exit)
                    return false;
            }
        }
    }
    return true;
}

bool Game::update()
{
    // Update logic
    return true;
}

bool Game::render()
{
    // Render logic
    return true;
}