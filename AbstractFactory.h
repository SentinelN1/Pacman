#pragma once

#include "Ghost.h"

class GhostFactory {
public:
    virtual Ghost *createGhost(const sf::Vector2f &, const sf::Vector2f &) = 0;
};

class PinkyFactory : public GhostFactory {
public:
    Pinky *createGhost(const sf::Vector2f &position, const sf::Vector2f &size) {
        return new Pinky(position);
    }
};

class InkyFactory : public GhostFactory {
    Inky *createGhost(const sf::Vector2f &position, const sf::Vector2f &size) {
        return new Inky(position);
    }
};

class BlinkyFactory : public GhostFactory {
    Blinky *createGhost(const sf::Vector2f &position, const sf::Vector2f &size) {
        return new Blinky(position);
    }
};

class ClydeFactory : public GhostFactory {
    Clyde *createGhost(const sf::Vector2f &position, const sf::Vector2f &size) {
        return new Clyde(position);
    }
};