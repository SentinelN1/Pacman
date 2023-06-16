#pragma once

#include "Entity.h"
#include <cmath>

class DynamicEntity : public Entity {
protected:
    float speed_{};
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

    virtual sf::Vector2f update(const float &elapsed_time) {
        position_ += elapsed_time * speed_ * direction_;
        return position_;
    }

    float getSpeed() const {
        return speed_;
    }
};