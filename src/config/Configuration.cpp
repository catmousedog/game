#include <fstream>

#include "Configuration.hpp"
#include "../util/Error.hpp"
#include "../util/Utils.hpp"
#include "../state/State.hpp"

namespace
{
    constexpr string CONFIGURATION_DIR = "config/";
}

Configuration::Configuration()
{
    _configDir = CONFIGURATION_DIR;
    _settingsPath = _configDir / "settings.yaml";
    _keyBindsPath = _configDir / "keybinds.yaml";

    try
    {
        _settingsYAML = YAML::LoadFile(_settingsPath.string());
        _keyBindsYAML = YAML::LoadFile(_keyBindsPath.string());
    }
    catch (const YAML::Exception &e)
    {
        PRINT_ERROR("Could not load settings or keybinds YAML: {}", e.what());
    }
}

void Configuration::loadSettings()
{
    try
    {
        uint width = _settingsYAML["windowWidth"].as<uint>();
        uint height = _settingsYAML["windowHeight"].as<uint>();
        _frameRate = _settingsYAML["frameRate"].as<uint>();
        _tickRate = _settingsYAML["tickRate"].as<uint>();
        _windowSize = sf::Vector2i(width, height);
    }
    catch (const YAML::Exception &e)
    {
        PRINT_ERROR("Error parsing settings.yaml: {}", e.what());
    }
}

void Configuration::loadKeyBinds(State &state) const
{
    if (!_keyBindsYAML[state.name()])
        return;

    for (const auto &actionNode : _keyBindsYAML[state.name()])
    {
        string actionName = actionNode.first.as<string>();
        const YAML::Node &keysNode = actionNode.second["keys"];

        vector<string> keyStrings;
        if (keysNode)
        {
            if (keysNode.IsSequence())
            {
                keyStrings = keysNode.as<vector<string>>();
            }
            else if (keysNode.IsScalar())
            {
                keyStrings.push_back(keysNode.as<string>());
            }
        }

        for (const auto &keyStr : keyStrings)
        {
            KeyBind keyBind = parseKeybind(keyStr);
            if (!state.addKeyBind(keyBind, actionName))
            {
                PRINT_ERROR("Failed to add keybind '{} -> {}'", keyStr, actionName);
            }
        }
    }
}

sf::Vector2f Configuration::absPos(const sf::Vector2f &relPos) const
{
    return {relPos.x * _windowSize.x, relPos.y * _windowSize.y};
}

sf::Vector2f Configuration::absPos(float relX, float relY) const
{
    return {relX * _windowSize.x, relY * _windowSize.y};
}
