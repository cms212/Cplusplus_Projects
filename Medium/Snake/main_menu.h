#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class main_menu{

    private:
        sf::RenderWindow* window;
        snake* menu_snake;
        sf::Text menu_text;
        sf::Text button_text;
        sf::Font font;
        sf::FloatRect text_bounds;
        sf::Event event;
        sf::RectangleShape normal_game_button;
        sf::SoundBuffer buffer;
        sf::Sound sound;
        int text_x;
        int frame_count;
        bool menu_stay;
        int snake_length;

    public:
        main_menu(sf::RenderWindow &window);
        ~main_menu();
        void updateMenuSnake();
        void moveText();
        void menuRun();
        void checkButtons();
        void update_snake_length();
        void checkSound();

};

#endif