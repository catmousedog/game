#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <unordered_map>
#include <memory>

#include "../config/KeyAction.hpp"
#include "../config/Keybinds.hpp"

using KeyActionMap = std::unordered_map<string, std::unique_ptr<KeyAction>>;
using KeyMap = std::unordered_map<KeyBind, KeyAction *>;

class Game;
class Configuration;
class Resources;

class State
{

    // =============== Construction =============== //

public:
    State(Game &game);

    virtual ~State() = default;

    // ================== Setup =================== //

    /**
     * @brief Sets up the state. The derived function should fill the _actions map
     * using addKeyAction() before calling State::setup().
     */
    virtual void setup();

    // ================== State =================== //

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

    // =============== SFML Events ================ //

    /**
     * @brief Handles a non sf::Event::KeyPressed event.
     * @param event The sf::Event to handle.
     */
    virtual void handleEvent(const sf::Event &event) = 0;

    /**
     * @return The case-sensitive identifier of the state.
     */
    virtual string name() const = 0;

    // ================= Keybinds ================= //

    /**
     * @brief Handles an sf::Event::KeyPressed event, by calling the appropriate KeyAction.
     * @param keyPressed The key pressed event.
     */
    void handleKeyPressed(const sf::Event::KeyPressed &keyPressed);

    void handleKeyReleased(const sf::Event::KeyReleased &keyReleased);

    /**
     * @brief Adds a KeyBind->KeyAction to the keybind map of the state.
     * This also checks if the action is valid, i.e. if it is in the _actions map.
     * @param keybind The KeyBind to add.
     * @param actionString The identifier of the KeyAction to bind to.
     * @return True if the keybind was added, false otherwise.
     */
    bool addKeyBind(const KeyBind &keybind, const string &actionString);

protected:
    /**
     * @brief Private helper function to add a KeyBind->KeyAction to the keybind
     * map of the state. This should be called in the setup() of the derived class.
     * @param actionString The identifier of the KeyAction to register.
     * @param action The KeyAction to call when the action is triggered.
     * @return True if the action was registered, false otherwise.
     */
    void addToggle(string actionString);

    void addHold(string actionString);

    void addPress(string actionString, std::function<void()> &&press);

    KeyAction *getKeyAction(string actionString);

    std::function<void()> &getPressAction(string actionString);

    // ================ Variables ================= //

protected:
    Game &_game;

private:
    KeyMap _keyBinds;
    KeyActionMap _actions;
};
