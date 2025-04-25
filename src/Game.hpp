#pragma once

#include "Configuration.hpp"

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
    sf::RenderWindow _window; // The main window of the game.
    // sf::Clock clock;         // Clock to manage time.
    // sf::Time deltaTime;      // Time elapsed since the last frame.
};