#pragma once

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::RectangleShape shape_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    sf::Texture texture_;
    sf::Color colour_;

public:
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

    sf::FloatRect getBounds() {
        return shape_.getGlobalBounds();
    }

    void render(sf::RenderWindow &window) {
        shape_.setSize(size_);
        shape_.setPosition(position_);
        shape_.setFillColor(colour_);
        window.draw(shape_);
    }
};
