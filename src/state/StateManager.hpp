#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

class StateManager
{

public:
    void push(std::unique_ptr<State> state)
    {
        _states.push(std::move(state));
    }

    template <typename T>
    void pushState(const Game& game, Configuration &config)
    {
        auto state = std::make_unique<T>(game, config);
        state->setup();
        push(std::move(state));
    }

    void pop()
    {
        if (!_states.empty())
            _states.pop();
    }

    State *current()
    {
        return _states.empty() ? nullptr : _states.top().get();
    }

    bool empty() const
    {
        return _states.empty();
    }

private:
    std::stack<std::unique_ptr<State>> _states;
};
