#include "food.h"


food::food(int x, int y){
    this->f = new block(x,y,0,0,255);
};
food::~food(){
     delete this->f;
};

void food::setrow(int r){
    this->f->setrow(r);
};
void food::setcol(int c){
    this->f->setcol(c);
};
int food::getrow(){
    return this->f->getrow();
};
int food::getcol(){
    return this->f->getcol();
};

void food::drawFood(sf::RenderWindow* window){
    window->draw(this->f->get_block_shape());
    
};

bool food::checkLocation(block* b, int x, int y){
    while (true){
        if (x == b->getcol() && y == b->getrow()){
            return true;
        }
        
        if (b->getprevious() == nullptr){
            return false;
        }
        else{
            b = b->getprevious();
        }
    }
};


