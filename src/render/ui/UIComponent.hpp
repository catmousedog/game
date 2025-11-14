#pragma once

#include "util/Basic.hpp"

#include <TGUI/Backend/SFML-Graphics.hpp>

class UIComponent
{
	// =============== Construction =============== //
  public:
	UIComponent(string file);

	// ================== Setup =================== //

	void setup(tgui::Gui& gui);

	// ================= Getters ================== //

	tgui::Widget::Ptr getWidget(tgui::Gui& gui, string name);

	// ================ Variables ================= //

  private:
	const string _file;
};