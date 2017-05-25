
// example_twoNums01.cpp
// compile with
// c++ -o ex2Num01 example_twoNums01.cpp
// execute with
// ./ex2Num01

#include <iostream>

class TwoNumbers{

public:
    double x;
    double y;
    std::string name;
    TwoNumbers(const double & =3.14159265);
    ~TwoNumbers();
};
TwoNumbers::TwoNumbers(const double & xValue){
    std::cout<<"DEFAULT CONSTRUCTOR with xValue="<<xValue<<std::endl;
    x=xValue;
    y=27.72;
    name="noNameSoFar";
}
TwoNumbers::~TwoNumbers(){
    std::cout<<"DESTRUCTOR FOR "<<name<<std::endl;
}
int main(){
    std::cout<<"Look at me. I will trigger the default constructor!"<<std::endl;
    TwoNumbers firstObject;
    std::cout<<"I will now set the name to Mr. Watson"<<std::endl;
    firstObject.name="Mr. Watson";
    return 0;
}
