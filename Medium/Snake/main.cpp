#include "snake_game.h"
#include "main_menu.h"
#include "end_display.h"
#include <SFML/Graphics.hpp>


int main(int argc, char *argv[]){
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Snake Game");
    window.setFramerateLimit(60);
    main_menu* mm = new main_menu(window);
    mm->menuRun();
    //delete mm;
    snake_game* sg = new snake_game(window);
    
    sg->run();
    end_display* ed = new end_display(window, sg->getGameScore());
    ed->run();
    //delete sg;
    return 0;
}