
// example_twoNums03.cpp
// compile with
// c++ -o ex2Num03 example_twoNums03.cpp
// execute with
// ./ex2Num03

#include <iostream>

class TwoNumbers{

public:
    double x;
    double y;
    std::string name;
    TwoNumbers(const double & =3.14159265);
    TwoNumbers(const TwoNumbers &);
    void operator=(const TwoNumbers &);
    ~TwoNumbers();
};
TwoNumbers::TwoNumbers(const double & xValue){
    std::cout<<"DEFAULT CONSTRUCTOR with xValue="<<xValue<<std::endl;
    x=xValue;
    y=27.72;
    name="noNameSoFar";
}
TwoNumbers::TwoNumbers(const TwoNumbers& copyFrom){
    std::cout<< "COPY CONSTRUCTOR"<< std::endl;
    x=copyFrom.x;
    y=copyFrom.y;
    name=copyFrom.name+" (copy)";
}
void TwoNumbers::operator=(const TwoNumbers & assignFrom){
    std::cout<<"ASSIGNMENT OPERATOR"<<std::endl;
    x=assignFrom.x;
    y=assignFrom.y;
    name=assignFrom.name+" (assigned)";
}
TwoNumbers::~TwoNumbers(){
    std::cout<<"DESTRUCTOR FOR "<<name<<std::endl;
}
int main(){
    std::cout<<"Look at me. I will trigger the default constructor!"<<std::endl;
    TwoNumbers firstObject;
    std::cout<<"I will now set the name to Mr. Watson"<<std::endl;
    firstObject.name="Mr. Watson";

    TwoNumbers secondObject(firstObject); // calling copy-constructor for secondObject
    TwoNumbers thirdObject=firstObject; // again, calling copy-constructor for thirdObject
    // The previous two lines of code do the same thing: call copy-constructor
    std::cout<<"Calling the assignment operator"<<std::endl;
    thirdObject=firstObject;

    return 0;
}
