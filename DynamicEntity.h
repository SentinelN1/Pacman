#pragma once

#include "Entity.h"
#include <cmath>

class DynamicEntity : public Entity {
protected:
    float speed_;
    sf::Vector2f direction_;

public:
    sf::Vector2f getDirection() const {
        return direction_;
    }

    sf::Vector2f setDirection(const sf::Vector2f direction) {
        float norm = sqrt(direction.x * direction.x + direction.y * direction.y);
        direction_ = direction / norm;
        return direction_;
    }

    float setSpeed(const float &speed) {
        speed_ = abs(speed);
        return speed_;
    }

    virtual sf::Vector2f update(const float &elapsed_time, const std::vector<Cell *> &cells) {
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