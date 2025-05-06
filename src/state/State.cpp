#include "State.hpp"

State::State(const Game& game, Configuration &config) : _game(game), _config(config)
{
}

void State::setup()
{
    _actionMap = setupActionMap();
    _config.loadKeyBinds(*this);
}

bool State::addKeyBind(const KeyBind &keyBind, const string &actionString)
{
    ActionID action = getActionID(actionString);
    if (action == ACTION_NONE)
        return false;

    if (getAction(keyBind) != action)
    {
        _keyBinds[keyBind] = action;
        return true;
    }
    else
    {
        return false;
    }
}

ActionID State::getAction(const KeyBind &keyBind) const
{
    auto it = _keyBinds.find(keyBind);
    if (it != _keyBinds.end())
        return it->second;

    return ACTION_NONE;
}

ActionID State::getActionID(const string &actionString) const
{
    auto it = _actionMap.find(actionString);
    if (it != _actionMap.end())
        return it->second;

    return ACTION_NONE;
}
