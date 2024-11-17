#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>
#include "block.h"
#include "food.h"



class snake
{
private:
    block* head;
    block* tail;
    sf::Event event;
    vector<block*> blocks;

public:
    snake(/* args */);
    ~snake();
    void updateSnake();
    void updateDirection(sf::RenderWindow* window);
    void updateBlockdirections();
    void addBlock();
    void drawSnake(sf::RenderWindow* window);
    void checkCollisionFood(food* f);
    void updateBlockLocations();
};





#endif