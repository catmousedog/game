#include "ResourceManager.hpp"

#include "util/Error.hpp"

#include <SFML/Graphics.hpp>

// =============== Construction =============== //

ResourceManager::ResourceManager()
{
    _resourceDir = RESOURCE_DIR;
    _texturePath = _resourceDir / "textures/texture.png";
    _fontPath = _resourceDir / "fonts/FreeMono.ttf";
}

void ResourceManager::loadTextures() {}

void ResourceManager::loadFonts()
{
    if (!_font.openFromFile(_fontPath))
        PRINT_ERROR("Failed to load font: {}", _fontPath.string());
}