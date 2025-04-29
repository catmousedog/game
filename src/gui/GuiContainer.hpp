#pragma once

#include <stack>
#include <memory>

#include "GuiElement.hpp"

/**
 * @brief A container holding multiple GuiElements.
 */
class GuiContainer
{
public:
    void push(std::unique_ptr<GuiElement> state)
    {
        _guiElements.push_back(std::move(state));
    }

    template <typename T>
    void pushGUI()
    {
        push(std::make_unique<T>());
    }

    bool empty() const
    {
        return _guiElements.empty();
    }

private:
    std::vector<std::unique_ptr<GuiElement>> _guiElements;
};
