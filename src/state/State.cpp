#include "State.hpp"

#include "../Game.hpp"
#include "../util/Utils.hpp"
#include "../util/Error.hpp"

State::State(Game &game) : _game(game) {}

void State::setup()
{
    _game.config().loadKeyBinds(*this);
    _gui.setWindow(_game.window());
}

void State::loadWidgetsFromFile(const string &filePath)
{
    _gui.loadWidgetsFromFile(filePath);

    for (auto &widget : _gui.getWidgets())
    {
        string name = widget->getWidgetName().toStdString();

        Action* action = getAction(name);

        if (action)
        {
            tgui::Button *button = dynamic_cast<tgui::Button *>(widget.get());
            button->onPress(action->press);
        }
    }
}

void State::update(double dt)
{
}

void State::render(sf::RenderWindow &window)
{
    _gui.draw();
}

void State::handleEvent(const sf::RenderWindow &window, const sf::Event &event)
{
    _gui.handleEvent(event);
}

void State::handleKeyPressed(const sf::Event::KeyPressed &keyPressed)
{
    Action *action = _keyBinds[keyPressed];
    if (!action)
        return;

    switch (action->mode)
    {
    case Action::Mode::PRESS:
        action->press();
        break;
    case Action::Mode::TOGGLE:
        action->enabled = !action->enabled;
        break;
    case Action::Mode::HOLD:
        action->enabled = true;
        break;
    }
}

void State::handleKeyReleased(const sf::Event::KeyReleased &keyReleased)
{
    Action *action = _keyBinds[keyReleased];
    switch (action->mode)
    {
    case Action::Mode::PRESS:
        break;
    case Action::Mode::TOGGLE:
        // could add another member to Action to store the state
        // this way a toggle can only occur if the key is also released first
        break;
    case Action::Mode::HOLD:
        action->enabled = false;
        break;
    }
}

bool State::addKeyBind(const KeyBind &keyBind, const string &actionString)
{
    Action *action = getAction(actionString);
    if (!action)
        return false;

    _keyBinds[keyBind] = action;
    return true;
}

void State::addToggle(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    _actions.emplace(actionString, Action::createToggle());
}

void State::addHold(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    _actions.emplace(actionString, Action::createHold());
}

void State::addPress(string actionString, std::function<void()> &&press)
{
    actionString = StringUtils::toLower(actionString);
    _actions.emplace(actionString, Action::createPress(std::move(press)));
}

Action *State::getAction(string actionString)
{
    actionString = StringUtils::toLower(actionString);
    auto action_it = _actions.find(actionString);
    if (action_it == _actions.end())
        return nullptr;

    return action_it->second.get();
}

// Maybe remove this and instead just use a builtin function to set the button action to this
std::function<void()> &State::getPressAction(string actionString)
{
    Action *keyAction = getAction(actionString);
    if (!keyAction)
        PRINT_ERROR("Attempted to get 'press' from a non-existing Action {}", actionString);
    if (keyAction->mode != Action::Mode::PRESS)
        PRINT_ERROR("Attempted to get 'press' from a non-Press Action {}", actionString);

    return keyAction->press;
}