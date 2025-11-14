#pragma once

#include "Game.hpp"
#include "render/CameraView.hpp"
#include "render/ui/UIManager.hpp"
#include "universe/Universe.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class RenderManager
{
	// =============== Construction =============== //

  public:
	RenderManager(Game& game, Universe& universe, tgui::Gui& gui);

	// ================== Setup =================== //

	void setup();

	// ================== State =================== //

	void update(GameTime& time);

	void render(sf::RenderTarget& target);

	// =============== SFML Events ================ //

	void handleEvent(const sf::RenderTarget& target, const sf::Event& event);

	// ================ Variables ================= //

  private:
	Game& _game;

	ResourceManager& _resourceManager;

	Universe& _universe;

	UIManager _uiManager;

	CameraView _cameraView;
};