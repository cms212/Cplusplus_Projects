#include "end_display.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
end_display::end_display(sf::RenderWindow &window, score* game_score){
    this->game_score = game_score;
    this->window = &window;
    load_scores();
    cout << "Scores size: " << this->scores.size() << "\n";
    isHighScore();
    cout << "is high score: " << this->ishighscore << "\n";
};
end_display::~end_display(){
    delete this->game_score;
};

void end_display::run_entry(){
    while(this->entry_index < 3){

    }
};
void end_display::run(){
    while(this->window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window->close();
            }
        }
        this->window->clear(sf::Color::Black);
        window->display();
        sf::sleep(sf::milliseconds(100));
    }
};
void end_display::load_scores(){
    fstream read_scores;
    read_scores.open("../../Snake/scores.txt", ios::in);
    if (read_scores.is_open()) {
    string user_entry;
    string user_score;
    while (getline(read_scores, user_entry, '\n')) {
      getline(read_scores, user_score, '\n');
      uint32_t user_score_int = stoi(user_score);
      this->scores.push_back(make_pair(user_entry, user_score_int));
    }
  } else {
    printf("issue opening file\n");
  }
    read_scores.close();
};
void end_display::isHighScore(){
    int index;
    if (this->scores.size() < 10){
        this->ishighscore = true;
        cout << "here1\n";
    }
    else{
        int min = this->scores[0].second;

        for (int i = 1; i < this->scores.size(); i++){
            if (min > this->scores[i].second){
                min = this->scores[i].second;
            }
        }
        cout << "here2\n";
        if(min < this->game_score->getLevelScore()){
            this->ishighscore = true;
        }
    }
};