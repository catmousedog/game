#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <TGUI/Font.hpp>

#include "../util/Basic.hpp"

using Path = std::filesystem::path;

// ================ Constants ================= //

namespace
{
    constexpr string RESOURCE_DIR = "resources/";
}

class Resources
{
    // =============== Construction =============== //

public:
    Resources();

    void loadTextures();

    void loadFonts();

    // ================= Getters ================== //

    const sf::Font &font() const { return _font; }

    const tgui::Font &tfont() const { return _tfont; }

    const sf::Texture &texture() const { return _texture; }

    // ================ Variables ================= //

private:
    Path _resourceDir;
    Path _texturePath;
    Path _fontPath;

    sf::Font _font;
    tgui::Font _tfont;

    // resources
    sf::Texture _texture;
};