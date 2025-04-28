#pragma once

#include <filesystem>

#include "../../lib/json.hpp"

#include "Keybinds.hpp"
#include "../state/State.hpp"

using json = nlohmann::json;
using Path = std::filesystem::path;

using KeyMap = std::unordered_map<KeyBind, Action>;

// ======= Constants ======= //
#define CONFIGURATION_DIR "config/"

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
    unsigned int windowWidth() const { return _windowWidth; }
    unsigned int windowHeight() const { return _windowHeight; }

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
};
