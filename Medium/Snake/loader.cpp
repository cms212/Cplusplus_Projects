#include "loader.h"
#include <fstream>
#include <cstdlib>

loader::loader(){
    this->window = window;
    for (int i = 3; i < 50; i++){
        for (int j = 0; j < 50; j++){
            tuple<int,int> coordinate = make_tuple(i,j);
            this->coors.push_back(coordinate);
        }
    }
    
 };
loader::~loader(){
    for (block* a : this->obstacles){
        delete a;
    }
    this->obstacles.clear();
};
set<tuple<int,int>>& loader::get_obstacles(){
    return this->picked_coor;
};
void loader::add_blocks(snake* s, food* f){
    int y;
    tuple<int, int> sel_coor;
    for(int i = 0; i < 5; i ++){
    y = rand()%2350;
    sel_coor = this->coors[y];
    while (this->picked_coor.find(sel_coor) != this->picked_coor.end() || check_food(f, sel_coor) || check_snake(s, sel_coor)){
        y = rand()%2350;
        sel_coor = this->coors[y];
    }
    this->picked_coor.insert(sel_coor);
    block* obstacle_block = new block(get<0>(sel_coor), get<1>(sel_coor), 255,255,255);
    this->obstacles.push_back(obstacle_block);
    }
};

void loader::draw_obstacles(sf::RenderWindow* window){
    for (block* b: this->obstacles){
        window->draw(b->get_block_shape());
    }
};

bool loader::check_food(food* f, tuple<int, int> coor){
    if (f->getcol() == get<0>(coor) && get<1>(coor) == f->getrow()){
        return true;
    }
    return false;
};

bool loader::check_snake(snake* s, tuple<int, int> coor){
    block* b = s->get_tail();
    while(true){
        if(b->getcol() == get<0>(coor) && get<1>(coor) == b->getrow()){
            return true;
        }
        if (b->getprevious() == nullptr){
            return false;
        }
        b = b->getprevious();
    }
};
