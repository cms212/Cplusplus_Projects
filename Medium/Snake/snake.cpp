#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "snake.h"
#include "block.h"
#include <tuple>

using namespace std;



snake::snake(direction d, int x, int y){

    block* b = new block(y, x, 0,255,0);
    this->head = b;
    this->tail = b;
    this->head->setdirection(d);
    this->isalive = true;
};
snake::~snake(){
    delete this->head;
};

bool snake::getisAlive(){
    return this->isalive;
};

void snake::updateSnake(){
        updateBlockdirections();
        updateBlockLocations();
        if (this->head->getdirection() == UP)
        {
            this->head->setrow(this->head->getrow() - 1);
        }
        if (this->head->getdirection() == DOWN)
        {
            this->head->setrow(this->head->getrow() + 1);
        }
        if (this->head->getdirection() == LEFT)
        {
            this->head->setcol(this->head->getcol() - 1);
        }
        if (this->head->getdirection() == RIGHT)
        {
            this->head->setcol(this->head->getcol() + 1);
        }
        return;
    };
bool snake::updateDirection(sf::RenderWindow* window){
        
        while (window->pollEvent(this->event)){
            
            if(this->event.type == sf::Event::KeyPressed){
            //cout << "keypressed\n";
            //cout << this->directionChange.key.code << "\n";
                if (this->event.key.code == sf::Keyboard::W){
                    if (getSnakeDirection() == DOWN && this->snake_length > 1){
                        return true;
                    }
                this->head->setdirection(UP);
                //cout << "U\n";
                }
                if (this->event.key.code == sf::Keyboard::A){
                    if (getSnakeDirection() == RIGHT && this->snake_length > 1){
                        return true;
                    }
                this->head->setdirection(LEFT);
                //cout << "L\n";
                }
                if (this->event.key.code == sf::Keyboard::S){
                    if (getSnakeDirection() == UP && this->snake_length > 1){
                        return true;
                    }
                this->head->setdirection(DOWN);
                //cout << "D\n";
                }
                if (this->event.key.code == sf::Keyboard::D){
                    if (getSnakeDirection() == LEFT && this->snake_length > 1){
                        return true;
                    }
                this->head->setdirection(RIGHT);
                //cout << "R\n";
                }
                if (this->event.key.code == sf::Keyboard::Escape){
                window->close();
                exit(0);
                }
                
            }
            if (this->event.type == sf::Event::Closed){
                window->close();
            }
        }
    return false;
};

void snake::addBlock(){
    if(this->tail->getdirection() == UP){
        block* b = new block(this->tail->getrow() + 1, this->tail->getcol(), 255,0,0);
        b->setprevious(this->tail);
        b->setdirection(this->tail->getdirection());
        this->tail = b;
    }
    if(this->tail->getdirection() == DOWN){
        block* b = new block(this->tail->getrow() - 1, this->tail->getcol(), 255,0,0);
        b->setprevious(this->tail);
        b->setdirection(this->tail->getdirection());
        this->tail = b;
    }
    if(this->tail->getdirection() == LEFT){
        block* b = new block(this->tail->getrow(), this->tail->getcol() + 1, 255,0,0);
        b->setprevious(this->tail);
        b->setdirection(this->tail->getdirection());
        this->tail = b;
    }
    if(this->tail->getdirection() == RIGHT){
        block* b = new block(this->tail->getrow(), this->tail->getcol() - 1, 255,0,0);
        b->setprevious(this->tail);
        b->setdirection(this->tail->getdirection());
        this->tail = b;
    }
    this->snake_length += 1;
    return;
};

void snake::drawSnake(sf::RenderWindow* window){
    //for (block* snake_blocks : this->blocks){
        //cout << "drawing\n";
        //cout << snake_blocks.getPosition().x << "\n";
        //cout << snake_blocks.getPosition().y << "\n";
        //window->draw(snake_blocks->get_block_shape());
    //}

    block* curr = this->tail;
    while (true){
        window->draw(curr->get_block_shape());
        if(curr->getprevious() == nullptr){
            break;
        }
        curr = curr->getprevious();
    }
    return;
};

bool snake::checkCollisionFood(food* f, set<tuple<int, int>>* o_coors){

    if (this->head->getrow() == f->getrow() && this->head->getcol() == f->getcol()){
        addBlock();
        int x = rand()%50;
        int y = rand()%47 + 3;
        if (o_coors != NULL){
        while(f->checkLocation(this->tail, x, y) || o_coors->find(make_tuple(y, x)) != o_coors->end()){
            x = rand()%50;
            y = rand()%46 + 3;
        }
        }
        else{
            while(f->checkLocation(this->tail, x, y)){
            x = rand()%50;
            y = rand()%46+3;
            }
        }
        f->setcol(x);
        f->setrow(y);
        return true;
    }
    return false;
};

void snake::updateBlockdirections(){
    block* curr = this->tail;
    while (curr->getprevious() != nullptr){
        curr->setdirection(curr->getprevious()->getdirection());
        curr = curr->getprevious();
    }
    return;
};

void snake::updateBlockLocations(){
    block* curr = this->tail;

    while (curr->getprevious() != nullptr){
        curr->setrow(curr->getprevious()->getrow());
        curr->setcol(curr->getprevious()->getcol());
        curr = curr->getprevious();
    }
    return;
};

void snake::checkCollisionsObstacles(set<tuple<int, int>>* o_coors){
    if (o_coors != nullptr) {
        for (const auto& t : *o_coors) {
            if (this->head->getrow() == get<0>(t) && this->head->getcol() == get<1>(t)){
                this->isalive = false;
                return;    
            }
        }
        return;
    }
}

void snake::checkCollisionBody(){
    block* curr = this->tail;

    while (curr->getprevious() != nullptr){
        if(curr->getrow() == this->head->getrow() && curr->getcol() == this->head->getcol()){
            this->isalive = false;
            return;
        }
        curr = curr->getprevious();
    }
};

void snake::checkCollisionwWall(){
    if(this->head->getrow() < 2 || this->head->getrow() > 49 || this->head->getcol() < 0
    || this->head->getcol() > 49){
        this->isalive = false;
        return;
    }
    return;
};

int snake::getHeadrow(){
    return this->head->getrow();
}

int snake::getHeadcol(){
    return this->head->getcol();
}

void snake::setSnakeDirection(direction d){
    this->head->setdirection(d);
};

direction snake::getSnakeDirection(){
    return this->head->getdirection();
};

block* snake::get_tail(){
    return this->tail;
}




