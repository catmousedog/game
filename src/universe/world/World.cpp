#include "World.hpp"

// =============== Construction =============== //

World::World(Game &game) : _game(game), _chunkManager(game)
{
}

// ================== Setup =================== //

void World::setup()
{
    _chunkManager.setup();
}