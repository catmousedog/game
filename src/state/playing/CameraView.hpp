#pragma once

#include "../../util/Basic.hpp"

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
    void initView(sf::Vector2i windowSize)
    {
        _view.setSize(static_cast<sf::Vector2f>(windowSize));
    }

    // ================== State =================== //

    void setView(sf::RenderWindow &window)
    {
        window.setView(_view);
    }

    // =============== SFML Events ================ //

    void handleEvent(const sf::RenderWindow &window, const sf::Event &event)
    {
        if (event.is<sf::Event::MouseButtonPressed>())
        {
            const auto mouse = event.getIf<sf::Event::MouseButtonPressed>();

            if (mouse->button == sf::Mouse::Button::Left)
            {
                _dragging = true;
                _dragStartMouse = mouse->position;
                _dragStartView = _view.getCenter();
            }
        }
        else if (event.is<sf::Event::MouseButtonReleased>())
        {
            const auto mouse = event.getIf<sf::Event::MouseButtonReleased>();

            if (mouse->button == sf::Mouse::Button::Left)
            {
                _dragging = false;
            }
        }
        else if (event.is<sf::Event::MouseMoved>())
        {
            const auto mouse = event.getIf<sf::Event::MouseMoved>();

            if (_dragging)
            {
                sf::Vector2i delta = _dragStartMouse - mouse->position;
                _view.setCenter(_dragStartView + static_cast<sf::Vector2f>(delta) * _zoom);
            }
        }
        else if (event.is<sf::Event::MouseWheelScrolled>())
        {
            const auto mouse = event.getIf<sf::Event::MouseWheelScrolled>();

            sf::Vector2f beforeZoom = window.mapPixelToCoords(mouse->position, _view);
            float factor = 1 - mouse->delta * ZOOM_FACTOR;
            _view.zoom(factor);
            _zoom *= factor;
            sf::Vector2f afterZoom = window.mapPixelToCoords(mouse->position, _view);

            _view.move(beforeZoom - afterZoom);
        }
    }

    // ================ Variables ================= //

private:
    sf::View _view;

    bool _dragging = false;
    sf::Vector2f _dragStartView;
    sf::Vector2i _dragStartMouse;
    float _zoom = 1.0f;
};
