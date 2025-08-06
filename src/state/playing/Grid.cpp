#include "Grid.hpp"

// =============== Construction =============== //

Grid::Grid(Configuration &config, Resources &resources, uint numCells)
    : _config(config), _resources(resources), _gridSize(numCells, numCells)
{

    const sf::Texture &texture = _resources.texture();

    _cells.reserve(numCells * numCells);
    for (uint x = 0; x < _gridSize.x; x++)
    {
        for (uint y = 0; y < _gridSize.y; y++)
        {
            sf::Vector2f pos(x * Grid::Cell::SIZE.x, y * Grid::Cell::SIZE.y);

            _cells.emplace_back(texture, pos, Grid::Cell::SIZE);
        }
    }
}

// ================== State =================== //

void Grid::render(sf::RenderWindow &window) const
{
    for (const Cell &cell : _cells)
        cell.render(window);
}

// ================= Getters ================== //

Grid::Cell &Grid::getCell(int x, int y)
{
    return _cells[getIndex(x, y)];
}

int Grid::getIndex(int x, int y) const
{
    return y * _gridSize.x + x;
}

sf::Vector2i Grid::getXY(int i) const
{
    return {i % _gridSize.x, i / _gridSize.x};
}

// =================== Cell =================== //

Grid::Cell::Cell(const sf::Texture &texture, sf::Vector2f pos, sf::Vector2f size) : _sprite(texture)
{
    _sprite.setPosition(pos);
    _sprite.setScale(size.componentWiseDiv(toVec2f(texture.getSize())));
}

void Grid::Cell::render(sf::RenderWindow &window) const
{
    window.draw(_sprite);
}
