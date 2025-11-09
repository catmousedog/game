#pragma once

#include "TextureManager.hpp"
#include "util/Basic.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <TGUI/Font.hpp>

using Path = std::filesystem::path;

// ================ Constants ================= //

namespace
{
constexpr string RESOURCE_DIR = "resources/";
}

class ResourceManager
{
    // =============== Construction =============== //

  public:
    ResourceManager();

    void loadTextures();

    void loadFonts();

    // ================= Getters ================== //

    const sf::Font& font() const
    {
        return _font;
    }

    // ================ Variables ================= //

  private:
    Path _resourceDir;
    Path _texturePath;
    Path _fontPath;

    sf::Font _font;

    // resources
    TextureManager _textureManager;
};