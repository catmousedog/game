#pragma once

#include <functional>

#include "../util/Basic.hpp"

/**
 * @brief Action performed when pressing a keybind.
 * This can be:
 * 1. Mode::PRESS   single press preforming an action
 * 2. Mode::TOGGLE  toggle switch when pressed
 * 3. Mode::HOLD    hold key that must be held down to be enabled
 */
class KeyAction
{

    // =================== Enum =================== //

public:
    enum class Mode
    {
        PRESS,
        TOGGLE,
        HOLD
    };

    // =============== Construction =============== //

    static unique_ptr<KeyAction> createPress(std::function<void()> &&press)
    {
        unique_ptr<KeyAction> keyAction(new KeyAction());
        keyAction->mode = Mode::PRESS;
        keyAction->press = std::move(press);
        return keyAction;
    }

    static unique_ptr<KeyAction> createToggle(bool enabled = false)
    {
        unique_ptr<KeyAction> keyAction(new KeyAction());
        keyAction->mode = Mode::TOGGLE;
        keyAction->enabled = enabled;
        return keyAction;
    }

    static unique_ptr<KeyAction> createHold(bool enabled = false)
    {
        unique_ptr<KeyAction> keyAction(new KeyAction());
        keyAction->mode = Mode::HOLD;
        keyAction->enabled = enabled;
        return keyAction;
    }

private:
    KeyAction() {}

    // ================ Variables ================= //

public:
    Mode mode;
    std::function<void()> press = nullptr;
    bool enabled = false;
};