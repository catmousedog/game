#pragma once

#include "util/Basic.hpp"

#include <functional>

/**
 * @brief Action performed when pressing a keybind.
 * This can be:
 * 1. Mode::PRESS   single press preforming an action
 * 2. Mode::TOGGLE  toggle switch when pressed
 * 3. Mode::HOLD    hold key that must be held down to be enabled
 */
class Action
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

	static unique_ptr<Action> createPress(std::function<void()>&& press)
	{
		unique_ptr<Action> keyAction(new Action());
		keyAction->mode = Mode::PRESS;
		keyAction->press = std::move(press);
		return keyAction;
	}

	static unique_ptr<Action> createToggle(bool enabled = false)
	{
		unique_ptr<Action> keyAction(new Action());
		keyAction->mode = Mode::TOGGLE;
		keyAction->enabled = enabled;
		return keyAction;
	}

	static unique_ptr<Action> createHold(bool enabled = false)
	{
		unique_ptr<Action> keyAction(new Action());
		keyAction->mode = Mode::HOLD;
		keyAction->enabled = enabled;
		return keyAction;
	}

	std::optional<std::function<void()>> getPress() const
	{
		if (mode == Mode::PRESS)
			return press;
		return std::nullopt;
	}

  private:
	Action() {}

	// ================ Variables ================= //

  public:
	Mode mode;
	std::function<void()> press = nullptr;
	bool enabled = false;
};