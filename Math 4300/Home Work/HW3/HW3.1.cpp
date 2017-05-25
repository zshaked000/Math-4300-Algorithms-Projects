//HW3.1.cpp
//Compile with
//c++ -o HW3.1  HW3.1.cpp
//execute with
// ./HW3.1
#include <iostream>
#include <math.h>

int f(int n,int p,int a){
if(n == 0){
  return a;
}
int result = (f(n-1,p,a)*f(n-1,p,a) + f(n-1,p,a) + 1)%p;
return result;
}

int main(int argc, char const *argv[]) {
  int n,p,a;
  std::cout << "Enter in n: "; std::cin >>n;
  std::cout << "Enter in p: "; std::cin >>p;
  std::cout << "Enter in a: "; std::cin >>a;
  std::cout << "f is " << f(3,2,5) << std::endl;

  return 0;
}
