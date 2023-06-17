#pragma once

#include "StaticEntity.h"

const float CELL_SIZE = 36;
const sf::Color WALL_COLOR = sf::Color(33, 33, 222);

class Cell : public StaticEntity {
public:
    explicit Cell(const sf::Vector2f &position) : StaticEntity(position, CELL_SIZE, WALL_COLOR) {}
};

