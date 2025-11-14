#include "Universe.hpp"

Universe::Universe(Game& game) : _game(game), _worldManager(game) {}

void Universe::setup()
{
	_worldManager.setup();
}