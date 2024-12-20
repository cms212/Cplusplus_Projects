#ifndef END_DISPLAY_H
#define END_DISPLAY_H
#include "score.h"
#include "snake.h"
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;

class end_display
{
private:
    vector<pair<string,int>> scores;
    vector<sf::Text> high_scores;
    int game_score;
    sf::RenderWindow* window;
    bool ishighscore;
    int frame_count;
    string user_entry;
    sf::Font font;
    sf::Text display_text;
    sf::Text enter_Text;
    bool continue_game;
    map<int, string> letters = {
        {0, "A"}, {1, "B"}, {2, "C"}, {3, "D"}, {4, "E"},
        {5, "F"}, {6, "G"}, {7, "H"}, {8, "I"}, {9, "J"},
        {10, "K"}, {11, "L"}, {12, "M"}, {13, "N"}, {14, "O"},
        {15, "P"}, {16, "Q"}, {17, "R"}, {18, "S"}, {19, "T"},
        {20, "U"}, {21, "V"}, {22, "W"}, {23, "X"}, {24, "Y"},
        {25, "Z"}
    };
public:
    end_display(sf::RenderWindow &window, int s);
    ~end_display();
    void run();
    void load_scores();
    void isHighScore();
    bool getIsHighScore();
    void run_entry();
    void sort_save();
    void set_HighScores_text();
    bool getContinueGame();
    void setScore(int s);
    int getScore();
};




#endif