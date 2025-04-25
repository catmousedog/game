#include <fstream>

#include "Configuration.hpp"
#include "Error.hpp"

Configuration::Configuration() : _configDir(CONFIGURATION_DIR)
{
    _settingsPath = (_configDir / "settings.json");
    _keyBindsPath = (_configDir / "keybinds.json");
    loadSettings();
    loadKeyBindings();
}

void Configuration::loadSettings()
{
    _settingsJSON = json::parse(std::ifstream(_settingsPath));

    _windowWidth = _settingsJSON["windowWidth"].get<unsigned int>();
    _windowHeight = _settingsJSON["windowHeight"].get<unsigned int>();
}

void Configuration::loadKeyBindings()
{
    _keyBindsJSON = json::parse(std::ifstream(_keyBindsPath));
    // _keyBinds.reserve(_keyBindsJSON.size());

    for (const auto &[actionString, items] : _keyBindsJSON.items())
    {
        string keyString = items.at("key").get<string>();

        KeyPressed keyPressed = parseKeybind(keyString);
        Action action = parseAction(actionString);

        auto it = _keyBinds.find(keyPressed);
        if (it != _keyBinds.end())
        {
            if (it->second == action)
            {
                PRINT_ERROR("Duplicate keybind {}->{}", keyString, actionString);
                continue;
            }
        }

        _keyBinds[keyPressed] = action;
    }
}

Action Configuration::getKeybind(const sf::Event::KeyPressed &keyPressed)
{
    // convert SFML keyPressed to KeyPressed
    KeyPressed key = {keyPressed.code, keyPressed.alt, keyPressed.control, keyPressed.shift};
    
    auto it = _keyBinds.find(key);
    if (it != _keyBinds.end())
        return it->second;
    else
        return Action::None;
}