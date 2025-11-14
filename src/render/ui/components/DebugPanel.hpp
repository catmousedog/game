#pragma once

#include "render/ui/UIComponent.hpp"

#include <TGUI/Widgets/TextArea.hpp>

struct DebugPanel : public UIComponent
{
	// =============== Construction =============== //

	DebugPanel();

	// ================== Setup =================== //

	void setup(tgui::Gui& gui);

	// ================= Setters ================== //

	void setText(string text);

	// ================ Variables ================= //

  private:
	tgui::TextArea::Ptr _textArea;
};