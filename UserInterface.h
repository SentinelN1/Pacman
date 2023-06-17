#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"

class UserInterface {
private:
    unsigned int score_;
    sf::RenderWindow *window_;
    Game *game_;
    sf::Font font_;

public:
    UserInterface(sf::RenderWindow &window, Game &game) {
        score_ = 0;
        window_ = &window;
        game_ = &game;
        font_.loadFromFile("C:\\Users\\egora\\Documents\\Projects\\Pacman\\arcade.ttf");
    }

    void render() {
        Pacman *pacman = game_->getPacman();
        score_ = 10 * pacman->getEatenGums() + 100 * pacman->getEatenSuperGums();
        sf::Text text;
        text.setPosition(CELL_SIZE / 2, CELL_SIZE / 2);
        text.setFont(font_);
        text.setString("Score: " + std::to_string(score_));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window_->draw(text);
    }
};
