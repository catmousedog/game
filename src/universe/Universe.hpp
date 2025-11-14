#pragma once

#include "world/WorldManager.hpp"

#include <SFML/Graphics/View.hpp>

class Universe
{
  public:
	// =============== Construction =============== //

	Universe(Game& game);

	// ================== Setup =================== //

	void setup();

	// ================= Getters ================== //

	WorldManager& worldManager()
	{
		return _worldManager;
	}

	// ================ Variables ================= //

  private:
	Game& _game;

	WorldManager _worldManager;

	// in the future we could have child classes for different types of universes
	// UniverseConfig _universeConfig;
	// unique_ptr<WorldManager> _worldManager;
	// unique_ptr<EntityManager> _entityManager;
	// unique_ptr<EventManager> _eventManager;
	// unique_ptr<TechManager> _techManager;
};