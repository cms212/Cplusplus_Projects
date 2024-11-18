#include "score.h"
#include <iostream>

score::score(){
    this->level_score = 0;
    this->global_score = 0;
    if (!this->score_font.loadFromFile("../../Snake/fonts/Roboto-Bold.ttf")){
        std::cout << "issue loading font";
    }

    this->score_text.setFont(this->score_font);
    this->score_text.setCharacterSize(20);
    this->score_text.setFillColor(sf::Color::Green);
    this->score_text.setPosition(10,10);
    setText();

};
score::~score(){

};
int score::getLevelScore(){
    return this->level_score;
};
int score::getGlobalScore(){
    return this->global_score;
}
void score::incrementScore(){
    this->level_score += 10;
    this->global_score += 10;
};
sf::Text score::getText(){
    return this->score_text;
};
void score::setText(){
    this->score_text.setString("Score: " + std::to_string(this->level_score));
};

void score::resetScore(){
    this->level_score = 0;
}

void score::drawScore(sf::RenderWindow* window){
    window->draw(this->score_text);
}