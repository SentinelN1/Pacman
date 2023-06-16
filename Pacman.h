#pragma once

#include "DynamicEntity.h"

const float PACMAN_SIZE = 48;
const float PACMAN_SPEED = 160;
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

    sf::Vector2f update(const float &elapsed_time, const std::vector<Cell *> &cells) override {
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

        sf::Vector2f position = position_ + elapsed_time * speed_ * direction_;

        sf::RectangleShape shape;
        shape.setPosition(position);
        shape.setSize(size_);

        bool collision = false;
        for (auto cell: cells) {
            if (cell && shape.getGlobalBounds().intersects(cell->getBounds())) {
                collision = true;
                break;
            }
        }

        if (!collision) {
            position_ = position;
        }
        return position_;
    }
};