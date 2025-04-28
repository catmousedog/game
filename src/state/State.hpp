#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../config/Keybinds.hpp"

class Configuration;

class State
{
public:
    virtual ~State() = default;

protected:
    State();

public:
    virtual void setup(const Configuration &config);

public:
    virtual void handleAction(Action action) = 0;

    virtual void update(float dt) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    virtual When when() const = 0;

    Action getAction(const KeyBind &keyPressed);

    bool addKeyBind(const KeyBind &keybind, Action action);

private:
    std::unordered_map<KeyBind, Action> _keyBinds;
};
