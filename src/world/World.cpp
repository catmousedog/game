#include "World.hpp"

World::World(const Configuration &config, const Resources &resources)
    : _grid(config, resources, 10)
{
}

void World::render(sf::RenderWindow &window) const
{
    _grid.render(window);
}