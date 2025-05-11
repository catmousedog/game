#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

class StateManager
{

public:
    StateManager(Game &game, Configuration &config)
        : _game(game), _config(config) {}

    /**
     * @brief Pushes a new state onto the stack.
     * @tparam T The type of the state to push.
     */
    template <typename T>
    void push()
    {
        auto state = std::make_unique<T>(_game, _config);
        state->setup();
        push(std::move(state));
    }

    /**
     * @brief Pops the current state from the stack.
     */
    void pop()
    {
        if (!_states.empty())
            _states.pop();
    }

    /**
     * @brief Replaces the current state with a new state.
     * @tparam T The type of the state to push.
     */
    template <typename T>
    void replace()
    {
        pop();
        push<T>();
    }

    /**
     * @brief Removes all states and pushes a new state.
     * @tparam T The type of the state to push.
     */
    template <typename T>
    void set()
    {
        while (!_states.empty())
            _states.pop();
        push<T>();
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
    void push(std::unique_ptr<State> state)
    {
        _states.push(std::move(state));
    }

    std::stack<std::unique_ptr<State>> _states;
    Game &_game;
    Configuration &_config;
};
