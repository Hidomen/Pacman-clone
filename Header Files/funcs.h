#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


sf::VertexArray drawGrid(sf::RenderWindow& window, unsigned cellSize) {

    sf::Color color = sf::Color::White;
    const auto size = window.getSize();
    sf::VertexArray lines(sf::PrimitiveType::Lines);

    // Dikey çizgiler
    for (unsigned x = 0; x <= size.x; x += cellSize)
    {
        lines.append({ sf::Vector2f((float)x, 0.f), color });
        lines.append({ sf::Vector2f((float)x, (float)size.y), color });
    }

    // Yatay çizgiler
    for (unsigned y = 0; y <= size.y; y += cellSize)
    {
        lines.append({ sf::Vector2f(0.f, (float)y), color });
        lines.append({ sf::Vector2f((float)size.x, (float)y), color });
    }

    return lines;
}

