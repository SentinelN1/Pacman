#pragma once

#include <vector>
#include <list>
#include <random>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Gum.h"
#include "SuperGum.h"
#include "Pacman.h"
#include "Ghost.h"
//#include "AbstractFactory.h"
#include "UserInterface.h"

const std::vector<std::string> MAP
        {"### ##### ###",
         "#A.........*#",
         "#.####.####.#",
         "#.#*.....B#.#",
         "#.#.#####.#.#",
         "#...#...#...#",
         "#.#.#.#.#.#.#",
         " .#...P...#. ",
         "#.#.#.#.#.#.#",
         "#...#...#...#",
         "#.#.#####.#.#",
         "#.#C.....*#.#",
         "#.####.####.#",
         "#*.........D#",
         "### ##### ###"};

const float WALL_PROBABILITY = 0.2;

class Game {
private:
    float cell_size_;
    size_t map_width_;
    size_t map_height_;

    std::vector<Cell *> cells_;
    std::list<Gum *> gums_;
    std::list<SuperGum *> supergums_;
    std::list<Ghost *> ghosts_;
    Pacman *pacman_;

    UserInterface UI_;

public:
    Game() {
        // Generate map
        cell_size_ = CELL_SIZE;

        std::vector<std::string> map = MAP;

        map_height_ = map.size();
        map_width_ = map[0].size(); // Верим

        cells_ = std::vector<Cell *>(map_width_ * map_height_);

        for (size_t y = 0; y < map_height_; ++y) {
            std::string str = map[y];
            for (size_t x = 0; x < map_width_; ++x) {
                sf::Vector2f position(cell_size_ * x, cell_size_ * y);
                if (str[x] == '#') {
                    cells_[y * map_width_ + x] = new Cell(position);
                }
                if (str[x] == '.') {
                    gums_.push_back(
                            new Gum(position + 0.5f * sf::Vector2f(CELL_SIZE - GUM_SIZE, CELL_SIZE - GUM_SIZE)));
                }
                if (str[x] == '*') {
                    supergums_.push_back(new SuperGum(
                            position + 0.5f * sf::Vector2f(CELL_SIZE - SUPERGUM_SIZE, CELL_SIZE - SUPERGUM_SIZE)));
                }
                if (str[x] == 'P') {
                    pacman_ = new Pacman(sf::Vector2f(
                            position + 0.5f * sf::Vector2f(CELL_SIZE - PACMAN_SIZE, CELL_SIZE - PACMAN_SIZE)));
                }
            }
        }

    }

    sf::Vector2f getScreenSize() const {
        return cell_size_ * sf::Vector2f(map_width_, map_height_);
    }

    std::list<Ghost *> getGhosts() {
        return ghosts_;
    }

    std::vector<Cell *> getCells() {
        return cells_;
    }

    Pacman *getPacman() {
        return pacman_;
    }

    void update(const float &elapsed_time) {
        if (pacman_) {
            pacman_->updateDirection();
            pacman_->update(elapsed_time, cells_);
            pacman_->eatGum(gums_, supergums_);
        }

//        for (auto ghost: ghosts_) {
//            ghost->update(elapsed_time, cells_);
//        }
    }

    void render(sf::RenderWindow &window) const {
        for (auto gum: gums_) {
            gum->render(window);
        }

        for (auto supergum: supergums_) {
            supergum->render(window);
        }

        for (auto ghost: ghosts_) {
            ghost->render(window);
        }

        for (auto cell: cells_) {
            if (cell) {
                cell->render(window);
            }
        }

        if (pacman_) {
            pacman_->render(window);
        }
    }

    ~Game() {
        delete pacman_;
        for (auto ghost: ghosts_) {
            delete ghost;
        }
        for (auto cell: cells_) {
            delete cell;
        }
        for (auto gum: gums_) {
            delete gum;
        }
        for (auto supergum: supergums_) {
            delete supergum;
        }
    }
};

