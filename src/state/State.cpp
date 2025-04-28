#include "State.hpp"
#include "../util/Error.hpp"
#include "../config/Configuration.hpp"

State::State() {}

void State::setup(const Configuration &config)
{
    _actionMap = setupActionMap();
    config.loadKeyBinds(*this);
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