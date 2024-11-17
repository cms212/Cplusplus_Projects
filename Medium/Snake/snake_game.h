#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"

class snake_game{
    private:
        sf::RenderWindow* window;
        snake* s;
        food* f;

    public:
        snake_game();
        ~snake_game();
        void run();
};

#endif