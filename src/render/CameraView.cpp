#include "CameraView.hpp"

// =============== Construction =============== //

void CameraView::setup(sf::Vector2f center, sf::Vector2f size, bool zoomToMouse)
{
	_zoomToMouse = zoomToMouse;

	_view.setCenter(center);
	_view.setSize(size);
}

// ================== State =================== //

void CameraView::setView(sf::RenderTarget& target)
{
	target.setView(_view);
}

// =============== SFML Events ================ //

void CameraView::handleEvent(const sf::RenderTarget& target, const sf::Event& event)
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
			sf::Vector2f worldStart = target.mapPixelToCoords(_dragStartMouse, _view);
			sf::Vector2f worldNow = target.mapPixelToCoords(mouse->position, _view);
			sf::Vector2f delta = worldStart - worldNow;
			_view.setCenter(_dragStartView + delta);
		}
	}
	else if (event.is<sf::Event::MouseWheelScrolled>())
	{
		const auto mouse = event.getIf<sf::Event::MouseWheelScrolled>();

		float factor = 1 - mouse->delta * ZOOM_FACTOR;
		if (_zoomToMouse)
		{
			sf::Vector2f beforeZoom = target.mapPixelToCoords(mouse->position, _view);
			_view.zoom(factor);
			_zoom *= factor;
			sf::Vector2f afterZoom = target.mapPixelToCoords(mouse->position, _view);

			_view.move(beforeZoom - afterZoom);
		}
		else
		{
			_view.zoom(factor);
		}
	}
}
