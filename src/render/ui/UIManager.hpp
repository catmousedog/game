#pragma once

#include "Game.hpp"
#include "util/Basic.hpp"

#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/Widgets/TextArea.hpp>

class UIManager
{
    // =============== Construction =============== //

  public:
    UIManager(tgui::Gui& gui);

    // ================== Setup =================== //

    void setup();

    // ================== State =================== //

    void update(GameTime& time);

    // ================ Variables ================= //
  private:
    tgui::Gui& _gui;
    tgui::TextArea::Ptr _textArea;  
};