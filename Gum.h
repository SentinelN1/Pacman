#pragma once

#include "StaticEntity.h"

const float GUM_SIZE = 16;
const sf::Color GUM_COLOR = sf::Color(255, 184, 151);

class Gum : public StaticEntity {
public:
    explicit Gum(const sf::Vector2f &position) : StaticEntity(position, GUM_SIZE, GUM_COLOR) {}
};
