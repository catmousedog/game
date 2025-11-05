#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "../util/Basic.hpp"
#include "../render/CameraView.hpp"
#include "../world/Grid.hpp"
#include "../Game.hpp"

class Renderer
{
    // =============== Construction =============== //

public:
    Renderer();

    void setup(Game& game, Grid& grid);

    // ================== State =================== //

    void render(sf::RenderWindow &window);

    // =============== SFML Events ================ //

    void handleEvent(const sf::RenderWindow &window, const sf::Event &event);

    // ================ Variables ================= //

private:
    CameraView _cameraView;
};