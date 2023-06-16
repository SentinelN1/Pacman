#pragma once

#include "DynamicEntity.h"

const float GHOST_SPEED = 2;
const float GHOST_SIZE = 16;

class Ghost : public DynamicEntity {

};

class Blinky : public Ghost {
public:
    Blinky(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
        speed_ = GHOST_SPEED;
    }
};

class Clyde : public Ghost {
public:
    Clyde(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
        speed_ = GHOST_SPEED;
    }
};

class Inky : public Ghost {
public:
    Inky(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
        speed_ = GHOST_SPEED;
    }
};

class Pinky : public Ghost {
public:
    Pinky(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
        speed_ = GHOST_SPEED;
    }
};
