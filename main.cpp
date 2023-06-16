#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "game.h"

const std::string TITLE = "GenshinImpact.exe";

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
    Game game;
    sf::RenderWindow window(sf::VideoMode(game.getScreenSize().x, game.getScreenSize().y), TITLE, sf::Style::Default);

    sf::Clock clock;
    while (window.isOpen()) {
        handleEvents(window);
        render(window, game);
        update(clock, game);
        clock.restart();
    }

    return 0;
}
