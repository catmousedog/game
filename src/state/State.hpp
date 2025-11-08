#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include <unordered_map>
#include <memory>

#include "config/Action.hpp"
#include "config/Keybinds.hpp"

/** Map of unique Actions, indexed by their name. */
using ActionSet = std::unordered_map<string, unique_ptr<Action>>;

/** Map of non-unique Actions, indexed by their KeyBind. */
using KeyBindMap = std::unordered_map<KeyBind, Action *>;

class Game;
class ConfigManager;
class ResourceManager;

class State
{

    // =============== Construction =============== //

public:
    State(Game &game);

    virtual ~State();

    // ================== Setup =================== //

    /**
     * @brief Sets up the state. The derived function should fill the _actions map
     * using addKeyAction() before calling State::setup().
     */
    virtual void setup();

    void loadWidgetsFromFile(const string &filePath);

    // ================== State =================== //

public:
    /**
     * @brief Updates the state.
     * @param dt Delta time since last frame.
     */
    virtual void update(double dt);

    /**
     * @brief Renders the state.
     * @param target The SFML target to render to.
     */
    virtual void render(sf::RenderTarget &target);

    // =============== SFML Events ================ //

    /**
     * @brief Handles a non sf::Event::KeyPressed event.
     * @param event The sf::Event to handle.
     */
    virtual void handleEvent(const sf::RenderTarget &target, const sf::Event &event);

    /**
     * @return The case-sensitive identifier of the state.
     */
    virtual string name() const = 0;

    // ================= Keybinds ================= //

    /**
     * @brief Handles an sf::Event::KeyPressed event, by calling the appropriate Action.
     * @param keyPressed The key pressed event.
     */
    void handleKeyPressed(const sf::Event::KeyPressed &keyPressed);

    void handleKeyReleased(const sf::Event::KeyReleased &keyReleased);

    /**
     * @brief Adds a KeyBind->Action to the keybind map of the state.
     * This also checks if the action is valid, i.e. if it is in the _actions map.
     * @param keybind The KeyBind to add.
     * @param actionString The identifier of the Action to bind to.
     * @return True if the keybind was added, false otherwise.
     */
    bool addKeyBind(const KeyBind &keybind, const string &actionString);

protected:
    /**
     * @brief Private helper function to add a KeyBind->Action to the keybind
     * map of the state. This should be called in the setup() of the derived class.
     * @param actionString The identifier of the Action to register.
     * @param action The Action to call when the action is triggered.
     * @return True if the action was registered, false otherwise.
     */
    void addToggle(string actionString);

    void addHold(string actionString);

    void addPress(string actionString, std::function<void()> &&press);

    Action *getAction(string actionString);

    // ================ Variables ================= //

protected:
    Game &_game;
    tgui::Gui _gui;

private:
    KeyBindMap _keyBinds;
    ActionSet _actions;
};
