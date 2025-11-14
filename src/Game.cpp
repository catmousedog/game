#include "Game.hpp"

#include "state/MainMenuState.hpp"
#include "util/Error.hpp"

// =============== Construction =============== //

Game::Game() : _stateManager(*this) {}

Game::~Game() {}

void Game::setup()
{
	// config
	_configManager.loadSettings();
	_window = sf::RenderWindow(sf::VideoMode(toVec2u(_configManager.windowSize())), "game");
	_window.setFramerateLimit(120); // max framerate

	// resources
	_resourceManager.loadTextures();
	_resourceManager.loadFonts();

	// states
	_stateManager.push<MainMenuState>();
	_stateManager.performQueued();
}

// ================== State =================== //

void Game::run()
{
	_running = true;

	// actual dt
	float tick_rate = _configManager.tickTime();

	sf::Clock clock;

	// clock times
	float now;
	float prevUpdate = 0.f;
	float prevRender = 0.f;

	// elapsed time per update
	float sfml_dt;
	float update_dt;
	float render_dt;

	while (_running && _window.isOpen())
	{
		// Perform queued state changes
		_stateManager.performQueued();

		if (!_stateManager.current())
		{
			PRINT_ERROR("No current state. Exiting game.");
			break;
		}

		// SFML
		now = clock.getElapsedTime().asSeconds();
		updateSFML();
		_time.sfml = clock.getElapsedTime().asSeconds() - now; // seconds for sfml

		// for now we fixed TPS = FPS
		// later might do concurrent update/render thread with interpolation

		// Update logic
		now = clock.getElapsedTime().asSeconds();
		float dt = now - prevUpdate;
		if (dt > tick_rate)
		{
			prevUpdate = now;
			_time.dt = dt;

			// Update
			now = clock.getElapsedTime().asSeconds();
			update(_time);
			_time.update = clock.getElapsedTime().asSeconds() - now; // seconds for update

			// Render
			now = clock.getElapsedTime().asSeconds();
			render();
			_time.render = clock.getElapsedTime().asSeconds() - now; // seconds for render
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
	State* state = _stateManager.current();
	while (const std::optional optional = _window.pollEvent())
	{
		auto event = optional.value();

		if (event.is<sf::Event::Closed>())
			stop();

		if (event.is<KeyPressed>())
		{
			const KeyPressed& SFML_key = *event.getIf<KeyPressed>();
			state->handleKeyPressed(SFML_key);
		}
		else
		{
			state->handleEvent(_window, event);
		}
	}
}

void Game::update(GameTime& time)
{
	if (auto* state = _stateManager.current())
		state->update(time);
}

void Game::render()
{
	_window.clear();

	if (auto* state = _stateManager.current())
		state->render(_window);

	_window.display();
}
