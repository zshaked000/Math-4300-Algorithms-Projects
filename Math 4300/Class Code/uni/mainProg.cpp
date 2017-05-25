// mainProg.cpp
// compile with
// c++ -o books mainProg.cpp
// execute with
// ./books
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
  void operator=(const Uni&);
  int getNumberOfBooks() const;
  string getBookName(const int &) const;
  void setBookName(const int &,const string&);
  void setNumberOfBooks(const int&);
  void printAllBooks() const;
  ~Uni();
};
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
void Uni::operator=(const Uni &_copyFrom){
  cout<<"COPY ASSIGNMENT"<<endl;
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
  cout<<endl;
  if(l.books!=nullptr){
    delete[] l.books;
  }
}


void Uni::printAllBooks() const{
  for(int i=0;i<l.nOfBooks;++i){
    std::cout<<l.books[i]<<", ";
  }
  std::cout<<std::endl;
}
int main(){
  Uni Baruch;
  Baruch.setNumberOfBooks(5);
  Baruch.setBookName(0,"Baruch College users manual"); Baruch.setBookName(1,"Animal Farm");
  Baruch.setBookName(2,"The Giving Tree"); Baruch.setBookName(3,"Cat in the Hat");
  Baruch.setBookName(4,"Frankenstein");
//  Baruch.printAllBooks();
  Uni someEvilUni(Baruch);
  someEvilUni.setBookName(0,"Evil University users manual");
  Uni lessEvil;
  lessEvil=Baruch;
  lessEvil.setBookName(0,"Less Evil and not so much writing");


  std::cout<<"Printing books of Evil University"<<std::endl;
  someEvilUni.printAllBooks();
  std::cout<<"Printing books of Less Evil University"<<std::endl;
  lessEvil.printAllBooks();
  std::cout<<"Printing our books"<<std::endl;
  Baruch.printAllBooks();
}
