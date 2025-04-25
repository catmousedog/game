#pragma once

#include <filesystem>

#include "../lib/json.hpp"

#include "Keybinds.hpp"

using json = nlohmann::json;
using Path = std::filesystem::path;

// ======= Constants ======= //
#define CONFIGURATION_DIR "config/"

class Configuration
{
    // ======= Construction ======= //
public:
    /**
     * @brief Constructor for the Configuration class.
     */
    Configuration();

private:
    void loadSettings();

    void loadKeyBindings();

    // ======= Getters ======= //
public:
    Action getKeybind(const sf::Event::KeyPressed& keyPressed);

    unsigned int windowWidth() const { return _windowWidth; }
    unsigned int windowHeight() const { return _windowHeight; }
    bool fullscreen() const { return _fullscreen; }

    // ======= Data ======= //
private:
    Path _configDir;
    
    Path _settingsPath;
    json _settingsJSON;

    Path _keyBindsPath;
    json _keyBindsJSON;

    // data
    unsigned int _windowWidth = 800;
    unsigned int _windowHeight = 600;

    std::unordered_map<KeyPressed, Action> _keyBinds;
};
