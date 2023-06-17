#pragma once

#include <SFML/Graphics.hpp>

class StaticEntity {
protected:
    sf::RectangleShape shape_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    sf::Texture texture_;
    sf::Color colour_;

public:
    explicit StaticEntity(const sf::Vector2f &position, const float &size, const sf::Color colour) {
        position_ = position;
        size_ = sf::Vector2f(size, size);
        colour_ = colour;
        shape_ = sf::RectangleShape(size_);
    }

    sf::Vector2f getPosition() const {
        return position_;
    }

    sf::Vector2f setPosition(const sf::Vector2f &position) {
        position_ = position;
        return position_;
    }

    sf::Vector2f getSize() const {
        return size_;
    }

    sf::Vector2f setSize(const sf::Vector2f &size) {
        size_ = size;
        return size_;
    }

    sf::Vector2f setSize(const float &size) {
        size_ = sf::Vector2f(size, size);
        return size_;
    }

    sf::FloatRect getBounds() const {
        return shape_.getGlobalBounds();
    }

    void render(sf::RenderWindow &window) {
        if (position_.x < -size_.x) {
            position_.x = window.getSize().x + size_.x;
        }
        if (position_.x > window.getSize().x + size_.x) {
            position_.x = -size_.x;
        }
        if (position_.y < -size_.y) {
            position_.y = window.getSize().y + size_.y;
        }
        if (position_.y > window.getSize().y + size_.y) {
            position_.y = -size_.y;
        }

        shape_.setSize(size_);
        shape_.setPosition(position_);
        shape_.setFillColor(colour_);
        window.draw(shape_);
    }
};
