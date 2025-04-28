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
    for (const auto &[whenActionString, items] : _keyBindsJSON.items())
    {
        string keyString = items.at("key").get<string>();

        KeyBind keyBind = parseKeybind(keyString);
        auto whenAction = parseWhenAction(whenActionString);

        When when = whenAction.first;
        Action action = whenAction.second;

        // when or action was not found
        if (when == When::None || action == Action::None)
            continue;

        // when this state
        if (when != When::All && state.when() != when)
            continue;

        if (!state.addKeyBind(keyBind, action))
        {
            PRINT_ERROR("Duplicate keybind {}->{}", keyString, whenActionString);
            continue;
        }
    }
}
