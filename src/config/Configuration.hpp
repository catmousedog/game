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
    // resources
    const sf::Font &font() const { return _font; }

    // settings
    unsigned int windowWidth() const { return _windowWidth; }
    unsigned int windowHeight() const { return _windowHeight; }
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
    unsigned int _windowWidth = 800;
    unsigned int _windowHeight = 600;
    unsigned int _frameRate = 30;
    unsigned int _tickRate = 20;
};
