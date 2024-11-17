#ifndef BLOCK_H
#define BLOCK_H

#include <tuple>
#include <SFML/Graphics.hpp>
using namespace std;

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

class block
{
private:
    int row;
    int column;
    block* previous;
    direction d;
    tuple<int, int, int> rgb;
    sf::RectangleShape  block_shape;


public:
    block(int r, int c, int red, int green, int blue);
    ~block();
    void setrow(int num);
    void setcol(int num);
    void setcolor(tuple<int,int,int> color);
    tuple<int, int, int> getcolor();
    int getrow();
    int getcol();
    sf::RectangleShape get_block_shape(); 
    void setprevious(block* k);
    block* getprevious();
    void setdirection(direction d);
    direction getdirection();
};




#endif