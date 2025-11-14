#pragma once

#include "GameContext.hpp"
#include "config/ConfigManager.hpp"
#include "resources/ResourceManager.hpp"
#include "state/StateManager.hpp"

class Game
{
	// =============== Construction =============== //
  public:
	/**
	 * @brief Constructor for the Game class.
	 */
	Game();

	/**
	 * @brief Destructor for the Game class.
	 */
	~Game();

	// ================== State =================== //

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
	void update(GameTime& time);

	/**
	 * @brief Runs the render loop.
	 */
	void render();

	// ================= Getters ================== //

  public:
	StateManager& stateManager()
	{
		return _stateManager;
	}

	ConfigManager& configManager()
	{
		return _configManager;
	}

	ResourceManager& resourceManager()
	{
		return _resourceManager;
	}

	sf::RenderWindow& window()
	{
		return _window;
	}

	// ================ Variables ================= //

  private:
	ConfigManager _configManager;
	ResourceManager _resourceManager;
	StateManager _stateManager;

	// SFML
	sf::Clock _clock;
	sf::RenderWindow _window;

	// variables
	bool _running;
	float _gameSpeed = 1.;

	// tick times
	GameTime _time;
};