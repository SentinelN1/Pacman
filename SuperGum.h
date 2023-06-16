#pragma once

#include "StaticEntity.h"

const float SUPERGUM_SIZE = 6;
const sf::Color SUPERGUM_COLOR = sf::Color(255, 184, 151);

class SuperGum : public StaticEntity {
public:
    SuperGum(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(SUPERGUM_SIZE, SUPERGUM_SIZE);
        shape_ = sf::RectangleShape(size_);
        colour_ = SUPERGUM_COLOR;
    }
};
