#pragma once

#include "util/Basic.hpp"
#include "World.hpp"

class WorldManager
{
public:
    // =============== Construction =============== //

    WorldManager(Game &game);

    // ================== Setup =================== //

    void setup();

    // ================= Getters ================== //

    World &getWorld(uint index);

    // ================ Variables ================= //

private:
    Game &_game;

    vector<World> _worlds;
};