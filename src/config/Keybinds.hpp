#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "../util/Basic.hpp"

using Key = sf::Keyboard::Key;
using KeyPressed = sf::Event::KeyPressed;

/**
 * Description of a certain keybind based on the sf::Event::KeyPressed
 */
struct KeyBind
{
    Key code = Key::Unknown;
    bool alt = false;
    bool control = false;
    bool shift = false;

    KeyBind() = default;

    KeyBind(const KeyPressed &key) : code(key.code), alt(key.alt), control(key.control), shift(key.shift) {}

    bool operator==(const KeyBind &other) const = default;
};

namespace std
{
    template <>
    struct hash<KeyBind>
    {
        size_t operator()(const KeyBind &k) const
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

enum class When
{
    None,
    All,
    MainMenu,
    Playing
};

enum class Action
{
    None,
    Exit,
    Test,
    Sprint
};

KeyBind parseKeybind(string keyString);

std::pair<When, Action> parseWhenAction(string whenActionString);
