#pragma once

#include "chunk/ChunkManager.hpp"

#include <SFML/Graphics/View.hpp>

class Game;

class World
{
  public:
    // =============== Construction =============== //

    World(Game& game);

    // ================== Setup =================== //

    void setup();

    // ================= Getters ================== //

    ChunkManager& chunkManager()
    {
        return _chunkManager;
    }

  private:
    Game& _game;
    ChunkManager _chunkManager;
};