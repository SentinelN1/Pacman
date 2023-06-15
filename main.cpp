#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "game.h"

const unsigned int CELL_SIZE = 16;
const unsigned int WIDTH = 48;
const unsigned int HEIGHT = 32;
const std::string TITLE = "Genshin Impact.exe";
const sf::Color PACMAN_COLOR = sf::Color(255, 255, 0);
const sf::Color WALL_COLOR = sf::Color(33, 33, 222);
const sf::Color GUM_COLOR = sf::Color(255, 184, 151);

void handleEvents(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void render(sf::RenderWindow &window, const Game &game) {
    window.clear(sf::Color::Black);
    game.render(window);
    window.display();
}

void update(sf::Clock &clock, Game &game) {
    const float elapsedTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    game.update(elapsedTime);
}

int main() {
    Game game(CELL_SIZE, WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(game.getScreenSize().x, game.getScreenSize().y), TITLE, sf::Style::Default);

//    sf::SoundBuffer buffer;
//    if (!buffer.loadFromFile("C:/Users/egora/Downloads/Theme.wav")) {
//        std::cout << "Unable to load the audio file.\n";
//        return -1;
//    }
//    sf::Sound sound;
//    sound.setBuffer(buffer);
//    sound.play();

    sf::Clock clock;
    while (window.isOpen()) {
        handleEvents(window);
        render(window, game);
        update(clock, game);
        clock.restart();
    }

    return 0;
}