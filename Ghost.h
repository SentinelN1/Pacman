#pragma once

#include "DynamicEntity.h"

const float GHOST_SPEED = 240;
const float GHOST_SIZE = 64;

class Ghost : public DynamicEntity {
    explicit Ghost(const sf::Vector2f &position) : DynamicEntity(position,
                                                                 GHOST_SPEED,
                                                                 GHOST_SIZE,
                                                                 sf::Color::White) {}
};
//
//class Blinky : public Ghost {
//public:
//    explicit Blinky(const sf::Vector2f &position) : Ghost(position) {
//    }
//};
//
//class Clyde : public Ghost {
//public:
//    Clyde(const sf::Vector2f &position) {
//        position_ = position;
//        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
//        speed_ = GHOST_SPEED;
//    }
//};
//
//class Inky : public Ghost {
//public:
//    Inky(const sf::Vector2f &position) {
//        position_ = position;
//        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
//        speed_ = GHOST_SPEED;
//    }
//};
//
//class Pinky : public Ghost {
//public:
//    Pinky(const sf::Vector2f &position) {
//        position_ = position;
//        size_ = sf::Vector2f(GHOST_SIZE, GHOST_SIZE);
//        speed_ = GHOST_SPEED;
//    }
//};
