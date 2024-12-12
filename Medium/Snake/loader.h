#ifndef LOADER_H
#define LOADER_H

#include<SFML/Graphics.hpp>
#include "block.h"
#include "food.h"
#include "snake.h"
#include <set>
using namespace std;



class loader{
    private:
        sf::RenderWindow* window;
        vector<block*> obstacles;
        vector<tuple<int, int>> coors;
        set<tuple<int, int>> picked_coor;

    public:
        loader();
        ~loader();
        set<tuple<int,int>>& get_obstacles();
        void add_blocks(snake* s, food* f);
        void draw_obstacles(sf::RenderWindow* window);
        bool check_food(food* f, tuple<int, int> coor);
        bool check_snake(snake* s, tuple<int, int> coor);

};




#endif 