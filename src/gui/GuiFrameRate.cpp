#include "GuiFrameRate.hpp"
#include "../util/Error.hpp"

GuiFrameRate::GuiFrameRate(Configuration &config)
    : GuiElement(config),
      _text(config.font(), "frames")
{
    _text.setStyle(sf::Text::Bold);
    _text.setFillColor(sf::Color::Red);
    _text.setCharacterSize(18);
}

void GuiFrameRate::update(double dt) {}

void GuiFrameRate::render(sf::RenderWindow &window)
{
    window.draw(_text);
}

void GuiFrameRate::handleEvent(const sf::Event &) {}

void GuiFrameRate::setDt(double updateGoal, double renderGoal, const array<double, 3> &dt)
{
    double SFML_ms = dt[0] * 1000.;
    double update_ms = dt[1] * 1000.;
    double render_ms = dt[2] * 1000.;
    double update_p = dt[1] / updateGoal * 100.;
    double render_p = dt[2] / renderGoal * 100.;
    string str = std::vformat("SFML:\t{:.0f}ms\nupdate:\t{:.0f}ms\t{:.1f}%\nrender:\t{:.0f}ms\t{:.1f}%",
                              std::make_format_args(SFML_ms, update_ms, update_p, render_ms, render_p));
    _text.setString(str);
}
