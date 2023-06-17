#pragma once

#include "DynamicEntity.h"

const float PACMAN_SIZE = 36;
const float PACMAN_SPEED = 200;

const sf::Color PACMAN_COLOUR = sf::Color::Yellow;

class Pacman : public DynamicEntity {
private:
    unsigned int gums_eaten;
    unsigned int supergums_eaten;
public:
    explicit Pacman(const sf::Vector2f &position) : DynamicEntity(position,
                                                                  PACMAN_SPEED,
                                                                  PACMAN_SIZE,
                                                                  PACMAN_COLOUR) {
        gums_eaten = 0;
        supergums_eaten = 0;
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

    void eatGum(std::list<Gum *> &gums, std::list<SuperGum *> &supergums) {
        for (auto it = gums.begin(); it != gums.end(); ++it) {
            if (getBounds().intersects((*it)->getBounds())) {
                gums.erase(it);
                ++gums_eaten;
                break;
            }
        }
        for (auto it = supergums.begin(); it != supergums.end(); ++it) {
            if (getBounds().intersects((*it)->getBounds())) {
                supergums.erase(it);
                ++gums_eaten;
                break;
            }
        }
    }
};