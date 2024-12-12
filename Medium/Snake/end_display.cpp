#include "end_display.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <ostream>

using namespace std;
end_display::end_display(sf::RenderWindow &window, int s){
    this->window = &window;
    this->frame_count = 0;
    load_scores();
    this->game_score = s;
    cout << this->game_score;
    //cout << "Scores size: " << this->scores.size() << "\n";
    isHighScore();
    //cout << "is high score: " << this->ishighscore << "\n";
    
    if (!this->font.loadFromFile("../../Snake/fonts/Roboto-Bold.ttf")){
        cout << "issue loading font";
        this->window->close();
    }

    this->display_text.setFont(this->font);
    this->enter_Text.setFont(this->font);
    if (this->ishighscore){
        this->display_text.setString("You Got a High Score! Enter Initials!");
        this->display_text.setPosition(100,25);
        this->display_text.setCharacterSize(50);
        this->display_text.setFillColor(sf::Color::Green);
    }
};
end_display::~end_display(){
};

int end_display::getScore(){
    return this->game_score;
}

void end_display::run_entry(){
    int letter_index = 0;
    bool display = true;
    int entry_index = 0;
    sf::Text entry_letter1;
    sf::Text entry_letter2;
    sf::Text entry_letter3;
    vector<pair<reference_wrapper<sf::Text>, int>>  entry_letters= {{entry_letter1,0}, {entry_letter2,0}, {entry_letter3,0}};
    sf::Text underscore;
    int entry_x = 400;
    int entry_y = 100;
    entry_letter1.setPosition(entry_x,entry_y);
    entry_letter2.setPosition(entry_x + 50, entry_y);
    entry_letter3.setPosition(entry_x + 100, entry_y);
    entry_letter1.setFont(this->font);
    entry_letter2.setFont(this->font);
    entry_letter3.setFont(this->font);
    entry_letter1.setString(this->letters[entry_letters[0].second]);
    entry_letter2.setString(this->letters.at(entry_letters[1].second));
    entry_letter3.setString(this->letters.at(entry_letters[2].second));
    entry_letter1.setFillColor(sf::Color::White);
    entry_letter2.setFillColor(sf::Color::White);
    entry_letter3.setFillColor(sf::Color::White);
    entry_letter1.setCharacterSize(50);
    entry_letter2.setCharacterSize(50);
    entry_letter3.setCharacterSize(50);
    underscore.setPosition(entry_x, entry_y);
    underscore.setFont(this->font);
    underscore.setString("_");
    underscore.setCharacterSize(75);
    sf::Event event;
    while(true){
        this->window->clear(sf::Color::Black);
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                this->window->close();
                return;
            }
            if(event.type == sf::Event::KeyPressed){
            //cout << "keypressed\n";
            //cout << this->directionChange.key.code << "\n";
                if (event.key.code == sf::Keyboard::Up){
                    entry_letters[entry_index].second += 1;
                    if(entry_letters[entry_index].second == 26){
                        entry_letters[entry_index].second = 0;
                    }
                    entry_letters[entry_index].first.get().setString(this->letters.at(entry_letters[entry_index].second));
                }
                if (event.key.code == sf::Keyboard::Down){
                    entry_letters[entry_index].second -= 1;
                    if(entry_letters[entry_index].second == -1){
                        entry_letters[entry_index].second = 25;
                    }
                    entry_letters[entry_index].first.get().setString(this->letters.at(entry_letters[entry_index].second));
                }
                if (event.key.code == sf::Keyboard::Left){
                    if(entry_index > 0){
                        entry_letters[entry_index].first.get().setString(this->letters.at(entry_letters[entry_index].second));
                        entry_index -= 1;
                        entry_x -= 50;
                        underscore.setPosition(entry_x, entry_y);
                    }
                }
                if (event.key.code == sf::Keyboard::Right){
                    if (entry_index < 2){
                        entry_letters[entry_index].first.get().setString(this->letters.at(entry_letters[entry_index].second));
                        entry_index += 1;
                        entry_x += 50;
                        underscore.setPosition(entry_x, entry_y);
                    }
                }
                if(event.key.code == sf::Keyboard::Enter){
                    //put togther user name
                    //sort scores
                    //save to text file
                    this->window->clear();
                    //return;
                    for (int i  = 0; i < entry_letters.size(); i++){
                        this->user_entry += this->letters[entry_letters[i].second];
                    }
                    sort_save();
                    return;
                }
            
                if (event.key.code == sf::Keyboard::Escape){
                    window->close();
                    exit(0);
                //cout << "R\n";
                }
            }
            
            
        }
        if (this->frame_count == 5){
            display = !display;
            this->frame_count = 0;
            if (display){
                entry_letters[entry_index].first.get().setString(this->letters.at(entry_letters[entry_index].second));
                //underscore.setString("_");
            }
            else{
                //cout << "here\n";
                entry_letters[entry_index].first.get().setString("");
                //underscore.setString("");
            }
        }
        for (int i = 0; i < entry_letters.size(); i++){
            
            this->window->draw(entry_letters[i].first);
        }
        this->window->draw(underscore);
        this->window->draw(display_text);
        window->display();
        sf::sleep(sf::milliseconds(100));
        this->frame_count += 1;
        //cout << this->frame_count;
    }
};
void end_display::run(){
    this->display_text.setString("HIGH SCORES");
    this->display_text.setPosition(250,50);
    this->display_text.setCharacterSize(75);
    this->display_text.setFillColor(sf::Color::Green);
    this->enter_Text.setString("PRESS ENTER TO PLAY AGAIN!");
    this->enter_Text.setPosition(150,750);
    this->enter_Text.setCharacterSize(50);
    this->enter_Text.setFillColor(sf::Color::Green);
    this->continue_game = false;
    set_HighScores_text();
    while(this->window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event)){
             if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    window->close();
                    return;
                //cout << "R\n";
                }
                if (event.key.code == sf::Keyboard::Enter){
                    //window->close();
                    this->continue_game = true;
                    this->window->clear();
                    return;
                //cout << "R\n";
                }
             }
            if (event.type == sf::Event::Closed){
                window->close();
                return;
            }
        }
        this->window->clear(sf::Color::Black);
        this->window->draw(this->display_text);
        this->window->draw(this->enter_Text);
        for (const auto& a: this->high_scores){
            this->window->draw(a);
        }
        window->display();
        sf::sleep(sf::milliseconds(100));
    }
};

