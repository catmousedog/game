#include <SFML/Graphics/Vertex.hpp>

#include "Chunk.hpp"

// =============== Construction =============== //

Chunk::Chunk(int cx, int cy) : _cx(cx), _cy(cy)
{
    _renderable.vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    _renderable.vertices.resize(6 * CHUNK_SIZE * CHUNK_SIZE);
    _renderable.textureId = 0;
    _renderable.zIndex = 0;
}

// ================= Helpers ================== //

void Chunk::addQuad(float x, float y, const sf::Vector2f &texCoords)
{
    sf::Vertex vertex;

    vertex.position = getWorldPosition(x, y);
    vertex.texCoords = texCoords + sf::Vector2f(0, 0);
    vertex.color = sf::Color::Red;
    _renderable.vertices.append(vertex);

    vertex.position = getWorldPosition(x + 1, y);
    vertex.texCoords = texCoords + sf::Vector2f(1, 0);
    vertex.color = sf::Color::Green;
    _renderable.vertices.append(vertex);

    vertex.position = getWorldPosition(x, y + 1);
    vertex.texCoords = texCoords + sf::Vector2f(0, 1);
    vertex.color = sf::Color::Blue;
    _renderable.vertices.append(vertex);

    vertex.position = getWorldPosition(x + 1, y + 1);
    vertex.texCoords = texCoords + sf::Vector2f(1, 1);
    vertex.color = sf::Color::Red;
    _renderable.vertices.append(vertex);

    vertex.position = getWorldPosition(x + 1, y);
    vertex.texCoords = texCoords + sf::Vector2f(1, 0);
    vertex.color = sf::Color::Green;
    _renderable.vertices.append(vertex);

    vertex.position = getWorldPosition(x, y + 1);
    vertex.texCoords = texCoords + sf::Vector2f(0, 1);
    vertex.color = sf::Color::Blue;
    _renderable.vertices.append(vertex);
}

sf::Vector2f Chunk::getWorldPosition(float x, float y) const
{
    return sf::Vector2f(_cx * CHUNK_SIZE + x, _cy * CHUNK_SIZE + y);
}

// ================= Getters ================== //

const Chunk::Renderable &Chunk::getRenderable()
{
    if (_isDirty)
    {
        _isDirty = false;

        _renderable.vertices.clear();

        for (float x = 0; x < CHUNK_SIZE; x++)
            for (float y = 0; y < CHUNK_SIZE; y++)
                addQuad(x, y, {0, 0});
    }
    return _renderable;
}