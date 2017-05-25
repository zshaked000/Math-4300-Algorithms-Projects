
// pointersIntro01.cpp
// compile with
// c++ -o pIntro01 pointersIntro01.cpp
// execute with
// ./pIntro01
#include <iostream>
int main(){
  int x;
  int *pX;
  x=30;
  pX=&x;
  std::cout<<"pX="<<pX<<std::endl;
  std::cout<<"*pX="<<*pX<<std::endl;
  *pX=45;
  std::cout<<"x="<<x<<std::endl;
  return 0;
}
