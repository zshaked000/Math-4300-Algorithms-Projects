// readingFiveCharacters.cpp
// compile with
// c++ -o readingFive readingFiveCharacters.cpp -std=c++11
// execute with
// ./readingFive
#include<iostream>
#include<fstream>
std::string readTheFirstFiveCharacters(std::string fileName){
  // The result of the function will be stored in finalString
  // We first initialize the variable as
  std::string finalString="";

  // A file that we will read from is an object of the class std::ifstream
  std::ifstream f(fileName, std::ios::in|std::ios:: binary|std::ios::ate);
  // The previous line opens a file whose name is the first argument.
  // The second argument consists of flags. We will skip the details
  // since in this course we will always open the files in this very same way.


  if(f.is_open()){
    // If the file did not exist or is corrupted, then is_open() would be false.
    // It is always a good idea to check whether the file is open before reading.


    // The next line finds out the size of the file. The method tellg() returns the size.
    // However, it does not return an integer. It returns and object of the class std::streampos.
    std::streampos size=f.tellg();

    // The entire file will be now read as a sequence of characters. We first need to initialize
    // a sequence of length size.
    char *entireText;
    entireText= new char[size];


    // The next two lines store the content of the file in the sequence entireText
    f.seekg(0,std::ios:: beg);
    f.read(entireText,size);

    // We can now close the file since we finished readaing.
    f.close();
    
    if(size< 5){
      // In this case the file is too small to extract the first 5 characters.
      finalString="The entire file does not have five characters.";
    }
    else{
      for(int i=0;i<5;++i){
        finalString+=entireText[i];
      }
    }
    delete[] entireText;
  }
  else{
    finalString="Could not open the file properly.";
  }
  return finalString;
}
int main(){
  std::string st;
  st=readTheFirstFiveCharacters("exercise1.txt");
  std::cout<<st<<std::endl;
  return 0;
}
