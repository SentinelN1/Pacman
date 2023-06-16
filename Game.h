#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "StaticEntity.h"
#include "Pacman.h"
#include "Ghost.h"

class Game {
private:
    unsigned int cell_size_;
    unsigned int width_;
    unsigned int height_;

    std::vector<std::vector<Cell *>> cells_;

    std::vector<Ghost *> ghosts_;
    Pacman *pacman_;

//    UserInterface UI;

public:
    Game(const unsigned int &cell_size, const unsigned int &width, const unsigned int &height) {
        cell_size_ = cell_size;
        width_ = width;
        height_ = height;
        pacman_ = new Pacman(sf::Vector2f(100, 100));
    }

    sf::Vector2u getScreenSize() const {
        return cell_size_ * sf::Vector2u(width_, height_);
    }

    std::vector<Ghost *> getGhosts() {
        return ghosts_;
    }

    std::vector<std::vector<Cell *>> getCells() {
        return cells_;
    }

    Pacman *getPacman() {
        return pacman_;
    }

    void update(const float &elapsed_time) {
        if (pacman_) {
            pacman_->update(elapsed_time);
        }

        for (auto ghost: ghosts_) {
            ghost->update(elapsed_time);
        }
    }

    void render(sf::RenderWindow &window) const {
        if (pacman_) {
            pacman_->render(window);
        }

        for (auto ghost: ghosts_) {
            ghost->render(window);
        }
    }

    ~Game() {
        delete pacman_;
        for (auto ghost: ghosts_) {
            delete ghost;
        }
    }
};

