#pragma once

#include <filesystem>
#include <SFML/Graphics/Text.hpp>

#include "../../lib/json.hpp"

#include "Keybinds.hpp"

using json = nlohmann::json;
using Path = std::filesystem::path;

// ======= Constants ======= //
#define CONFIGURATION_DIR "config/"
#define RESOURCE_DIR "resources/"

class State;

class Configuration
{
    // ======= Construction ======= //
public:
    Configuration();

    // ======= Load ======= //

    void loadSettings();

    void loadKeyBinds(State &state) const;

    // ======= Getters ======= //
public:
    // convert relative pos to absolute pos
    sf::Vector2f absPos(const sf::Vector2f &pos) const;

    sf::Vector2f absPos(float x, float y) const;
    

    // resources
    const sf::Font &font() const { return _font; }

    // settings
    sf::Vector2u windowSize() const { return _windowSize; }
    unsigned int frameRate() const { return _frameRate; }
    unsigned int tickRate() const { return _tickRate; }

    // ======= Setters ======= //

    // ======= Variables ======= //
private:
    // config
    Path _configDir;

    Path _settingsPath;
    json _settingsJSON;

    Path _keyBindsPath;
    json _keyBindsJSON;

    // resources
    Path _resourceDir;

    Path _fontPath;
    sf::Font _font;

    // loaded settings
    sf::Vector2u _windowSize;
    unsigned int _frameRate = 30;
    unsigned int _tickRate = 20;
};
