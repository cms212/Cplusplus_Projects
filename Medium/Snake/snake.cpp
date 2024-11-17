#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "snake.h"
#include "block.h"
#include <tuple>

using namespace std;



snake::snake(/* args */){

    block* b = new block(24, 24, 255,0,0);
    this->head = b;
    this->tail = b;
    this->head->setdirection(NONE);
};
snake::~snake(){
    delete this->head;
};
void snake::updateSnake(){
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
        
    };
void snake::updateDirection(sf::RenderWindow* window){
        
        while (window->pollEvent(this->event)){
            
            if(this->event.type == sf::Event::KeyPressed){
            //cout << "keypressed\n";
            //cout << this->directionChange.key.code << "\n";
                if (this->event.key.code == sf::Keyboard::W){
                this->head->setdirection(UP);
                //cout << "U\n";
                }
                if (this->event.key.code == sf::Keyboard::A){
                this->head->setdirection(LEFT);
                //cout << "L\n";
                }
                if (this->event.key.code == sf::Keyboard::S){
                this->head->setdirection(DOWN);
                //cout << "D\n";
                }
                if (this->event.key.code == sf::Keyboard::D){
                this->head->setdirection(RIGHT);
                //cout << "R\n";
                }
                if (this->event.key.code == sf::Keyboard::Escape){
                window->close();
                //cout << "R\n";
                }
                
            }
            if (this->event.type == sf::Event::Closed){
                window->close();
            }
        }
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
};

void snake::checkCollisionFood(food* f){
    if (this->head->getrow() == f->getrow() && this->head->getcol() == f->getcol()){
        addBlock();
        int x = rand()%49;
        int y = rand()%49;
        while(f->checkLocation(this->tail, x, y)){
            x = rand() % 49;
            y = rand() % 49;
        }
        f->setcol(x);
        f->setrow(y);
    }

};

void snake::updateBlockdirections(){
    block* curr = this->tail;
    while (curr->getprevious() != nullptr){
        curr->setdirection(curr->getprevious()->getdirection());
        curr = curr->getprevious();
    }
};

void snake::updateBlockLocations(){
    block* curr = this->tail;

    while (curr->getprevious() != nullptr){
        curr->setrow(curr->getprevious()->getrow());
        curr->setcol(curr->getprevious()->getcol());
        curr = curr->getprevious();
    }
};

