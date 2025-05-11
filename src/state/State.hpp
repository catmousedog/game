#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../config/Configuration.hpp"
#include "../util/Utils.hpp"

class Game;

using ActionID = unsigned int;
using ActionMap = std::unordered_map<string, ActionID>;
using KeyMap = std::unordered_map<KeyBind, ActionID>;

constexpr ActionID ACTION_NONE = 0;

/**
 * @brief Macro to define an action map entry. This is used to define the action map in the
 * setupActionMap() function.
 * @param ACTION The action to define.
 * @return The action map entry: 'STATE'.'ACTION' -> STATE::ACTION
 */
#define ACTIONMAP_ENTRY(ACTION)                       \
    {                                                 \
        StringUtils::toLower(#ACTION), Action::ACTION \
    }

class State
{
    // ======= Construction ======= //
public:
    State(Game &game, Configuration &config);

    virtual ~State() = default;

    // ======= Setup ======= //

    /**
     * @brief Sets up the state. The default implementation loads the keybinds from the configuration.
     */
    virtual void setup();

private:
    /**
     * @brief Sets up the action map. This should return a mapping of action strings to action IDs.
     * The strings should point to the (untyped) Derived::Action enum, where Derived::Action::None
     * =ACTION_NONE is the first element.
     */
    virtual const ActionMap setupActionMap() const = 0;

    // ======= State ======= //
public:
    /**
     * @brief Updates the state.
     * @param dt Delta time since last frame.
     */
    virtual void update(double dt) = 0;

    /**
     * @brief Renders the state.
     * @param window The SFML window to render to.
     */
    virtual void render(sf::RenderWindow &window) = 0;

    // ======= Events ======= //

    /**
     * @brief Handles a sf::Event::KeyPressed event using the built in KeyMap.
     * @param keyPressed The KeyPressed event.
     */
    void handleKeyPressed(const sf::Event::KeyPressed &keyPressed);

    /**
     * @brief Handles a certain Derived::Acton. This is called from the handleKeyPressed.
     * @param action The action to handle.
     */
    virtual void handleAction(ActionID action) = 0;

    /**
     * @brief Handles a non-KeyPressed event.
     * @param event the event which is not of type sf::Event::KeyPressed.
     */
    virtual void handleEvent(const sf::Event &event) = 0;

    /**
     * @brief Returns the State name used in the keybinds.
     * @return The state name.
     */
    virtual string name() const = 0;

    /**
     * @brief Adds a KeyBind to the KeyBind map. The map is to the Derived::Action enum using
     * the action map defined in the setupActionMap().
     * @return True if the keybind was added, false if it was already present or failed.
     */
    bool addKeyBind(const KeyBind &keybind, const string &actionString);

private:
    /**
     * @brief Returns the action ID for a certain keybind in the KeyBind mapping.
     * @param keyPressed The keybind to check.
     * @return The action ID, or ACTION_NONE if not found.
     */
    ActionID getActionFromKeyBind(const KeyBind &keyPressed) const;

    /**
     * @brief Private function used to convert the action string to an action ID using
     * the action map defined in the setupActionMap().
     * @param actionString The action string to convert.
     * @return The action ID, or ACTION_NONE if not found.
     */
    ActionID getActionFromString(const string &actionString) const;

    // ======= Getters ======= //
protected:
    Configuration &config() const { return _config; }

    // ======= Variables ======= //
protected:
    Game &_game;

private:
    Configuration &_config;
    KeyMap _keyBinds;
    ActionMap _actionMap;
};
