// c++ -o 3.2.1 3.2.01.cpp

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
    delete[] seqToC;
    seqToC = temp;
    *len = newlen; seqToC[i];
    std::cout << "ending len: " << *len << '\n';
    std::cout << "The Shifted Sequence (slideSequence()): " << '\n';
    printSequence(seqToC,*len);
    cout << "memory loaction being sent: " << seqToC << endl;
    return temp;
}

int* compressTheSequence(int *seqToC, int* len , int i = 0) {
    if(i < *len){
      cout << "i: " << i << endl;
      cout << "seqToC[" << i << "]: " << *(seqToC + i) << endl;
      if(seqToC[i] < 0){
        int dist = -1* seqToC[i];
        std::cout << "entering slideSequence" << '\n';
        seqToC = slideSequence(seqToC,len,dist,i);
        cout << "new len: " << *len << endl;
         compressTheSequence(seqToC,len);
      }
      cout << "This function works so far " << endl;
      cout << "seqToC memory location: " << seqToC << endl;
       compressTheSequence(seqToC, len, ++i);
    }
      printSequence(seqToC,*len);
      cout << "I returned seqToC: " << seqToC << endl;

      return seqToC;
}


int main() {
    int *x, *y;
    int numElements = 5;
    // std::cout<<"How many elements are in the sequence? ";
    // std::cin>>numElements;
    x = new int[numElements];
    y = new int[numElements];

    //std::cout<<"Enter the elements of the sequence. "<<std::endl;
        x[0] = 1,
        x[1] = 2,
        x[2] = -1,
        x[3] =  1,
        x[4] =  4;
    for (int i = 0; i<numElements; ++i) {
        //std::cin>>x[i];
        y[i] = x[i];
    }
    cout << "Starting Sequence: " << endl;
    printSequence(y, numElements); cout << endl;
    //slideSequence(y,&numElements,1,2); //remove this and uncomment below
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
