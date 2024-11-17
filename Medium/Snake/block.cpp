#include "block.h"
#include <tuple>
using namespace std;

block::block(int r, int c, int red, int green, int blue){
    this->previous = nullptr;
    this->row = r;
    this->column = c;
    get<0>(this->rgb) = red;
    get<1>(this->rgb) = green;
    get<2>(this->rgb) = blue;
    this->block_shape = sf::RectangleShape(sf::Vector2f(20.0,20.0));
    this->block_shape.setPosition(this->column *20, this->row *20);
    this->block_shape.setFillColor(sf::Color(get<0>(this->rgb), get<1>(this->rgb), get<2>(this->rgb)));
};
block::~block(){
    delete this->previous;
};
void block::setrow(int num){
    this->row = num;
    this->block_shape.setPosition(this->column *20, this->row *20);
}
void block::setcol(int num){
    this->column = num;
    this->block_shape.setPosition(this->column *20, this->row *20);
};
int block::getrow(){
    return this->row;
};
int block::getcol(){
    return this->column;
};

void block::setprevious(block* k){
    this->previous = k;
};

void block::setcolor(tuple<int,int,int> color){
    this->rgb = color;
};

tuple<int, int, int> block::getcolor(){
    return this->rgb;
};

sf::RectangleShape block::get_block_shape(){
    return this->block_shape;
};

void block::setdirection(direction d){
    this->d = d;
};
direction block::getdirection(){
    return this->d;
};

block* block::getprevious(){
    return this->previous;
};