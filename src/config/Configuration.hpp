#pragma once

#include <filesystem>
#include <SFML/Graphics/Text.hpp>
#include <yaml-cpp/yaml.h>

#include "Keybinds.hpp"

using Path = std::filesystem::path;

class State;

class Configuration
{
public:
    Configuration();

    void loadSettings();
    void loadKeyBinds(State &state) const;

    // Getters
    sf::Vector2f absPos(const sf::Vector2f &pos) const;
    sf::Vector2f absPos(float x, float y) const;

    const sf::Font &font() const { return _font; }
    sf::Vector2u windowSize() const { return _windowSize; }
    unsigned int frameRate() const { return _frameRate; }
    unsigned int tickRate() const { return _tickRate; }

private:
    // paths
    Path _configDir;
    Path _settingsPath;
    Path _keyBindsPath;

    Path _resourceDir;
    Path _fontPath;

    // settings
    YAML::Node _settingsYAML;
    YAML::Node _keyBindsYAML;

    // resources
    sf::Font _font;

    // cached values
    sf::Vector2u _windowSize;
    unsigned int _frameRate = 30;
    unsigned int _tickRate = 20;
};
