#include "State.hpp"
#include "../util/Error.hpp"
#include "../config/Configuration.hpp"

State::State()
{
}

void State::setup(const Configuration &config)
{
    config.loadKeyBinds(*this);
}

Action State::getAction(const KeyBind &keyBind)
{
    auto it = _keyBinds.find(keyBind);
    if (it != _keyBinds.end())
        return it->second;
    else
        return Action::None;
}

bool State::addKeyBind(const KeyBind &keyBind, Action action)
{
    if (action == Action::None)
    {
        PRINT_ERROR("None keybind encountered: {}->None", (int)keyBind.code);
        return false;
    }

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