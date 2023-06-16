#pragma once

#include "StaticEntity.h"

const float GUM_SIZE = 2;
const sf::Color GUM_COLOR = sf::Color(255, 184, 151);

class Gum : public StaticEntity {
public:
    Gum(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(GUM_SIZE, GUM_SIZE);
        shape_ = sf::RectangleShape(size_);
        colour_ = GUM_COLOR;
    }
};
