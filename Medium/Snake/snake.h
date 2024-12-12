#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>
#include "block.h"
#include "food.h"
#include <set>



class snake
{
private:
    block* head;
    block* tail;
    sf::Event event;
    vector<block*> blocks;
    bool isalive;
    int snake_length = 1;

public:
    snake(direction d, int x, int y);
    ~snake();
    void updateSnake();
    bool updateDirection(sf::RenderWindow* window);
    void updateBlockdirections();
    void addBlock();
    void drawSnake(sf::RenderWindow* window);
    bool checkCollisionFood(food* f, set<tuple<int, int>>* o_coors);
    void updateBlockLocations();
    bool getisAlive();
    void checkCollisionBody();
    void checkCollisionwWall();
    void checkCollisionsObstacles(set<tuple<int, int>>* o_coors);
    int  getHeadrow();
    int  getHeadcol();
    void  setSnakeDirection(direction d);
    direction getSnakeDirection();
    block* get_tail();
};





#endif