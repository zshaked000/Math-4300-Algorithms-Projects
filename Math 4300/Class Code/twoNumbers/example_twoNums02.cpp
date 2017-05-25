
// example_twoNums02.cpp
// compile with
// c++ -o ex2Num02 example_twoNums02.cpp
// execute with
// ./ex2Num02

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

void simpleFunctionThatDoesAlmostNothing(){
  TwoNumbers objectInsideTheFunction(9.22);
  objectInsideTheFunction.name="Function Insider";
}
int main(){
    std::cout<<"Look at me. I will trigger the default constructor!"<<std::endl;
    TwoNumbers firstObject;
    std::cout<<"I will now set the name to Mr. Watson"<<std::endl;
    firstObject.name="Mr. Watson";
    std::cout<<"Entering the block"<<std::endl;
    {
      std::cout<<"A block of code inside main"<<std::endl;
      TwoNumbers objectInsideTheBlock(1.99);
      objectInsideTheBlock.name="Block Insider";

    }
    std::cout<<"Out of the block. Calling the function."<<std::endl;
    simpleFunctionThatDoesAlmostNothing();
    std::cout<<"Finished with the function."<<std::endl;
    return 0;
}
