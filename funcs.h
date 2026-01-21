#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>






void board(sf::RenderWindow& window, sf::RectangleShape& screen, float grid_size) {

    screen.setFillColor(sf::Color{ 0,0,0 });

    screen.setSize({ grid_size * 3 * 7, grid_size * 3 * 9 });
    const auto size = window.getSize();
    screen.setPosition(sf::Vector2f{ size.x / 2.f, size.y / 2.f });
    screen.setOrigin(screen.getGeometricCenter());

}

void rectangle_init(sf::RectangleShape& rect, sf::Vector2f pos, sf::Vector2f size) {

    rect.setSize(size);

    rect.setFillColor(sf::Color::Red);

    rect.setPosition(sf::Vector2f(pos.x / 2.f, pos.y / 2.f));
    rect.setOrigin(rect.getGeometricCenter());
}




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

