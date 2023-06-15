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
    explicit Entity(const sf::Vector2f &position = sf::Vector2f(0, 0), const sf::Vector2f &size = sf::Vector2f(0, 0)) {
        position_ = position;
        size_ = size;
        shape_ = sf::RectangleShape(size);
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

    sf::FloatRect getBounds() {
        return shape_.getGlobalBounds();
    }

    void render(sf::RenderWindow &window) {
        window.draw(shape_);
    }

    void update() {
        shape_.setPosition(position_);
        shape_.setFillColor(colour_);
    }
};

class Cell : public Entity {
private:

public:

};

class Gum : public Entity {
private:
    const unsigned int GUM_SIZE = 2;
    const sf::Color GUM_COLOR = sf::Color(255, 184, 151);

public:
    Gum() {
        colour_ = GUM_COLOR;
        size_ = sf::Vector2f(GUM_SIZE, GUM_SIZE);
    }

    ~Gum() = default;
};


//class SuperPacGum : public StaticEntity {
//public:
//
//    SuperPacGum(const float &x, const float &y, const float &s) {
//        x_pos = x;
//        y_pos = y;
//        size = s;
//    }
//
//    void render(sf::RenderWindow &window) {
//        shape.setFillColor(sf::Color(255, 183, 174));
//        shape.setSize(sf::Vector2f(size, size));
//        shape.setPosition(sf::Vector2f(x_pos, y_pos));
//    }
//};

class DynamicEntity : public Entity {
protected:
    float speed_;
    sf::Vector2f direction_;

public:
    sf::Vector2f getDirection() const {
        return direction_;
    }

    sf::Vector2f setDirection(const sf::Vector2f direction) {
        direction_ = direction;
        return direction_;
    }

    float getSpeed() const {
        return speed_;
    }

    float setSpeed(const float &speed) {
        speed_ = speed;
        return speed_;
    }

//    sf::Vector2f updatePosition(float elapsed_time) {
//        position_ += speed_ * direction_;
//        return position_;
//    }
};

class Pacman : public DynamicEntity {
private:
    const sf::Color PACMAN_COLOR = sf::Color(255, 255, 0);
    const float PACMAN_SPEED = 120; // pixels per second.
    const unsigned int PACMAN_SIZE = 13; // pixels

public:
    void updatePacmanDirection(const sf::Event &event) {
//        direction_ = sf::Vector2f(0, 0);
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
    }
};

class Ghost : DynamicEntity {

};

class Blinky : public Ghost {

};

class Clyde : public Ghost {

};

class Inky : public Ghost {

};

class Pinky : public Ghost {

};
