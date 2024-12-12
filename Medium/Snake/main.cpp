#include "snake_game.h"
#include "main_menu.h"
#include "end_display.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Snake Game");
    window.setFramerateLimit(60);
    bool playagain = false;
    main_menu* mm;
    snake_game* sg;
    end_display* ed;
    do {
    mm = new main_menu(window);
    mm->menuRun();
    cout << "here\n";
    //delete mm;
    sg = new snake_game(window, mm->get_mode());

    sg->run();
    ed = new end_display(window, sg->getGameScore()->getLevelScore());
    if(ed->getIsHighScore()){
        ed->run_entry();
    }
    ed->run();
    playagain = ed->getContinueGame();
    if (playagain){
        delete sg;
        delete mm;
        delete ed;
    }
    }while(playagain);
    delete sg;
    delete mm;
    delete ed;
    return 0;
}