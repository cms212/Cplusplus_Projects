#include "Calculator.h"
#include<cstdlib>
using namespace std;

Calculator::Calculator(){
}

void Calculator::set_num1(int num){
    this->num1 = num;
};

void Calculator::set_num2(int num){
    this->num2 = num;
};

float Calculator::add(){
    return (this->num1 + this->num2);
};

float Calculator::sub(){
    return (this->num1 - this->num2);
};

float Calculator::mult(){
    return ((float)this->num1 * (float)this->num2);
};

float Calculator::div(){
    return ((float)this->num1/(float)this->num2);
};



