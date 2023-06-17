#pragma once

#include "DynamicEntity.h"

const float GHOST_SPEED = 125;
const float GHOST_SIZE = 20;

class Ghost : public DynamicEntity {
public:
    explicit Ghost(const sf::Vector2f &position) : DynamicEntity(position, GHOST_SPEED, GHOST_SIZE, sf::Color::White) {}
};


const sf::Color BLICKY_COLOR = sf::Color::Red;

class Blinky : public Ghost {
public:
    explicit Blinky(const sf::Vector2f &position) : Ghost(position) {
        colour_ = BLICKY_COLOR;
    }
};

const sf::Color CLYDE_COLOR = sf::Color(255, 184, 71);

class Clyde : public Ghost {
public:
    explicit Clyde(const sf::Vector2f &position) : Ghost(position) {
        colour_ = CLYDE_COLOR;
    }
};

const sf::Color INKY_COLOR = sf::Color(0, 255, 222);

class Inky : public Ghost {
public:
    explicit Inky(const sf::Vector2f &position) : Ghost(position) {
        colour_ = INKY_COLOR;
    }
};

const sf::Color PINKY_COLOR = sf::Color(255, 184, 222);

class Pinky : public Ghost {
public:
    explicit Pinky(const sf::Vector2f &position) : Ghost(position) {
        colour_ = PINKY_COLOR;
    }
};
