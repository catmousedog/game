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

    /**
     * @brief Sets up the game.
     */
    void setup();

    /**
     * @brief Starts the game loop.
     */
    void run();

    /**
     * @brief Stop the game loop at the end of this tick.
     */
    void stop();

    /**
     * @brief Updates the SFML window.
     */
    void updateSFML();

    /**
     * @brief Runs the game loop.
     */
    void update();

    /**
     * @brief Runs the render loop.
     */
    void render();

    /**
     * @brief Handles the global Game Action.
     * @param gameAction
     */
    void handleAction(GameAction gameAction);

private:
    Configuration _config;
    sf::RenderWindow _window;
    StateManager _stateManager;

    bool _running;
};