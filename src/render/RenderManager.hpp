#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "render/CameraView.hpp"
#include "render/UIManager.hpp"
#include "universe/Universe.hpp"
#include "Game.hpp"

class RenderManager
{
    // =============== Construction =============== //

public:
    RenderManager(Game &game, Universe &universe);

    void setup();

    // ================== State =================== //

    void render(sf::RenderTarget &target);

    // =============== SFML Events ================ //

    void handleEvent(const sf::RenderTarget &target, const sf::Event &event);

    // ================ Variables ================= //

private:
    Game &_game;

    ResourceManager &_resourceManager;

    Universe &_universe;

    UIManager _uiManager;

    CameraView _cameraView;
};