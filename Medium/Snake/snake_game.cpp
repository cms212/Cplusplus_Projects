#include "snake_game.h"

#include <SFML/Graphics.hpp>

snake_game::snake_game(){
    this->window = new sf::RenderWindow(sf::VideoMode(1000,1000), "Snake Game");
    this->window->setFramerateLimit(60);
    this->window->setKeyRepeatEnabled(false);
    this->s = new snake();
    srand(std::time(0));
    this->f = new food(rand() % 49, rand() % 49);
};
snake_game::~snake_game(){
    delete this->s;
    delete this->f;
    delete this->window;
};
void snake_game::run(){
    while(this->window->isOpen()){
        this->window->clear(sf::Color::Black);
        this->s->checkCollisionFood(this->f);
        this->s->updateDirection(this->window);
        this->s->updateBlockdirections();
        this->s->updateSnake();
        this->s->drawSnake(this->window);
        this->f->drawFood(this->window);
        window->display();
        sf::sleep(sf::milliseconds(100));
    }
};