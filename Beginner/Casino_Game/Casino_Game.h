#ifndef CASINO_GAME_H
#define CASINO_GAME_H
#include<string>
#include<cstdlib>
using namespace std;
class Casino_Game{
    private:
        int betting_amount;
        int guesses;
        int rand_num;
        int total_amount;
        int guess;
        int multiplier;
    public:
        Casino_Game(int total_amount);
        void game();
        void set_betting_amount(int betting_amount);
        void set_game_mode(string game_mode);
        int get_total();
};


#endif