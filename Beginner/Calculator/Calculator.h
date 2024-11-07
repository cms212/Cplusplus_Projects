#ifndef CALCULATOR_H
#define CALCULATOR_H

using namespace std;
#include<cstdlib>
class Calculator{
    private:
        int num1;
        int num2;
    public:
        Calculator();
        void set_num1(int num);
        void set_num2(int num);
        float add();
        float sub();
        float mult();
        float div();
};

#endif
