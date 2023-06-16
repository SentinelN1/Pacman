#pragma once

#include "StaticEntity.h"

const float CELL_SIZE = 64;
const sf::Color WALL_COLOR = sf::Color(33, 33, 222);

class Cell : public StaticEntity {
public:
    Cell(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(CELL_SIZE, CELL_SIZE);
        colour_ = WALL_COLOR;
    }
};

