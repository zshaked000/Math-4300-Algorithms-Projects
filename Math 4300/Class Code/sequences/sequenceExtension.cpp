// sequenceExtension.cpp
// compile with
// c++ -o seqExt sequenceExtension.cpp
// execute with
// ./seqExt
#include <iostream>
void extendTheSequence(int** pX, int n){
    int *y;
    // We have to allocate the memory of the size n+(*pX)[n-1]
    // to accommodate the extended sequence.
    // We will move the sequence *pX to the new extended block
    // and add ones in the end of y.
    // After these tasks are completed, we will delete *pX
    // and assign the address of the first memory block of y
    // to the address location *pX.
    y=new int[n+(*pX)[n-1]];
    int i;
    for(i=0;i<n;++i){
        y[i]=(*pX)[i];
    }
    for(i=n;i<n+(*pX)[n-1];++i){
        y[i]=1;
    }
    delete[] *pX;
    *pX=y;
}
int main(){
    int n;
    std::cout<<"What is n? ";
    std::cin>>n;
    std::cout<<"Enter the sequence of "<<n<<" integers."<<std::endl;
    int* x;
    x=new int[n];
    int i;
    for(i=0;i<n;++i){
        std::cin>> x[i];
    }
    std::cout<<"Extending the sequence "<<std::endl;
    extendTheSequence(&x,n);
    for(i=0;i<n+x[n-1];++i){
        std::cout<< x[i]<< " ";
    }
    std::cout<<std::endl;
    delete[] x;
    return 0;
}
