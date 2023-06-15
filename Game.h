#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
//#include "UserInterface.h"

class Game {
private:
    unsigned int cell_size_;
    unsigned int width_;
    unsigned int height_;

    std::vector<Entity *> entities_;
    std::vector<DynamicEntity *> dynamic_entities_;

    std::vector<Ghost *> ghosts_;
    Pacman *pacman_;

//    UserInterface UI;

    std::vector<std::vector<Cell *>> cells;

public:
    Game(const unsigned int &cell_size, const unsigned int &width, const unsigned int &height) {
        cell_size_ = cell_size;
        width_ = width;
        height_ = height;
        pacman_ = new Pacman();
    }

    sf::Vector2u getScreenSize() const {
        return cell_size_ * sf::Vector2u(width_, height_);
    }

    std::vector<Entity> getEntities() const {
        size_t size = entities_.size();
        std::vector<Entity> entities(size);
        for (int i = 0; i < size; ++i) {
            entities[i] = *entities_[i];
        }
        return entities;
    }

    std::vector<Cell> getCells() const;

    Pacman getPacman() const {
        return *pacman_;
    }

    void update(const float &elapsed_time) {
        for (auto dynamic_entity: dynamic_entities_) {
            float speed = dynamic_entity->getSpeed();
            sf::Vector2f size = dynamic_entity->getSize();
            sf::Vector2f direction = dynamic_entity->getDirection();
            sf::Vector2f position = dynamic_entity->getPosition();
            position += speed * direction;

            float x_pos = position.x;
            float y_pos = position.y;

            float screen_width = cell_size_ * width_;
            float screen_height = cell_size_ * height_;

            if (x_pos < -size.x) {
                x_pos = screen_width;
            }

            if (x_pos > screen_width) {
                x_pos = -size.x;
            }

            if (y_pos < -size.y) {
                y_pos = screen_height;
            }

            if (y_pos > screen_height) {
                y_pos = -size.y;
            }

            position = sf::Vector2f(x_pos, y_pos);
            dynamic_entity->setPosition(position);
        }
    }

    void render(sf::RenderWindow &window) const {
        for (auto entity: entities_) {
            entity->render(window);
        }
    }

    ~Game() {
        delete pacman_;
    }
};

