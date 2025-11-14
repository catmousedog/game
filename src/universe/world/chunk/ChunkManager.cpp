#include "ChunkManager.hpp"

// =============== Construction =============== //

ChunkManager::ChunkManager(Game& game) : _game(game) {}

// ================== Setup =================== //

void ChunkManager::setup()
{
	Chunk chunk(0, 0);
	_chunks.push_back(chunk);
}