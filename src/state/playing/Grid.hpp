#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <unordered_map>

#include "../../config/Configuration.hpp"
#include "../../resources/Resources.hpp"

class Grid
{
    // =================== Cell =================== //

public:
    class Cell
    {
    public:
        Cell(const sf::Texture &texture, sf::Vector2f pos, sf::Vector2f size);

        void render(sf::RenderWindow &window) const;

    private:
        sf::Sprite _sprite;
    };

    // =============== Construction =============== //

    Grid(Configuration &config, Resources &resources, uint size);

    // ================== State =================== //

    void render(sf::RenderWindow &window) const;

    // ================= Getters ================== //

    Cell &getCell(int x, int y);

    int getIndex(int x, int y) const;

    sf::Vector2i getXY(int i) const;

    // ================ Variables ================= //

private:
    Configuration &_config;
    Resources &_resources;

    sf::Vector2i _gridSize;
    std::vector<Cell> _cells;
};