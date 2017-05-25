// writingHelloWorld.cpp
// compile with the command:
// c++ -o wrHelloWorld writingHelloWorld.cpp -std=c++11
// execute with command
// ./wrHelloWorld
#include<iostream>
#include<fstream>
int main(){
  std::ofstream f;
  f.open("myFile.txt");
  f<<"Hello world"<<std::endl;
  f.close();
  return 0;
}
