#pragma once

#include "util/Basic.hpp"

#include <SFML/Graphics/VertexArray.hpp>

namespace
{
constexpr uint CHUNK_SIZE = 16;
}

class Chunk
{
  public:
    // ================= Classes ================== //

    struct Renderable
    {
        sf::VertexArray vertices; // might change to sf::VertexBuffer later
        int textureId;
        int zIndex; // maybe obsolete?
    };

    // =============== Construction =============== //

    Chunk(int cx, int cy);

    // ================= Helpers ================== //

    void addQuad(float x, float y, const sf::Vector2f& texCoords);

    sf::Vector2f getWorldPosition(float x, float y) const;

    // ================= Getters ================== //

    const Renderable& getRenderable();

    // ================ Variables ================= //

  private:
    // whether the chunk needs to be rerendered
    bool _isDirty = true;
    Renderable _renderable;

    // chunk coordinates (in chunk space)
    int _cx;
    int _cy;
};