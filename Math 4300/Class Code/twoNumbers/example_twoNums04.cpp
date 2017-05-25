
// example_twoNums04.cpp
// compile with
// c++ -o ex2Num04 example_twoNums04.cpp
// execute with
// ./ex2Num04

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

TwoNumbers oppositeNumbers(TwoNumbers myInput){
    std::cout<<"Inside the function oppositeNumbers"<<std::endl;
    TwoNumbers myOutput=myInput; //actually calls copy constructor
    myOutput.x = myOutput.x * (-1);
    myOutput.y = myOutput.y * (-1);
    myOutput.name= myOutput.name+" (output)";
    myInput.name=myInput.name+" (input)";
    std::cout<<"About to exit the function"<<std::endl;
    return myOutput;
}


int main(){
    std::cout<<"Look at me. I will trigger the default constructor!"<<std::endl;
    TwoNumbers firstObject;
    std::cout<<"I will now set the name to Mr. Watson"<<std::endl;
    firstObject.name="Mr. Watson";

    std::cout<<"!!!OPPOSITE NUMBERS!!!"<<std::endl;
    TwoNumbers oppositeObject;
    std::cout<<"Calling the function"<<std::endl;
    oppositeObject=oppositeNumbers(firstObject);
    std::cout<<"Finished the function call and created ";
    std::cout<<oppositeObject.name<<std::endl;

    return 0;
}
