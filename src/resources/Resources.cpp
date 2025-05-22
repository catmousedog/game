#include "Resources.hpp"
#include "../util/Error.hpp"

#include <SFML/Graphics.hpp>

Resources::Resources()
{
    _resourceDir = RESOURCE_DIR;
    _texturePath = _resourceDir / "textures/texture.png";
    _fontPath = _resourceDir / "fonts/FreeMono.ttf";
}

void Resources::loadTextures()
{
    if (!_texture.loadFromFile(_texturePath))
        PRINT_ERROR("Failed to load texture: {}", _texturePath.string());
}

void Resources::loadFonts()
{
    if (!_font.openFromFile(_fontPath))
        PRINT_ERROR("Failed to load font: {}", _fontPath.string());
}