//compile with
// c++ -o mS mergeSort.cpp -std=c++11
// execute with
// ./mS

#include<iostream>
using namespace std;
void mTwoSeq(int *a, int*b, int*nSq, int lA, int lB){
  // We assume that the memory is allocated for nSq
  int readerA, readerB, writerN;
  readerA=0;readerB=0;writerN=0;
  while((readerA<lA)||(readerB<lB)){

    // figure out whether nSq[writerN]=a[readerA] or
    //                    nSq[writerN]=b[readerB]
    // perform the correct assignment
    // increment the corresponding reader (readerA
    // or readerB)
    if((readerA<lA)&&(readerB<lB)){
      if(a[readerA]<b[readerB]){
        nSq[writerN]=a[readerA];
        ++readerA;
      }
      else{
        nSq[writerN]=b[readerB];
        ++readerB;
      }
    }
    else{
      if(readerA>=lA){
        nSq[writerN]=b[readerB];
        ++readerB;
      }
      else{
        nSq[writerN]=a[readerA];
        ++readerA;
      }
    }

    ++writerN;
  }
// cout<<"WriterN in the end is "<<writerN<<endl;
}

void mergeSort(int *x, int len){
  if (len>1){
    int newLen=len/2;
    // 1. Sort the left part
    mergeSort(x, newLen);
    // 2. Sort the right part
    mergeSort(x+newLen,len-newLen);
    // 3. Merging two sequences
    // 3.1 Create a new sequence to merge into
    int *newSeq;
    newSeq=new int[len];
    // 3.2 Merge the two sequences into newSeq
    mTwoSeq(x, x+newLen, newSeq,newLen, len-newLen);
    // 3.3 Copy from newSeq to x
    for(int i=0;i<len;++i){
      x[i]=newSeq[i];
    }
    // 3.4. Delete the newSeq
    delete[] newSeq;

  }
}

int oldMain(){
  int * seqA, *seqB, *seqMerged;
  int lenA, lenB;
  int i;
  cout<<"Please insert two sorted sequences that you ";
  cout<<"wish to see merged."<<endl;
  cout<<"First insert their lengths"<<endl;
  cin>>lenA>>lenB;
  seqA=new int[lenA];
  seqB=new int[lenB];
  seqMerged=new int[lenA+lenB];
  cout<<"Insert the first sequence of length "<<lenA<<endl;
  for(i=0;i<lenA;++i){
    cin>>seqA[i];
  }
  cout<<"Insert the second sequence of length "<<lenB<<endl;
  for(i=0;i<lenB;++i){
    cin>>seqB[i];
  }

  mTwoSeq(seqA,seqB,seqMerged,lenA,lenB);
  cout<<"Printing the merged sequence"<<endl;
  for(i=0;i<lenA+lenB;++i){
    cout<<seqMerged[i]<<" ";
  }
  cout<<endl;

  delete[] seqA;
  delete[] seqB;
  delete[] seqMerged;
  return 0;
}
int main(){
  int *x;
  int len;
  std::cout<<" I will sort a sequence for you!"<<std::endl;
  std::cout<<" Length: ";
  std::cin>>len;
  x= new int[len];

  std::cout<<" Please insert a sequence of length "<<len;
  std::cout<<std::endl;

  for(int i=0;i<len;++i){
    std::cin>>x[i];
  }
  std::cout<<"Sorting the sequence:"<<std::endl;
  mergeSort(x,len);
  std::cout<<"Sorting finished! The new sequence is"<<std::endl;
  for(int i=0;i<len;++i){
    std::cout<<x[i]<<" ";
  }
  std::cout<<std::endl;
  delete[] x;
  return 0;
}
