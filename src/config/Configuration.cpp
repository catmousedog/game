#include <fstream>

#include "Configuration.hpp"
#include "../util/Error.hpp"
#include "../util/Utils.hpp"
#include "../state/State.hpp"

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

    _resourceDir = RESOURCE_DIR;
    _fontPath = _resourceDir / "fonts/FreeMono.ttf";

    if (!_font.openFromFile(_fontPath))
        PRINT_ERROR("Failed to load font: {}", _fontPath.string());
}

void Configuration::loadSettings()
{
    try
    {
        unsigned int width = _settingsYAML["windowWidth"].as<unsigned int>();
        unsigned int height = _settingsYAML["windowHeight"].as<unsigned int>();
        _frameRate = _settingsYAML["frameRate"].as<unsigned int>();
        _tickRate = _settingsYAML["tickRate"].as<unsigned int>();
        _windowSize = sf::Vector2u(width, height);
    }
    catch (const YAML::Exception &e)
    {
        PRINT_ERROR("Error parsing settings.yaml: {}", e.what());
    }
}

void Configuration::loadKeyBinds(State &state) const
{
    string currentState = state.name();

    if (!_keyBindsYAML[currentState])
        return;

    for (const auto &actionNode : _keyBindsYAML[currentState])
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
            else
            {
                PRINT_DEBUG("{}: Added keybind '{} -> {}'", currentState, keyStr, actionName);
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
