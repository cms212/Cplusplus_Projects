#include "Calculator.h"
#include<iostream>
#include<string>

using namespace std;
int main(){
    int num1;
    int num2;
    string operation;
    Calculator C;
    cout << "Welcome to simple calculator. Enter two numbers and then choose the operation to perform.\n";
    while(true){
        cout << "Enter the first number: ";
        cin >> num1;
        C.set_num1(num1);
        cout << "Enter the second number: ";
        cin >> num2;
        C.set_num2(num2);
        while (true){
        cout << "Choose an operation(+,-,*,/):";
        cin >> operation;
        if(operation == "+"){
            cout << C.add() << "\n";
            break;
        }
        else if(operation == "-"){
            cout << C.sub() << "\n";
            break;
        }
        else if(operation == "*"){
            cout << C.mult() << "\n";
            break;
        }
        else if(operation == "/"){
            cout << C.div() << "\n";
            break;
        }
        else{
            cout << "pick a correct operation\n";
        }
    }
}
    return 0;
}