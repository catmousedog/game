#include "State.hpp"

State::State(Game &game, Configuration &config) : _game(game), _config(config) {}

void State::setup()
{
    _config.loadKeyBinds(*this);
}

void State::handleKeyPressed(const sf::Event::KeyPressed &keyPressed)
{
    KeyAction *action = _keyBinds[keyPressed];
    if (!action)
        return;

    switch (action->mode)
    {
    case KeyAction::Mode::PRESS:
        action->press();
        break;
    case KeyAction::Mode::TOGGLE:
        action->enabled = !action->enabled;
        break;
    case KeyAction::Mode::HOLD:
        action->enabled = true;
        break;
    }
}

void State::handleKeyReleased(const sf::Event::KeyReleased &keyReleased)
{
    KeyAction *action = _keyBinds[keyReleased];
    switch (action->mode)
    {
    case KeyAction::Mode::PRESS:
        break;
    case KeyAction::Mode::TOGGLE:
        // could add another member to KeyAction to store the state
        // this way a toggle can only occur if the key is also released first
        break;
    case KeyAction::Mode::HOLD:
        action->enabled = false;
        break;
    }
}

bool State::addKeyBind(const KeyBind &keyBind, const string &actionString)
{
    KeyAction *action = getKeyAction(actionString);
    if (!action)
        return false;

    _keyBinds[keyBind] = action;
    return true;
}

void State::addToggle(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    _actions.emplace(actionString, KeyAction::createToggle());
}

void State::addHold(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    _actions.emplace(actionString, KeyAction::createHold());
}

void State::addPress(string actionString, std::function<void()> &&press)
{
    actionString = StringUtils::toLower(actionString);
    _actions.emplace(actionString, KeyAction::createPress(std::move(press)));
}

KeyAction *State::getKeyAction(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    auto action_it = _actions.find(actionString);
    if (action_it == _actions.end())
        return nullptr;

    return action_it->second.get();
}

std::function<void()> &State::getPressAction(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    KeyAction *keyAction = getKeyAction(actionString);
    if (!keyAction)
        PRINT_ERROR("Attempted to get 'press' from a non-existing KeyAction {}", actionString);
    if (keyAction->mode != KeyAction::Mode::PRESS)
        PRINT_ERROR("Attempted to get 'press' from a non-Press KeyAction {}", actionString);

    return keyAction->press;
}