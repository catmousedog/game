#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <unordered_map>

#include "../config/Configuration.hpp"
#include "../resources/Resources.hpp"

class Grid
{

public:
    class Cell;

    // =============== Construction =============== //

    Grid(const Configuration &config, const Resources &resources, uint size);

    // ================== State =================== //

    void render(sf::RenderWindow &window) const;

    // ================= Getters ================== //

    const sf::Vector2i &gridSize() const { return _gridSize; }

    Cell &getCell(int x, int y);

    int getIndex(int x, int y) const;

    sf::Vector2i getXY(int i) const;

    // ================ Variables ================= //

private:
    const Configuration &_config;
    const Resources &_resources;

    sf::Vector2i _gridSize;
    std::vector<Cell> _cells;
};

class Grid::Cell
{
    // ================ Constants ================= //

public:
    // Size of a single cell in the world space, should have no effect on anything.
    static constexpr sf::Vector2f SIZE = {1.f, 1.f};

    // =============== Construction =============== //

    Cell(const sf::Texture &texture, sf::Vector2f pos, sf::Vector2f size);

    // ================== State =================== //

    void render(sf::RenderWindow &window) const;

    // ================ Variables ================= //

private:
    sf::Sprite _sprite;
};
