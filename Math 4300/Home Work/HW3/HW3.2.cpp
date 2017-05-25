//HW3.2.cpp
//Compile with
//c++ -o HW3.2  HW3.2.cpp
//execute with
// ./HW3.2
#include<iostream>
using namespace std;

void ExtendTheSequence(int size,int extendby, int *x);
void printSeq(int *x, int n);

void ExtendTheSequence(int size,int extendby, int *x){
  int *temp = new int[size + extendby];
  for(int i = 0; i < size + extendby; ++i){
    *(temp+i) = *(x+i)
  }
  delete x;
  x = temp;
}
void printSeq(int *x, int n){
  for(int i = 0 ; i < n; ++i){
    cout << "x contains: " << *(x + i) << endl;
  }
}
//Example: Input: 2 3 4 5 6 7 8 9 -2 3 4 5 6 -1 -2 3 4 5 -9
//        Output: 2 3 4 5 6 7        3             3 4 5




void RemoveTerms(int *x, int *y, int yi , int xi, int counter){
  if(counter != 0) {
    counter--;
    y[yi-coutner] = x[xi + counter];
    RemoveTerms(x , y , xi , yi , counter);
  }
}


int main(){
cout << "Enter the size of your sequnce: ";
int n = 0;
int input = 0;
cin >> n;
int *x = new int[n];
int *y = new int[n];
for(int i = 0; i < n; ++i){
  cout << "Enter sequnce value: ";
  cin >> input;
  *(x + i) = input;
  if(input <= -9){
    break;
  }
  return 0;
}

for(int i = 0; i < n; ++i){
  if(x[i] < 0){
    RemoveTerms(x,y,i);
    continue;
  }
  y[i] = x[i];
}

  return 0;
}
