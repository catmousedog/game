#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "Basic.hpp"

using Key = sf::Keyboard::Key;

struct KeyPressed
{
    Key code = Key::Unknown;
    bool alt = false;
    bool control = false;
    bool shift = false;

    bool operator==(const KeyPressed &other) const = default;
};

namespace std
{
    template <>
    struct hash<KeyPressed>
    {
        size_t operator()(const KeyPressed &k) const
        {
            size_t h = 0;
            h ^= hash<int>{}(static_cast<int>(k.code)) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= hash<bool>{}(k.alt) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= hash<bool>{}(k.control) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= hash<bool>{}(k.shift) + 0x9e3779b9 + (h << 6) + (h >> 2);
            return h;
        }
    };
}

enum class Action
{
    None,
    Exit
};

KeyPressed parseKeybind(string keyString);

Action parseAction(string actionString);
