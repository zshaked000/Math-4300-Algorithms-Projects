// c++ -o 3.2.3 HW3.2.3.cpp
//This one works but doesnt use recursion

#include <iostream>
typedef long int myint;
using namespace std;

void printSequence(int *x, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << x[i] << " ";
    }
        cout<<endl;
}

void copySequence(int *x, int* y, int len, int begin = 0) {
    for (int i = begin; i < len; ++i) {
        y[i] = x[i];
    }
  }
//this works
//*len has to be the new length or  len-dist
int* slideSequence(int *seqToC, int * len ,int dist, int i){
    cout << "memory location recieved: " << seqToC << endl;
    cout << "starting len: " << *len << endl;
    int newlen = *len - dist - 1;
    int *temp = new int[newlen];
    for(int k = 0; k < i - dist; ++k){
      temp[k] = seqToC[k];
    }

    int j = 1;
    for(int k = i - dist; k < newlen; ++k ){
        temp[k] = seqToC[i+j];
        j++;
    }
    //delete[] seqToC;
    seqToC = temp;
    *len = newlen;
    std::cout << "ending len: " << *len << '\n';
    std::cout << "The Shifted Sequence (slideSequence()): " << '\n';
    printSequence(seqToC,*len);
    cout << "memory loaction being sent: " << seqToC << endl;
    return temp;
}
//This one works
int* compressTheSequence(int *seqToC, int* len){
  if(*len > 1){
    for(int i = 0; i < *len; ++i){
      if(seqToC[i] < 0){
        int dist = -1*seqToC[i];
        seqToC = slideSequence(seqToC,len,dist,i);
        cout << "Seq after slideSequence(): ";
        printSequence(seqToC,*len);
      }
    }
  }
    // cout << "Seq after compressTheSequence(): " << endl;
    // printSequence(seqToC,*len);
    return seqToC;
}


int main() {
    int *x, *y;
    int numElements = 5;
    std::cout<<"How many elements are in the sequence? ";
    std::cin>>numElements;
    x = new int[numElements];
    y = new int[numElements];

    std::cout<<"Enter the elements of the sequence. "<<std::endl;
        // x[0] = 1,
        // x[1] = 2,
        // x[2] = 2,
        // x[3] =  -2,
        // x[4] =  4;
    for (int i = 0; i<numElements; ++i) {
        std::cin>>x[i];
        y[i] = x[i];
    }
    cout << "Starting Sequence: " << endl;
    printSequence(y, numElements); cout << endl;
    std::cout << "Starting compression" << std::endl;
    y = compressTheSequence(y, &numElements);
    cout << "Ending Compress the sequence" << endl;
    std::cout << "y mem loc:      " << y << "\ny output: " << '\n';
    for (int i = 0; i<numElements; ++i) {
       std::cout << y[i]<< " "; ;
    }
    std::cout << std::endl;
    delete[] x;
    delete[] y;
    return 0;
}
