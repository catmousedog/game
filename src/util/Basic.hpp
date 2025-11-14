#pragma once

#include <memory>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::unique_ptr;
using std::vector;

using uint = unsigned int;

#include <SFML/System/Vector2.hpp>

template <typename T> inline constexpr sf::Vector2f toVec2f(const T& t)
{
	return static_cast<sf::Vector2f>(t);
}
template <typename T> inline constexpr sf::Vector2u toVec2u(const T& t)
{
	return static_cast<sf::Vector2u>(t);
}