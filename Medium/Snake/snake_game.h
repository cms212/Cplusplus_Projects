#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "snake.h"
#include "food.h"
#include "score.h"
#include "loader.h"


class snake_game{
    private:
        sf::RenderWindow* window;
        sf::SoundBuffer music_buffer;
        sf::SoundBuffer food_buffer;
        sf::SoundBuffer lose_buffer;
        sf::Sound food_grab;
        sf::Sound game_music;
        sf::Sound lose_sound;
        snake* s;
        food* f;
        loader* l;
        score* game_score;
        vector<string> wav_files = {"Level1.wav", "Level2.wav", "Level3.wav"};
        set<tuple<int,int>>* o_coors;
        int music_index;
        bool extreme_mode;

    public:
        snake_game(sf::RenderWindow &window, bool extreme_mode);
        ~snake_game();
        void run();
        bool checkCollisions();
        void musicCycle();
        score* getGameScore();

};

#endif