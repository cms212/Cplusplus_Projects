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
    bool isalive;

public:
    snake(direction d, int x, int y);
    ~snake();
    void updateSnake();
    void updateDirection(sf::RenderWindow* window);
    void updateBlockdirections();
    void addBlock();
    void drawSnake(sf::RenderWindow* window);
    bool checkCollisionFood(food* f);
    void updateBlockLocations();
    bool getisAlive();
    void checkCollisionBody();
    void checkCollisionwWall();
    int  getHeadrow();
    int  getHeadcol();
    void  setSnakeDirection(direction d);
    direction getSnakeDirection();
};





#endif