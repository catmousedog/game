#pragma once

#include "State.hpp"
#include <stack>
#include <memory>

class StateManager
{
private:
    std::stack<std::unique_ptr<State>> _states;

public:
    void push(std::unique_ptr<State> state) {
        _states.push(std::move(state));
    }

    template <typename T>
    void pushState(const Configuration& config) {
        auto state = std::make_unique<T>();
        state->setup(config);
        push(std::move(state));
    }

    void pop() {
        if (!_states.empty()) _states.pop();
    }

    State* current() {
        return _states.empty() ? nullptr : _states.top().get();
    }

    bool empty() const {
        return _states.empty();
    }
};
