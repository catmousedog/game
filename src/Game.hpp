#pragma once

#include "config/Configuration.hpp"
#include "resources/Resources.hpp"
#include "state/StateManager.hpp"

class Game
{

    // ======= Construction ======= //
public:
    /**
     * @brief Constructor for the Game class.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     */
    ~Game();

    // ======= State ======= //
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
    void update(double dt);

    /**
     * @brief Runs the render loop.
     */
    void render();

    // ======= Getters ======= //
public:
    /**
     * @brief Calculates the desired time (s) between update ticks.
     * @return Desired update time (s).
     */
    double getUpdateGoal() const { return 1.f / (_gameSpeed * _config.tickRate()); }

    /**
     * @brief Calculates the desired time (s) between render ticks.
     * @return Desired render time (s).
     */
    double getRenderGoal() const { return 1.f / _config.frameRate(); }

    array<double, 3> getDt() const { return {_SFML_dt, _update_dt, _render_dt}; }

    StateManager &stateManager() { return _stateManager; }

    Configuration& config() { return _config; }

    Resources& resources() { return _resources; }

    // ======= Setters ======= //

public:
    // ======= Variables ======= //
private:
    Configuration _config;
    Resources _resources;
    StateManager _stateManager;

    // SFML
    sf::Clock _clock;
    sf::RenderWindow _window;

    // variables
    bool _running;
    double _gameSpeed = 1.;
    // dt
    double _SFML_dt;
    double _update_dt;
    double _render_dt;

    double test;
};