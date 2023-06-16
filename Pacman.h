#pragma once

#include "DynamicEntity.h"

const float PACMAN_SIZE = 32;
const float PACMAN_SPEED = 200;

const sf::Color PACMAN_COLOUR = sf::Color::Yellow;

class Pacman : public DynamicEntity {
public:
    explicit Pacman(const sf::Vector2f &position) {
        position_ = position;
        size_ = sf::Vector2f(PACMAN_SIZE, PACMAN_SIZE);
        speed_ = PACMAN_SPEED;
        direction_ = sf::Vector2f(0, 0);
        colour_ = PACMAN_COLOUR;
    }

    sf::Vector2f updateDirection() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction_ = sf::Vector2f(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction_ = sf::Vector2f(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction_ = sf::Vector2f(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction_ = sf::Vector2f(1, 0);
        }
        return direction_;
    }
};