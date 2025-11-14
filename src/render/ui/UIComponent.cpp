#include "UIComponent.hpp"

// =============== Construction =============== //

UIComponent::UIComponent(string file) : _file(file) {}

// ================== Setup =================== //

void UIComponent::setup(tgui::Gui& gui)
{
	gui.loadWidgetsFromFile(_file, false);
}

// ================= Getters ================== //

tgui::Widget::Ptr UIComponent::getWidget(tgui::Gui& gui, string name)
{
	for (const auto& widget : gui.getWidgets())
		if (widget->getWidgetName() == name)
			return widget;
	return nullptr;
}
