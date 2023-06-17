#pragma once

#include "Ghost.h"

class GhostFactory {
public:
    GhostFactory() = default;

    ~GhostFactory() = default;

    virtual Ghost *createGhost(const sf::Vector2f &) = 0;
};

class BlinkyFactory : public GhostFactory {
    Blinky *createGhost(const sf::Vector2f &position) {
        return new Blinky(position);
    }
};

class ClydeFactory : public GhostFactory {
    Clyde *createGhost(const sf::Vector2f &position) {
        return new Clyde(position);
    }
};

class InkyFactory : public GhostFactory {
    Inky *createGhost(const sf::Vector2f &position) {
        return new Inky(position);
    }
};

class PinkyFactory : public GhostFactory {
public:
    Pinky *createGhost(const sf::Vector2f &position) {
        return new Pinky(position);
    }
};
