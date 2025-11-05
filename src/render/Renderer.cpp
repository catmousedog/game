#include "Renderer.hpp"

Renderer::Renderer()
{
}

void Renderer::setup(Game &game, Grid &grid)
{
    sf::Vector2f gridSize = toVec2f(grid.gridSize());
    sf::Vector2f cellSize = Grid::Cell::SIZE;
    sf::Vector2f gridWorldSize = gridSize.componentWiseMul(cellSize);
    sf::Vector2f center(gridWorldSize / 2.f);
    sf::Vector2f size(gridWorldSize.x * game.config().windowRatio(), gridWorldSize.y);
    _cameraView.setup(center, size, game.config().zoomToMouse());
}

void Renderer::render(sf::RenderWindow &window)
{
    _cameraView.setView(window);
}

void Renderer::handleEvent(const sf::RenderWindow &window, const sf::Event &event)
{
    _cameraView.handleEvent(window, event);
}