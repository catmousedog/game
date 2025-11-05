#pragma once

#include <SFML/Graphics/View.hpp>

#include "Grid.hpp"

class World
{
public:
    // =============== Construction =============== //

    World(const Configuration &config, const Resources &resources);

    // ================== State =================== //

    void render(sf::RenderWindow &window) const;

private:
    Grid _grid;
};