// sourceWritingFunction.cpp
// Compile using the command
// c++ -o writingFunction sourceWritingFunction.cpp -std=c++11
// Execute using the command
// ./writingFunction
#include<iostream>
#include<fstream>
void writeToFile(std::string fileName, int n){
  std::ofstream f;
  f.open(fileName);
  f <<"The number "<<n<<" is very beautiful."<<std::endl;
  f.close();
}
int main(){
  int x;
  std::cin>>x;
  writeToFile("exercise1.txt",x);
  return 0;
}
