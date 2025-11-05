#include "GuiInfo.hpp"
#include "../util/Error.hpp"

GuiInfo::GuiInfo(const sf::Font &font, const Configuration &config)
    : _text(font, "frames")
{
    sf::Vector2f windowSize = toVec2f(config.windowSize());
    _text.setStyle(sf::Text::Bold);
    _text.setFillColor(sf::Color::White);
    _text.setOutlineColor(sf::Color::Black);
    _text.setOutlineThickness(1.f);
    _text.setCharacterSize(18);

    auto box = _text.getGlobalBounds();
    // _text.setPosition()
}

void GuiInfo::update(double dt) {}

void GuiInfo::render(sf::RenderWindow &window)
{
    window.draw(_text);
}

void GuiInfo::handleEvent(const sf::RenderWindow &window, const sf::Event &) {}

void GuiInfo::setDt()
{
    _text.setString("test");
}
