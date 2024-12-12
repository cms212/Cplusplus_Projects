#include "score.h"
#include <iostream>

score::score(){
    this->level_score = 0;
    this->level = 0;
    if (!this->score_font.loadFromFile("../../Snake/fonts/Roboto-Bold.ttf")){
        std::cout << "issue loading font";
    }

    this->score_text.setFont(this->score_font);
    this->score_text.setCharacterSize(20);
    this->score_text.setFillColor(sf::Color::Green);
    this->score_text.setPosition(10,10);
    this->Level_text.setFont(this->score_font);
    this->Level_text.setCharacterSize(20);
    this->Level_text.setFillColor(sf::Color::Green);
    this->Level_text.setPosition(200,10);
    setText();

};
score::~score(){

};
int score::getLevelScore(){
    return this->level_score;
};
int score::getGlobalScore(){
    return this->level;
}
void score::incrementScore(){
    this->level_score += 10;
    this->level += 1;
};
sf::Text score::getText(){
    return this->score_text;
};
void score::setText(){
    this->score_text.setString("Score: " + std::to_string(this->level_score));
    this->Level_text.setString("Level: " + std::to_string(this->level));
};


void score::resetScore(){
    this->level_score = 0;
}

void score::drawScore(sf::RenderWindow* window){
    window->draw(this->score_text);
}

sf::Text score::getText2(){
    return this->Level_text;
}

void score::drawLevel(sf::RenderWindow* window){
    window->draw(this->Level_text);
}

