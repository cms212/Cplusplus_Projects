#include "Casino_Game.h"
#include<iostream>

int main(){
    int total_amount;
    int betting_amount;
    string game_mode;

    cout << "Welcome to the Casino! The rules are as follows: \n";
    cout << "1. A random number between 1-100 must be guessed\n";
    cout << "2. Easy mode gives you 10 guesses to 2x your betting amount\n";
    cout << "3. Medium mode gives you 7 guesses to 5x your betting amount\n";
    cout << "4. Hard mode gives you 5 guesses to 10x your betting amount\n";
    cout << "Please Enter total amount of money you have: ";
    cin >> total_amount;
    Casino_Game cg(total_amount);
    while (true){
        cout << "Enter betting amount or type 0 to stop playing: ";
        cin  >> betting_amount;
        if (betting_amount == 0){
            break;
        }
        while (true){
        cout << "Enter either Easy, Medium or Hard for game mode: ";
        cin >> game_mode;

        if (game_mode != "Easy" && game_mode != "Medium" && game_mode != "Hard"){
            cout << "Pick a correct option\n";
        }
        else{
            break;
        }

        }
        cg.set_betting_amount(betting_amount);
        cg.set_game_mode(game_mode);
        cg.game();

        if(cg.get_total() <= 0){
            cout << "You lost all your money better luck next time!\n";
            break;
        }
    }
    cout << "Thanks for playing you left here with $" << cg.get_total() << ". See you again soon!";

    return 0;
}