#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <string>


class score{
    private:
        int level_score;
        int global_score;
        sf::Text score_text;
        std::string score_string;
        sf::Font score_font;
    public: 
        score();
        ~score();
        int getLevelScore();
        int getGlobalScore();
        void incrementScore();
        void resetScore();
        sf::Text getText();
        void setText();
        void drawScore(sf::RenderWindow* window);

};



#endif