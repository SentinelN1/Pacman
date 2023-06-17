#pragma once

#include "StaticEntity.h"

const float SUPERGUM_SIZE = 16;
const sf::Color SUPERGUM_COLOR = sf::Color(255, 184, 151);

class SuperGum : public StaticEntity {
public:
    explicit SuperGum(const sf::Vector2f &position) : StaticEntity(position, SUPERGUM_SIZE, SUPERGUM_COLOR) {}
};
