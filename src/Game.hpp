#pragma once

#include "config/Configuration.hpp"
#include "state/StateManager.hpp"

class Game
{
public:
    /**
     * @brief Constructor for the Game class.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     */
    ~Game();

    void setup();

    void run();

    /**
     * @brief Updates the SFML window.
     */
    bool updateSFML();

    /**
     * @brief Runs the game loop.
     */
    bool update();

    /**
     * @brief Runs the render loop.
     */
    bool render();

private:
    Configuration _config;
    sf::RenderWindow _window;
    StateManager _stateManager;
};