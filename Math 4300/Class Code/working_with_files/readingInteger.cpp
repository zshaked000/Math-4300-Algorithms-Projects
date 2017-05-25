// readingInteger.cpp
// compile with
// c++ -o readInt readingInteger.cpp -std=c++11
// execute with
// ./readInt
#include<iostream>
#include<fstream>

int firstIntInText(char* text, std::streampos size){
  int result=0;
  std::streampos position;
  position=std::streampos(0);
  int finishedReading=0;
  while(
        (position<size) &&
        (text[position]!='-') &&
        ( (text[position]<'0') || (text[position]>'9') )
       ){
        position+= (std::streampos)(1);
  }
  // When we leave the loop we are guaranteed
  // that one of the following happens:
  // 1) end of text and no numbers; i.e. position>=size
  // 2) text[position]='-'
  // 3) text[position] is a digit between '0' and '9'

  if(position<size){
    int multiplyingFactor=1;
    if(text[position]=='-'){
      multiplyingFactor=-1;
      position+= (std::streampos)(1);
    }
    while(
          (position<size)&&
          (text[position]>='0')&&
          (text[position]<='9')
         ){
          result*=10;
          result+= int(text[position]-'0');
          position+= (std::streampos)(1);
        }
    result*=multiplyingFactor;
  }
  return result;
}

int readFirstInteger(std::string fileName){
  int firstInt=0;
  std::ifstream f(fileName, std::ios::in|std::ios:: binary|std::ios::ate);
  if(f.is_open()){
    std::streampos size=f.tellg();
    char *entireText;
    entireText= new char[size];
    f.seekg(0,std::ios:: beg);
    f.read(entireText,size);
    f.close();
    firstInt=firstIntInText(entireText,size);
    delete[] entireText;
  }
  return firstInt;
}
int main(){
  int firstInteger;
  firstInteger= readFirstInteger("exercise1.txt");
  std::cout<<"The first integer is "<<firstInteger<<"."<<std::endl;
  return 0;
}
