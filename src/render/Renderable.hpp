#pragma once

#include "util/Basic.hpp"

#include <SFML/Graphics/Rect.hpp>

struct Renderable
{
	sf::Vector2f position;
	string textureId;
	sf::IntRect textureRect;
	int zIndex;
};