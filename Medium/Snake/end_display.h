#ifndef END_DISPLAY_H
#define END_DISPLAY_H
#include "score.h"
#include "snake.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class end_display
{
private:
    vector<pair<string,int>> scores;
    score* game_score;
    sf::RenderWindow* window;
    bool ishighscore = false;
    int frame_count;
    string user_entry;
    int entry_index = 0;
public:
    end_display(sf::RenderWindow &window, score* game_score);
    ~end_display();
    void run();
    void load_scores();
    void isHighScore();
    void run_entry();
};




#endif