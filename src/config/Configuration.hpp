#pragma once

#include <SFML/Graphics.hpp>

#include <yaml-cpp/yaml.h>

#include <filesystem>

#include "Keybinds.hpp"

using Path = std::filesystem::path;

class State;

class Configuration
{

    // =============== Construction =============== //
public:
    Configuration();

    void loadSettings();
    void loadKeyBinds(State &state) const;

    // ================= Getters ================== //

    sf::Vector2f absPos(const sf::Vector2f &pos) const;

    sf::Vector2f absPos(float relX, float relY) const;

    sf::Vector2i windowSize() const { return _windowSize; }

    float windowRatio() const { return static_cast<float>(_windowSize.x) / _windowSize.y; }

    uint frameRate() const { return _frameRate; }

    uint tickRate() const { return _tickRate; }

    bool zoomToMouse() const { return _zoomToMouse; }

    // ================ Variables ================= //

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

    // cached values
    sf::Vector2i _windowSize;
    uint _frameRate = 30;
    uint _tickRate = 20;
    bool _zoomToMouse = false;
};
