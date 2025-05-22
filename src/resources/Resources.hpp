#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../util/Basic.hpp"

using Path = std::filesystem::path;

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

    const sf::Texture &texture() const { return _texture; }

    // ================ Variables ================= //

private:
    Path _resourceDir;
    Path _texturePath;
    Path _fontPath;

    sf::Font _font;

    // resources
    sf::Texture _texture;
};