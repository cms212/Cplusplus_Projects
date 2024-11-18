#include "snake_game.h"
#include "main_menu.h"
#include "score.h"
#include <SFML/Graphics.hpp>
#include <iostream>

snake_game::snake_game(sf::RenderWindow &window){
    this->window = &window;
    this->window->setFramerateLimit(60);
    this->window->setKeyRepeatEnabled(false);
    this->s = new snake(NONE, 24,24);
    srand(std::time(0));
    this->f = new food(rand() % 49, rand() % 49);
    this->game_score = new score();
    this->music_index = 0;

    if(!this->food_buffer.loadFromFile("../../Snake/wav_files/mixkit-retro-arcade-casino-notification-211.wav")){
        cout << "issue loading sound";
        this->window->close();
    }

    if(!this->lose_buffer.loadFromFile("../../Snake/wav_files/mixkit-player-losing-or-failing-2042.wav")){
        cout << "issue loading sound";
        this->window->close();
    }

    this->food_grab.setBuffer(this->food_buffer);
    this->game_music.setBuffer(this->music_buffer);
    this->lose_sound.setBuffer(this->lose_buffer);
};
snake_game::~snake_game(){
    delete this->s;
    delete this->f;
    delete this->game_score;
};
void snake_game::run(){
    while(this->window->isOpen()){
        this->window->clear(sf::Color::Black);
        if(this->s->checkCollisionFood(this->f)){
            this->food_grab.play();
            this->game_score->incrementScore();
            this->game_score->setText();
        }
        this->game_score->drawScore(this->window);
        this->s->updateDirection(this->window);
        this->s->updateSnake();
        if (!checkCollisions()){
            this->lose_sound.play();
            this->window->close();
        }
        this->s->drawSnake(this->window);
        this->f->drawFood(this->window);
        musicCycle();
        window->display();
        sf::sleep(sf::milliseconds(100));
    }

};

bool snake_game::checkCollisions(){
    s->checkCollisionBody();
    s->checkCollisionwWall();
    return s->getisAlive();
}

void snake_game::musicCycle(){
    if((this->game_music.getStatus() != sf::Sound::Playing)){
        if(!this->music_buffer.loadFromFile("../../Snake/wav_files/" + this->wav_files.at(this->music_index))){
            cout << "issue loading sound";
            this->window->close();
        }
        this->game_music.play();
        this->music_index += 1;
        if (this->music_index == this->wav_files.size()){
            this->music_index = 0;
        }
    }
};