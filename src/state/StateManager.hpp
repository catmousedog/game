#pragma once

#include <stack>
#include <memory>
#include <queue>

#include "State.hpp"

class StateManager
{

public:
    StateManager(Game &game, Configuration &config)
        : _game(game), _config(config) {}

    /**
     * @brief Queues a state to be pushed onto the stack.
     * @tparam T The type of state to push.
     */
    template <typename T>
    void push()
    {
        _pending.push([this]()
                      { pushState<T>(); });
    }

    /**
     * @brief Queues a state to be popped from the stack.
     * If the top state is not of type T, it will not be popped.
     * @tparam T The type of state to pop.
     */
    template <typename T>
    void pop()
    {
        _pending.push([this]()
                      { popState<T>(); });
    }

    /**
     * @brief Performs all queued state changes.
     */
    void performQueued()
    {
        while (!_pending.empty())
        {
            auto action = std::move(_pending.front());
            _pending.pop();
            action();
        }
    }

    /**
     * @brief Gets the current state.
     * @return A pointer to the current state, or nullptr if there are no states.
     */
    State *current()
    {
        return _states.empty() ? nullptr : _states.top().get();
    }

    /**
     * @returns true if the stack is empty, false otherwise.
     */
    bool empty() const
    {
        return _states.empty();
    }

private:
    template <typename T>
    void pushState()
    {
        auto state = std::make_unique<T>(_game, _config);
        state->setup();
        _states.push(std::move(state));
    }

    template <typename T>
    void popState()
    {
        if (!_states.empty())
        {
            if (dynamic_cast<T *>(_states.top().get()))
                _states.pop();
        }
    }

    std::stack<std::unique_ptr<State>> _states;
    std::queue<std::function<void()>> _pending;
    Game &_game;
    Configuration &_config;
};
