#include "RenderManager.hpp"

// =============== Construction =============== //

RenderManager::RenderManager(Game& game, Universe& universe, tgui::Gui& gui)
    : _game(game), _resourceManager(game.resourceManager()), _universe(universe), _uiManager(gui)
{
}

// ================== Setup =================== //

void RenderManager::setup()
{
    sf::Vector2f center(1.f, 1.f);
    sf::Vector2f size(10, 10);
    _cameraView.setup(center, size, true);
    _uiManager.setup();
}

// ================== State =================== //

void RenderManager::update(GameTime& time)
{
    _uiManager.update(time);
}

void RenderManager::render(sf::RenderTarget& target)
{
    _cameraView.setView(target);

    ChunkManager& chunkManager = _universe.worldManager().getWorld(0).chunkManager();

    vector<Chunk>& chunks = chunkManager.getChunks();

    for (Chunk& chunk : chunks)
    {
        Chunk::Renderable renderable = chunk.getRenderable();
        // renderable.textureId
        target.draw(renderable.vertices);
    }
}

// =============== SFML Events ================ //

void RenderManager::handleEvent(const sf::RenderTarget& target, const sf::Event& event)
{
    _cameraView.handleEvent(target, event);
}