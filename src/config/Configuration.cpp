#include <fstream>

#include "Configuration.hpp"
#include "../util/Error.hpp"
#include "../util/Utils.hpp"
#include "../state/State.hpp"

Configuration::Configuration()
{
    _configDir = CONFIGURATION_DIR;
    _settingsPath = (_configDir / "settings.json");
    _keyBindsPath = (_configDir / "keybinds.json");

    _keyBindsJSON = json::parse(std::ifstream(_keyBindsPath));
    _settingsJSON = json::parse(std::ifstream(_settingsPath));

    _resourceDir = RESOURCE_DIR;
    _fontPath = (_resourceDir / "fonts/FreeMono.ttf");

    if (!_font.openFromFile(_fontPath))
        PRINT_ERROR("Failed to load font: {}", _fontPath.string());
}

void Configuration::loadSettings()
{
    unsigned int windowWidth = _settingsJSON["windowWidth"].get<unsigned int>();
    unsigned int windowHeight = _settingsJSON["windowHeight"].get<unsigned int>();
    _windowSize = sf::Vector2u(windowWidth, windowHeight);
    _frameRate = _settingsJSON["frameRate"].get<unsigned int>();
    _tickRate = _settingsJSON["tickRate"].get<unsigned int>();
}

void Configuration::loadKeyBinds(State &state) const
{
    for (const auto &[stateActionString, items] : _keyBindsJSON.items())
    {
        string keyString = items.at("key").get<string>();

        KeyBind keyBind = parseKeybind(keyString);
        auto [stateString, actionString] = parseAction(stateActionString);

        // when or action was not found
        if (stateString.empty() || actionString.empty())
        {
            PRINT_ERROR("State.Action '{}' not recognized", actionString);
            continue;
        }

        // skip not this state
        if (stateString != StringUtils::toLower(state.name()))
            continue;

        if (!state.addKeyBind(keyBind, actionString))
        {
            PRINT_ERROR("Could not add keybind: {}.{}->{}", stateString, keyString, actionString);
            continue;
        }
    }
}

sf::Vector2f Configuration::absPos(const sf::Vector2f &pos) const
{
    return sf::Vector2f(pos.x * _windowSize.x, pos.y * _windowSize.y);
}

sf::Vector2f Configuration::absPos(float x, float y) const
{
    return sf::Vector2f(x * _windowSize.x, y * _windowSize.y);
}