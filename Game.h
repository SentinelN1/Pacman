#pragma once

#include <vector>
#include <random>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Gum.h"
#include "Pacman.h"
#include "Ghost.h"
#include "AbstractFactory.h"

const std::vector<std::string> MAP
        {"###  ######  ###",
         "#              #",
         "# ############ #",
         "# #          # #",
         "# # ###        #",
         "#   #          #",
         "# # #          #",
         "  # #           ",
         "  #             ",
         "# # #          #",
         "#   #          #",
         "# # #          #",
         "# #            #",
         "# ####         #",
         "#              #",
         "###  ######  ###"};

const unsigned int WIDTH = 16;
const unsigned int HEIGHT = 16;
const float WALL_PROBABILITY = 0.2;


std::vector<Cell *> GenerateMap(const std::vector<std::string> &map, const float &cell_size = CELL_SIZE) {
    size_t map_height = map.size();
    size_t map_width = map[0].size(); // Верим
    std::vector<Cell *> cells(map_width * map_height);
    for (size_t y = 0; y < map_height; ++y) {
        std::string str = map[y];
        for (size_t x = 0; x < map_width; ++x) {
            if (str[x] == '#') {
                sf::Vector2f position(x * cell_size, y * cell_size);
                cells[y * map_width + x] = new Cell(position);
            }
        }
    }
    return cells;
}

std::vector<Cell *> GenerateRandomMap(const size_t &map_width_ = WIDTH,
                                      const size_t &map_height_ = HEIGHT,
                                      const float &wall_probability = WALL_PROBABILITY,
                                      const float &cell_size_ = CELL_SIZE) {
    std::vector<Cell *> cells_(map_width_ * map_height_);
    for (size_t y = 0; y < map_height_; ++y) {
        for (size_t x = 0; x < map_width_; ++x) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> dist(0, 1);
            float value = dist(gen);
            if (value < wall_probability) {
                sf::Vector2f position(cell_size_ * x, cell_size_ * y);
                cells_[y * map_width_ + x] = new Cell(sf::Vector2f(position));
            }
        }
    }
    return cells_;
}

class Game {
private:
    float cell_size_;
    unsigned int map_width_;
    unsigned int map_height_;

    std::vector<Cell *> cells_;
    std::vector<Ghost *> ghosts_;
    Pacman *pacman_;

//    UserInterface UI;

public:
    Game() {
        cell_size_ = CELL_SIZE;
        map_width_ = WIDTH;
        map_height_ = HEIGHT;
        pacman_ = new Pacman(sf::Vector2f(cell_size_ * map_width_ / 2, cell_size_ * map_height_ / 2));

        // Generate walls
        cells_ = GenerateMap(MAP);
    }

    sf::Vector2f getScreenSize() const {
        return cell_size_ * sf::Vector2f(map_width_, map_height_);
    }

    std::vector<Ghost *> getGhosts() {
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
        }

        for (auto ghost: ghosts_) {
            ghost->update(elapsed_time, cells_);
        }
    }

    void render(sf::RenderWindow &window) const {
        if (pacman_) {
            pacman_->render(window);
        }

        for (auto ghost: ghosts_) {
            ghost->render(window);
        }

        for (auto cell: cells_) {
            if (cell) {
                cell->render(window);
            }
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
    }
};

