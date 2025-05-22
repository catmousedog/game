#include "Grid.hpp"

// =================== Cell =================== //

Grid::Cell::Cell(const sf::Texture &texture, sf::Vector2f pos, sf::Vector2f size) : _sprite(texture)
{
    _sprite.setPosition(pos);
}

void Grid::Cell::render(sf::RenderWindow &window) const
{
    window.draw(_sprite);
}

// =============== Construction =============== //

Grid::Grid(Configuration &config, Resources &resources, uint size)
    : _config(config), _resources(resources), _gridSize(size, size)
{

    const sf::Texture &texture = _resources.texture();

    _cells.reserve(size * size);
    for (uint x = 0; x < _gridSize.x; x++)
    {
        for (uint y = 0; y < _gridSize.y; y++)
        {
            sf::Vector2f size(100, 100);
            // sf::IntRect rect({0, 0}, size);

            sf::Vector2f pos(x * size.x, y * size.y);

            _cells.emplace_back(texture, pos, size);
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