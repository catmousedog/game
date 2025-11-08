#pragma once

#include <SFML/Graphics/View.hpp>

#include "chunk/ChunkManager.hpp"

class Game;

class World
{
public:
    // =============== Construction =============== //

    World(Game &game);

    // ================== Setup =================== //

    void setup();

    // ================= Getters ================== //

    inline ChunkManager &chunkManager() { return _chunkManager; }

private:
    Game &_game;
    ChunkManager _chunkManager;
};