bool end_display::getContinueGame(){
    return this->continue_game;
}
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
    this->ishighscore = false;
    if (this->scores.size() < 10){
        this->ishighscore = true;
        //cout << "here1\n";
    }
    else{
        int min = this->scores[0].second;

        for (int i = 1; i < this->scores.size(); i++){
            if (min > this->scores[i].second){
                min = this->scores[i].second;
            }
        }
        //cout << "here2\n";
        if(min < this->game_score){
            this->ishighscore = true;
        }
    }
    cout << this->ishighscore;
};

void end_display::setScore(int s){
    this->game_score = s;
}

bool end_display::getIsHighScore(){
    return this->ishighscore;
}

void end_display::sort_save(){
    this->scores.push_back(make_pair(this->user_entry, this->game_score));
    int j;
    pair<string, int> temp;
    for (int i = 0; i < this->scores.size(); i++){
        j = i;
        while (j != 0 && this->scores[j].second > this->scores[j-1].second){
            temp = this->scores[j-1];
            this->scores[j-1] = this->scores[j];
            this->scores[j] = temp;
            j -= 1;
        }
    }
    while(this->scores.size() > 10){
        this->scores.pop_back();
    }

    for (const auto& a: this->scores){
        cout << a.first << " : " << a.second << "\n";
    }
    ofstream write_scores("../../Snake/scores.txt");
    if (write_scores.is_open()){
        for (const auto& score : this->scores){
            write_scores << score.first << "\n" << score.second << "\n";
        }
    }
    else{
        cout << "Issue opening scores text file\n";
    }
};

void end_display::set_HighScores_text(){
    int x = 400;
    int y = 200;
    for (int i = 0; i < this->scores.size(); i++){
        sf::Text text;
        text.setFont(this->font);
        text.setString(this->scores[i].first + "  " + to_string(this->scores[i].second));
        text.setPosition(x,y);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(30);
        this->high_scores.push_back(text);
        y+= 50;
    }
};

