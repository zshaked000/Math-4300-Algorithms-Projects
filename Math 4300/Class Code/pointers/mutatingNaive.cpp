
// mutatingNaive.cpp
// compile with
// c++ -o mNaive mutatingNaive.cpp
// execute with
// ./mNaive
#include <iostream>
void addOneToXAndTwoToY(int x, int y){
  x=x+1;
  y=y+2;
}
int main(){
  int x,y;
  x=5; y=7;
  addOneToXAndTwoToY(x,y);
  std::cout<< "x="<<x<<" and y="<<y<<std::endl;
}
