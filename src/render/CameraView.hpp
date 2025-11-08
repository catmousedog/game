#pragma once

#include "util/Basic.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

// ================ Constants ================= //

namespace
{
    constexpr float ZOOM_FACTOR = 0.05f;
}

class CameraView
{
    // =============== Construction =============== //

public:
    void setup(sf::Vector2f center, sf::Vector2f size, bool zoomToMouse);

    // ================== State =================== //

    void setView(sf::RenderTarget &target);

    // =============== SFML Events ================ //

    void handleEvent(const sf::RenderTarget &target, const sf::Event &event);

    // ================ Variables ================= //

private:
    sf::View _view;

    bool _zoomToMouse = false;

    bool _dragging = false;
    sf::Vector2f _dragStartView;
    sf::Vector2i _dragStartMouse;
    float _zoom = 1.0f;
};
