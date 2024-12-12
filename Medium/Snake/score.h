#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <string>


class score{
    private:
        int level_score;
        int level;
        sf::Text score_text;
        std::string score_string;
        sf::Font score_font;
        sf::Text Level_text;
        std::string level_string;
        sf::Font level_font;
    public: 
        score();
        ~score();
        int getLevelScore();
        int getGlobalScore();
        void incrementScore();
        void resetScore();
        sf::Text getText();
        sf::Text getText2();
        void setText();
        void drawScore(sf::RenderWindow* window);
        void drawLevel(sf::RenderWindow* window);

};



#endif