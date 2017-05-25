
// mutatingCorrect.cpp
// compile with
// c++ -o mCorrect mutatingCorrect.cpp
// execute with
// ./mCorrect
#include <iostream>
void addOneToXAndTwoToY(int* pX, int* pY){
  (*pX)=(*pX)+1;
  (*pY)=(*pY)+2;
}
int main(){
  int x,y;
  x=5; y=7;
  addOneToXAndTwoToY(&x,&y);
  std::cout<< "x="<<x<<" and y="<<y<<std::endl;
}
