#include "DebugPanel.hpp"

// =============== Construction =============== //

DebugPanel::DebugPanel() : UIComponent("resources/TGUI/DebugPanel.txt") {}

// ================== Setup =================== //

void DebugPanel::setup(tgui::Gui& gui)
{
	UIComponent::setup(gui);

	auto widget = getWidget(gui, "DebugPanel");
	_textArea = widget->cast<tgui::TextArea>();
}

// ================= Setters ================== //

void DebugPanel::setText(string text)
{
	_textArea->setText(text);
}