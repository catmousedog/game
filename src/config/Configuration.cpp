#include <fstream>

#include "Configuration.hpp"
#include "../util/Error.hpp"
#include "../util/Utils.hpp"

Configuration::Configuration()
{
    _configDir = CONFIGURATION_DIR;
    _settingsPath = (_configDir / "settings.json");
    _keyBindsPath = (_configDir / "keybinds.json");

    _keyBindsJSON = json::parse(std::ifstream(_keyBindsPath));
    _settingsJSON = json::parse(std::ifstream(_settingsPath));
}

void Configuration::loadSettings()
{
    _windowWidth = _settingsJSON["windowWidth"].get<unsigned int>();
    _windowHeight = _settingsJSON["windowHeight"].get<unsigned int>();
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
