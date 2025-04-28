#include "MainMenuState.hpp"
#include "../util/Error.hpp"

#include <iostream>

MainMenuState::MainMenuState() : State() {}

void MainMenuState::handleAction(Action action)
{
    if (action == Action::Test)
        PRINT_DEBUG("test{}", 0);
}

void MainMenuState::update(float dt) {}

void MainMenuState::render(sf::RenderWindow &window) {}