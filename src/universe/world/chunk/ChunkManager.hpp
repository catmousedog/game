#pragma once

#include "Chunk.hpp"
#include "util/Basic.hpp"

class Game;

class ChunkManager
{
  public:
    // =============== Construction =============== //

    ChunkManager(Game& game);

    // ================== Setup =================== //

    void setup();

    // ================= Getters ================== //

    vector<Chunk>& getChunks()
    {
        return _chunks;
    }

    // ================ Variables ================= //

  private:
    Game& _game;

    vector<Chunk> _chunks;
};