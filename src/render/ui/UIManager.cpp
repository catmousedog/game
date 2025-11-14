#include "UIManager.hpp"

// =============== Construction =============== //

UIManager::UIManager(tgui::Gui& gui) : _gui(gui) {}

// ================== Setup =================== //

void UIManager::setup()
{
	_debugPanel.setup(_gui);
}

// ================== State =================== //

void UIManager::update(GameTime& time)
{
	float dt = 1 / time.dt;
	float tps = 1 / time.update;
	float fps = 1 / time.render;
	_debugPanel.setText(std::format("tps: {}\nups: {}\nfps: {}", dt, tps, fps));
}

// =============== SFML Events ================ //

void UIManager::handleEvent(const sf::RenderTarget& target, const sf::Event& event)
{
	_gui.handleEvent(event);
}