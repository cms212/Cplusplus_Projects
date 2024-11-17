#ifndef FOOD_H
#define FOOD_H
#include "block.h"
#include <SFML/Graphics.hpp>

class food{

    private:
        block* f;
    public:
        food(int x, int y);
        ~food();
        void setrow(int r);
        void setcol(int c);
        int getrow();
        int getcol();
        void drawFood(sf::RenderWindow* window);
        bool checkLocation(block* b, int x, int y);

};

#endif