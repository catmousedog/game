#include "RenderManager.hpp"

RenderManager::RenderManager(Game &game, Universe &universe)
    : _game(game), _universe(universe), _resourceManager(game.resourceManager())
{
}

void RenderManager::setup()
{
    sf::Vector2f center(1.f, 1.f);
    sf::Vector2f size(10, 10);
    _cameraView.setup(center, size, true);
}

void RenderManager::render(sf::RenderTarget &target)
{
    _cameraView.setView(target);

    ChunkManager &chunkManager = _universe.worldManager().getWorld(0).chunkManager();

    vector<Chunk> &chunks = chunkManager.getChunks();

    for (Chunk &chunk : chunks)
    {
        Chunk::Renderable renderable = chunk.getRenderable();
        // renderable.textureId
        target.draw(renderable.vertices);
    }
}

void RenderManager::handleEvent(const sf::RenderTarget &target, const sf::Event &event)
{
    _cameraView.handleEvent(target, event);
}