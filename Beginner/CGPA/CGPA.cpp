#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, double> classes;

    cout << "Welcome to the Cumilaitve Grada Point Average Calculator!" << endl;
    cout << "Please enter the number of classes you took this semester: ";
    int num_classes;
    cin >> num_classes;
    


    cout << "Please enter the name of each course taken." << endl;
    string class_name;
    for (int i = 0; i < num_classes; i++){
        cout << "Enter name for class " << i+1 << ": ";
        cin >> class_name;
        classes[class_name] = 0;
        
    }

    
    cout << endl;
    cout << "Please enter score for each course. Grade Scale as follows" << endl;
    cout << "A: 4" << endl << "B: 3" << endl << "C: 2" << endl << "D: 1" << endl << "E: 0" << endl;
    double class_score;
    for (auto i:classes){
        cout << "Score for " << i.first << ": ";
        cin >> class_score;
        classes[i.first] = class_score;
    }

    double quality_points = 0;
    double credit_hours = 0;

    cout << endl;
    cout << "Please enter number of credits for each course." << endl;
    double class_credits;
    for (auto i:classes){
        cout << "Number of credits for " << i.first << ": ";
        cin >> class_credits;
        credit_hours += class_credits;
        quality_points += class_credits * i.second;
    }

    
   
    double score = quality_points / credit_hours;
    cout << endl << "Cumilative Grade Point Average for this semester is: " << score << endl;
    return 0;

}