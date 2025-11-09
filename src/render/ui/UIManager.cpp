#include "UIManager.hpp"

#include "util/Utils.hpp"

// =============== Construction =============== //

UIManager::UIManager(tgui::Gui& gui) : _gui(gui) {}

// ================== Setup =================== //

void UIManager::setup()
{
    _gui.loadWidgetsFromFile("resources/TGUI/test.txt", false);

    auto t = _gui.getWidgets().front();

    if (t->getWidgetType() == "TextArea")
    {
        _textArea = t->cast<tgui::TextArea>();
    }
}

// ================== State =================== //

void UIManager::update(GameTime& time)
{
    float tps = 20 * time.lagUpdate;
    float fps = 60 * time.lagRender;
    _textArea->setText(
        StringUtils::toLower(std::to_string(tps) + " tps\n" + std::to_string(fps) + " fps"));
}
