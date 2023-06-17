#pragma once

#include "StaticEntity.h"
#include <cmath>

class DynamicEntity : public StaticEntity {
protected:
    float speed_;
    sf::Vector2f direction_;
//    sf::CircleShape shape_;

public:
    explicit DynamicEntity(const sf::Vector2f &position,
                           const float &speed,
                           const float &size,
                           const sf::Color colour) : StaticEntity(position, size, colour) {
        speed_ = speed;
        direction_ = sf::Vector2f(0, 0);
    }

    sf::Vector2f getDirection() const {
        return direction_;
    }

    sf::Vector2f setDirection(const sf::Vector2f direction) {
        // Normalize direction vector
        float norm = sqrt(direction.x * direction.x + direction.y * direction.y);
        direction_ = direction / norm;
        return direction_;
    }

    float setSpeed(const float &speed) {
        speed_ = abs(speed);
        return speed_;
    }

    sf::Vector2f update(const float &elapsed_time, const std::vector<Cell *> &cells) {
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

    float getSpeed() const {
        return speed_;
    }
};