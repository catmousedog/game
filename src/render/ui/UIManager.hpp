#pragma once

#include "GameContext.hpp"
#include "components/DebugPanel.hpp"

#include <TGUI/Backend/SFML-Graphics.hpp>

class UIManager
{
	// =============== Construction =============== //

  public:
	UIManager(tgui::Gui& gui);

	// ================== Setup =================== //

	void setup();

	// ================== State =================== //

	void update(GameTime& time);

	// =============== SFML Events ================ //

	void handleEvent(const sf::RenderTarget& target, const sf::Event& event);

	// ================ Variables ================= //
  private:
	tgui::Gui& _gui;
	DebugPanel _debugPanel;
};