// mainProg_move.cpp
// compile with
// c++ -o books_move mainProg_move.cpp -std=c++11 -fno-elide-constructors
// execute with
// ./books_move
#include<iostream>
#include<string>
using namespace std;
class Library{
public:
  string* books;
  int nOfBooks;
};
class Uni{
private:
  Library l;
public:
  Uni();
  Uni(const Uni&);
  Uni(Uni &&);
  void operator=(const Uni&);
  void operator=(Uni&&);
  int getNumberOfBooks() const;
  string getBookName(const int &) const;
  void setBookName(const int &,const string&);
  void setNumberOfBooks(const int&);
  void printAllBooks() const;
  string* getPointerToBooks() const;
  void victimOfTheft();
  ~Uni();
};
string* Uni::getPointerToBooks() const{
  return l.books;
}
void Uni::victimOfTheft(){
  l.nOfBooks=0;
  l.books=nullptr;// I do not delete[]
}

Uni::Uni(){
  cout<<"DEFAULT CONSTRUCTOR"<<endl;
  l.nOfBooks=0;
  l.books=nullptr;
}
Uni::Uni(const Uni &_copyFrom){
  cout<<"COPY CONSTRUCTOR"<<endl;
  // DON'T DO THIS: l=_copyFrom.l;
  // THIS WOULD ONLY SHARE THE Library
  l.nOfBooks=_copyFrom.getNumberOfBooks();
  if(l.nOfBooks>0){
    l.books=new string[l.nOfBooks];
  }
  else{
    l.books=nullptr;
  }
  for(int i=0;i<l.nOfBooks;++i){
    l.books[i]=_copyFrom.getBookName(i);
  }


}
Uni::Uni(Uni&& moveFrom){
  cout<<"MOVE CONSTRUCTOR"<<endl;
  l.nOfBooks=moveFrom.getNumberOfBooks();
  l.books=moveFrom.getPointerToBooks();
  moveFrom.victimOfTheft();

}

void Uni::operator=(const Uni &_copyFrom){
  cout<<"COPY ASSIGNMENT"<<endl;
  // DON'T DO THIS: l=_copyFrom.l;
  // THIS WOULD ONLY SHARE THE Library
  if(l.books!=nullptr){
    delete[] l.books;
  }
  l.nOfBooks=_copyFrom.getNumberOfBooks();
  if(l.nOfBooks>0){
    l.books=new string[l.nOfBooks];
  }
  else{
    l.books=nullptr;
  }
  for(int i=0;i<l.nOfBooks;++i){
    l.books[i]=_copyFrom.getBookName(i);
  }


}
void Uni::operator=(Uni &&moveFrom){
  cout<<"MOVE ASSIGNMENT"<<endl;
  if(l.books!=nullptr){
    delete[] l.books;
  }
  l.nOfBooks=moveFrom.getNumberOfBooks();
  l.books=moveFrom.getPointerToBooks();
  moveFrom.victimOfTheft();
}

int Uni::getNumberOfBooks() const{
  return l.nOfBooks;
}
string Uni::getBookName(const int &i) const{
  return (l.books)[i];
}
void Uni::setBookName(const int &i, const string &bookName){
  (l.books)[i]=bookName;
}
void Uni::setNumberOfBooks(const int & _nOfB){
  if(_nOfB!=l.nOfBooks){
    // Step 1: Allocate new memory
    string * newBooks;
    if(_nOfB>0){
      newBooks=new string[_nOfB];
    }
    else{
      newBooks=nullptr;
    }
    // Step 2: Copy
    int minNum=_nOfB;
    if(_nOfB>l.nOfBooks){minNum=l.nOfBooks;}
    for(int i=0;i<minNum;++i){newBooks[i]=(l.books)[i]; }
    // Step 3: Delete the old
    if(l.books!=nullptr){delete[] l.books;}
    // Step 4: Update the books
    l.books=newBooks;
    // Step 5: Update the number of books
    l.nOfBooks=_nOfB;
  }
}
Uni::~Uni(){
  cout<<"DESTRUCTOR: ";
  if(l.nOfBooks>0){
    cout<<l.books[0];
  }

  if(l.books!=nullptr){
    delete[] l.books;
  }
  else{
    cout<<" I am a victim of theft";
  }
  cout<<endl;
}


void Uni::printAllBooks() const{
  for(int i=0;i<l.nOfBooks;++i){
    std::cout<<l.books[i]<<", ";
  }
  std::cout<<std::endl;
}
string newestBook(const Uni& inputUni){
  int tNB= inputUni.getNumberOfBooks();
  string bookNameToReturn=inputUni.getBookName(tNB-1);
  return bookNameToReturn;
}
Uni makeFunnyUniversity(const Uni &input){
  Uni kgU;
  kgU= input;
  int tNB=input.getNumberOfBooks();
  for(int i=0;i<tNB;++i){
    string newString=input.getBookName(i);
    newString=newString+" Kindergarten";
    kgU.setBookName(i,newString);
  }
  return kgU;
}


int main(){
  Uni Baruch;
  Baruch.setNumberOfBooks(5);
  Baruch.setBookName(0,"Baruch College"); Baruch.setBookName(1,"Animal Farm");
  Baruch.setBookName(2,"The Giving Tree"); Baruch.setBookName(3,"Cat in the Hat");
  Baruch.setBookName(4,"Frankenstein");
//  string lastBookName;
  Uni fun_U;
  cout<<"Function calling"<<endl;
  //lastBookName=newestBook(Baruch);

  fun_U=makeFunnyUniversity(Baruch);
  cout<<"Function finished"<<endl;
  //cout<<"Newest book is "<<lastBookName<<endl;
  cout<<"Printing the books"<<endl;
  fun_U.printAllBooks();
  return 0;
}
