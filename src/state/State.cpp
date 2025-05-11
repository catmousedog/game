#include "State.hpp"

State::State(Game &game, Configuration &config) : _game(game), _config(config)
{
}

void State::setup()
{
    _actionMap = setupActionMap();
    _config.loadKeyBinds(*this);
}

void State::handleKeyPressed(const sf::Event::KeyPressed &keyPressed)
{
    ActionID action = getActionFromKeyBind(keyPressed);

    if (action != ACTION_NONE)
        handleAction(action);
}

bool State::addKeyBind(const KeyBind &keyBind, const string &actionString)
{
    ActionID action = getActionFromString(actionString);
    if (action == ACTION_NONE)
        return false;

    if (getActionFromKeyBind(keyBind) != action)
    {
        _keyBinds[keyBind] = action;
        return true;
    }
    else
    {
        return false;
    }
}

ActionID State::getActionFromKeyBind(const KeyBind &keyBind) const
{
    auto it = _keyBinds.find(keyBind);
    if (it != _keyBinds.end())
        return it->second;

    return ACTION_NONE;
}

ActionID State::getActionFromString(const string &actionString) const
{
    auto it = _actionMap.find(StringUtils::toLower(actionString));
    if (it != _actionMap.end())
        return it->second;

    return ACTION_NONE;
}
