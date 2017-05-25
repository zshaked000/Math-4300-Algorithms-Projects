// compression.cpp
// compile with
// c++ -o compr compression.cpp
// execute with
// ./compr

// PROBLEM:
// The input consists of a number n and a sequence
// of integers of length n, whose terms are
// 0, 1, and 2.
// The comperssion of the sequence consists of
// replacing the first occurrence of the same two numbers
// by one number according to the following rules:
// 0 0 is replaced by 1;
// 1 1 is replaced by 2;
// 2 2 is replaced by 0;
// The new sequence is then subject to a new compression,
// if possible. The procedure is repeated until
// we obtain a sequence that can't be further compressed.
// Print the final sequence.

#include <iostream>
typedef long int myint;

void compressTheSequence(int *seqToC, int* len){
    if(*len>1){
      int i=0, indicator=0;
      while((i<(*len)-1)&&(indicator==0)){
        if(seqToC[i]==seqToC[i+1]){
          indicator=1;
          seqToC[i]+=1;
          if(seqToC[i]==3){
            seqToC[i]=0;
          }
          ++i;
          (*len)-=1;
          while(i<(*len)){
            seqToC[i]=seqToC[i+1];
            ++i;
          }

        }
         
        ++i;
      }


      if(indicator==1){compressTheSequence(seqToC,len);}
    }

}

 int main(){

    int *inputSequence, *outputSequence;
    int numElements;
    std::cout<<"How many elements are in the sequence? ";
    std::cin>>numElements;
    inputSequence=new int[numElements];
    outputSequence=new int[numElements];
    std::cout<<"Enter the elements of the sequence. "<<std::endl;
    for(int i=0;i<numElements;++i){
      std::cin>>inputSequence[i];
      outputSequence[i]=inputSequence[i];
    }
    std::cout<<"Starting compression"<<std::endl;

    compressTheSequence(outputSequence,&numElements);
    for(int i=0;i<numElements;++i){
      std::cout<<outputSequence[i]<<" ";
    }
    std::cout<<std::endl;
    delete[] inputSequence;
    delete[] outputSequence;
    return 0;
}
