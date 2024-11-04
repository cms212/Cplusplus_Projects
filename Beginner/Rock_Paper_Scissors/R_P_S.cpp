#include <iostream>
#include "R_P_S.h"
using namespace std;

int main(){
    cout << "Welcome to Rock Paper Scissors see if you can beat the computer" << "\n";
    string input;
    string c_choice;
    while (true){
    cout << "Choose Rock, Paper, Scissors or type stop to quit playing" << "\n";
    cin >> input;
    if(input == "stop"){
        break;
    }
    else if(input != "Paper" && input != "Rock" && input != "Scissors"){
        cout << "Pick a correct option!\n";
    }
    else {
        c_choice = comp_choice();
        cout << "Computer choosed: " << c_choice << "\n";
        cout << check_win(input, c_choice) << "\n";
    }
    }

    return 0;
}
