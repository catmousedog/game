#pragma once

#include "State.hpp"

class MainMenuState : public State
{
	// =============== Construction =============== //

  public:
	MainMenuState(Game& game);

	// ================== Setup =================== //

	void setup() override;

	// ================== State =================== //

	void update(GameTime& time) override;

	void render(sf::RenderTarget& target) override;

	// =============== SFML Events ================ //

	void handleEvent(const sf::RenderTarget& target, const sf::Event& event) override;

	string name() const override
	{
		return "MainMenu";
	};

	// ================= Actions ================== //

	void play();

	void exit();

	// ================ Variables ================= //

  private:
};
