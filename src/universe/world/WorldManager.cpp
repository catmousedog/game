#include "WorldManager.hpp"

// =============== Construction =============== //

WorldManager::WorldManager(Game& game) : _game(game) {}

// ================== Setup =================== //

void WorldManager::setup()
{
    World world(_game);
    world.setup();
    _worlds.push_back(world);
}

// ================= Getters ================== //

World& WorldManager::getWorld(uint index)
{
    return _worlds[index];
}