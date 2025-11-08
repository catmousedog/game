#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "util/Basic.hpp"

struct Renderable
{
    sf::Vector2f position;
    string textureId;
    sf::IntRect textureRect;
    int zIndex;
};