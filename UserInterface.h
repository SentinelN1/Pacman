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
    UserInterface(Game &game) {
        score_ = 0;
        game_ = &game;
        font_.loadFromFile("C:\\Users\\egora\\Documents\\Projects\\Pacman\\arcade.ttf");
    }

    void render(sf::RenderWindow &window) {
        Pacman *pacman = game_->getPacman();
        score_ = 10 * pacman->getEatenGums() + 100 * pacman->getEatenSuperGums();
        sf::Text text;
        text.setPosition(CELL_SIZE / 2, CELL_SIZE / 2);
        text.setFont(font_);
        text.setString("Score: " + std::to_string(score_));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        window.draw(text);
    }
};
