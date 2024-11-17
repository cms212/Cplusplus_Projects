#include "snake_game.h"


int main(int argc, char *argv[]){
    snake_game* sg = new snake_game();

    sg->run();

    delete sg;
    
    
    
    return 0;
}