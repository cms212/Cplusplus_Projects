#include "Casino_Game.h"
#include<iostream>
#include<cstdlib>
using namespace std;

Casino_Game::Casino_Game(int total_amount){
    this->total_amount = total_amount;
};

void Casino_Game::game(){
    this->rand_num = (rand() % 100) + 1;
    //this->rand_num = 50;
    cout << "You have " << this->guesses << " guesses to correctly guess a random number between 1-100" << "\n";
    cout << "If you guess corectly you win " << this->multiplier << "x your betting amount! Good Luck" << "\n";

    for (int i  = 0; i < this->guesses; i++){
        cout << "Enter your Guess: ";
        cin >> this->guess;
        if (this->guess == rand_num){
            this->total_amount += this->betting_amount * this->multiplier;
            cout << "You Guessed Right!" << "\n";
            cout << "Your new total is: " << this->total_amount << "\n";
            return;
        }
        else if(this->guess < this->rand_num){
        cout << "To low. Try again\n";
        }
        else{
            cout << "To high. Try again\n";
        }
    }

    this->total_amount -= this->betting_amount;
    cout << "You are out of guesses and have lost your betting amount.\n";
    cout << "New total is: " << this->total_amount << "\n";
    return;
};

void Casino_Game::set_betting_amount(int betting_amount){
    this->betting_amount = betting_amount;
    return;
};

int Casino_Game::get_total(){
    return this->total_amount;
};

void Casino_Game::set_game_mode(string game_mode){
    if (game_mode == "Easy"){
        this->guesses = 10;
        this->multiplier = 2;
    }
    else if(game_mode == "Medium"){
        this->guesses = 7;
        this->multiplier = 5;
    }
    else{
        this->guesses = 5;
        this->multiplier = 10;
    }
    return;
};
