#include<iostream>
#include<cmath>

int main() {
  std::cout << "enter the positive integer: ";
  int counter = 0;
  int num;
  int times10 = 1;
  int curbin;
  std::cin >> num;
  int bin;
  int remainder = 0;
  int division = num;
  while(division != 0){
    remainder = division%2;
    if(remainder == 0){
    division = division/2;
  }
  else{
    division--;
    division  = division/2;
  }
    times10 = 1;
     for(int i = 0; i < counter; ++i){
     times10 =  times10 *10;
     }
    curbin = remainder*times10;//pow(10,counter);
    bin += curbin;
    counter++;
  }
  std::cout << num << " in binary is " << bin <<std::endl;;
  return 0;
}
