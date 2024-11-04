

#ifndef R_P_S
#define R_P_S
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int random_num_gen(){
    srand((unsigned) std::time(NULL));
    return rand() % 3; 
}

string comp_choice(){
    int num = random_num_gen();
    if (num == 0){
        return "Rock";
    }
    else if (num == 1){
        return "Paper";
    }
    return "Scissors";
}



string check_win(string input, string comp_choice){
    if (input == comp_choice){
        return "Tie";
    }
    else if (input == "Rock"){
        if (comp_choice == "Paper"){
            return "Computer Wins";
        }
        else{
            return "Human wins";
        }
    }
    else if (input == "Paper"){
        if (comp_choice == "Scissors"){
            return "Computer Wins";
        }
        else{
            return "Human wins";
        }
    }
    else if (input == "Scissors"){
        if (comp_choice == "Rock"){
            return "Computer Wins";
        }
        else{
            return "Human wins";
        }
    }
}
#endif