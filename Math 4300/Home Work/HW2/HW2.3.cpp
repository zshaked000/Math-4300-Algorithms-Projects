// HW2.3.cpp
// compile with
// c++ -o HW2.3 HW2.3.cpp -std=c++11
// execute with
// ./HW2.3

#include<iostream>
#include<fstream>

//Function Declaration
std::string readCharacters(std::string fileName);
int readFirstInteger(std::string fileName);
//int firstIntInText(char *text, std::streampos size);
int NextIntInText(char *text, std::streampos size, std::streampos *pos);
void readSequenceFromFile(std::string filename, int** sequencePointer, int *length);
std::streampos fileSize(std::string fileName);
void printToFile(std::string filename, int *seq, int len );
//










std::string readCharacters(std::string fileName){
 // The result of the function will be stored in finalString
 // We first initialize the variable as
 std::string finalString="";

 // A file that we will read from is an object of the class std::ifstream
 std::ifstream f(fileName, std::ios::in|std::ios:: binary|std::ios::ate);
 //opens a file called file name, tells it that its an input stream,tells it to
 //open in binary format at the last postion of the file
 // The previous line opens a file whose name is the first argument.
 // The second argument consists of flags. We will skip the details
 // since in this course we will always open the files in this very same way.


 if(f.is_open()){
 // If the file did not exist or is corrupted, then is_open() would be false.
 // It is always a good idea to check whether the file is open before reading.


 // The next line finds out the size of the file. The method tellg() returns the size.
 // However, it does not return an integer. It returns and object of the class std::streampos.
 //since we start off with the pointer at the end of the file the position that tellg
 //returns is the size
 std::streampos size = f.tellg();

 // The entire file will be now read as a sequence of characters. We first need to initialize
 // a sequence of sufficient length.
 char *entireText; //says give me a pointer to a character
 entireText= new char[size];// says allocate size number of slots


 // The next two lines store the content of the file in the sequence entireText
 //this line says set the read position to 0 positions over from the beigining
 //the file, which is the first postion in the file
 f.seekg(0,std::ios:: beg);
 //this says read the the file
 //extracts size number of characters from the file f and stores them in
 //the entire text character array by pointing the memory location of each
 //character to a spot in the array
 f.read(entireText,size);

 // We can now close the file since we finished reading.
 f.close();

 if(size< 5){
 // In this case the file is too small to extract the first 5 characters.
 finalString="The entire file does not have five characters.";
 }
 else{
 for(int i=0;i<size;++i){
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










//Function to tell us the first integer in or file
int readFirstInteger(std::string fileName){
int firstInt = 0;
std::ifstream file;
//this will open the file and move us to the last postion of the file
//it takes the content in the binary or text format
file.open(fileName,std::ios::in|std::ios:: binary|std::ios::ate);

if(file.is_open()){
  //this will tell us the size by telling us the current position we are in
  //in the file
   std::streampos size=file.tellg();
   char *entireText;
   entireText= new char[size];
   //shift our positon to the beginning of the file to begin reading
   file.seekg(0,std::ios::beg);
   file.read(entireText,size);
   file.close();
   //this function will find us the first int from the character array we sent
   //it
   //firstInt=NextIntInText(entireText,size,std::streampos(0));
   std::streampos pos =  std::streampos(0);

   firstInt=NextIntInText(entireText,size, &pos);
   delete[] entireText;
}
  return firstInt;
}

char * getText(std::string filename){
std::ifstream file;
file.open(filename,std::ios::in|std::ios:: binary|std::ios::ate);
char *entireText;
if(file.is_open()){
  std::streampos size=file.tellg();

  entireText= new char[size];
  //shift our positon to the beginning of the file to begin reading
  file.seekg(0,std::ios::beg);
  file.read(entireText,size);
  file.close();
  //this function

}
  return entireText;
}










int NextIntInText(char *text, std::streampos size, std::streampos *pos){
  int result = 0;
  std::streampos position = std::streampos(*pos);
  int finishedReading=0;

  //This while loop gets us to the postion of an integer
  while(
  (position<size) &&
  (text[position]!='-') &&
  ( (text[position]<'0') || (text[position]>'9') )
  ){
  position+= (std::streampos)(1);
  }


 if(position<size){
 int multiplyingFactor=1;
 if(text[position]=='-'){
 multiplyingFactor=-1;
 position+= (std::streampos)(1);
 }
 /*
 for(int j = 0; j < size; ++j){
   std::cout << text[j] << std::endl;
 }*/
 while( (position<size)&&(text[position]>='0')&& (text[position]<='9') ){
 result*=10;
 //std::cout << "Whats being read from the current text position: " << text[position] << std::endl;
 result+= int(text[position]-'0');
 position+= (std::streampos)(1);
 }
 result*=multiplyingFactor;
 }
 *pos = position;//just added
 return result;
}








std::streampos fileSize(std::string fileName){
  std::ifstream f(fileName, std::ios::in|std::ios:: binary|std::ios::ate);
  //opens a file called file name, tells it that its an input stream,tells it to
  //open in binary format at the last postion of the file
  // The previous line opens a file whose name is the first argument.
  // The second argument consists of flags. We will skip the details
  // since in this course we will always open the files in this very same way.
  std::streampos size;

  if(f.is_open()){
  // If the file did not exist or is corrupted, then is_open() would be false.
  // It is always a good idea to check whether the file is open before reading.


  // The next line finds out the size of the file. The method tellg() returns the size.
  // However, it does not return an integer. It returns and object of the class std::streampos.
  //since we start off with the pointer at the end of the file the position that tellg
  //returns is the size
  size = f.tellg();


  // We can now close the file since we finished reading.
  f.close();
}
return size;

};
















void readSequenceFromFile(std::string filename, int** sequencePointer, int *length,std::streampos* pos){
char *text;
//text = new char[filename.length()]; changing this
//text = (char*)readCharacters(filename).c_str(); //this was already commented out ignore
//text = &filename[0]; //trying to find the fault changing this
int size = fileSize(filename); // trying to find the fautl
text = new char[size];
text = getText(filename);//just added
//std::cout << "*length before the function NextIntInText is called: " << *length << std::endl;
*length = NextIntInText(text,size, pos);//change the stream trying to find the fault
//position later to move around dynamically
//std::cout << "The first integer in the string is: " << *length << std::endl;
int *seq = new int[*length];
int numInSeq = 0;
for(int i = 1; i < *length + 2; ++i){ //changed  + 1 to + 2
  numInSeq = NextIntInText(text,size,pos);
  if(numInSeq == -9){
    while(i < *length + 2) // changed 1 to 2
    {
      *(seq + i - 1) = 0;
      std::cout << "*(seq + i - 1) = " << *(seq + i - 1) << std::endl;
      ++i;
    }
    break;
  }
  *(seq + i - 1) = numInSeq;
  //std::cout << "The (" << i << ") int in the text is " << *(seq + i - 1) << std::endl;
}

//std::cout << "The sequence of numbers read from the file and save in seq is as follws "
//<< std::endl;
for(int i = 0; i < *length + 1 ; ++i){
//  std::cout << *(seq + i) << " "; // reads out the sequence
}
 *sequencePointer = seq;
}

void printToFile(std::string filename, int *seq, int len ){
std::ofstream file;
file.open(filename);
for(int i = 0; i < len; ++i){
if(i == len - 1)
{
  file << *(seq + i);
  break;
}
file << *(seq + i) << " , ";
}
file.close();
}







int main(){
 std::string st;
 //st=readCharacters("/Users/a123456/Desktop/Math 4300/OpeningFilesTest/Test.txt");
st = readCharacters("dataForHW2.txt");
 //std::cout<<st<<std::endl; read out entire string

 std::string filename = "dataForHW2.txt";
 char * fname = new char[filename.length()];
 fname = &filename[0];
 int *x = new int;
 *x = 5;
 int *len = new int;
// void readSequenceFromFile((char*)filename, &x,NULL);
 //readSequenceFromFile(fname, &x,NULL); old way the function was set up, NULL leads to a segmentation fault

 std::streampos *begin = new std::streampos;
 *begin = std::streampos(0);
 readSequenceFromFile(filename, &x,len,begin); // fault is from this function changed &x

int *y = new int[*len];
int temp = 0;
//std::cout << "What the sequecne pointer contains" << '\n';
 for(int i = 0; i < *len ; ++i){
   //std::cout << *(x + i) << " ";
   temp += *(x + i);
   *(y + i) = temp;
   //std::cout << *(y + i) << " ";
 }
  std::string newFileName = "hw2Output.txt";
  printToFile(newFileName, y, *len);
 return 0;
}
