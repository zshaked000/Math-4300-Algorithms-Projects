// sequenceExtension.cpp
// compile with
// c++ -o HW2.2 HW2.2.cpp
// execute with
// ./HW2.2

#include <iostream>
void zerosToOnes(int** pX, int n , int breakpoint){
    int *y;
    // We have to allocate the memory of size n+2 for each time the function is called
    // to accommodate the extended sequence.
    // We will move the sequence *pX to the new extended block
    // and add ones in place of 0's by splitting up y.
    // After these tasks are completed, we will delete *pX
    // and assign the address of the first memory block of y
    // to the address location *pX.
   y=new int[n + 2];
    int i;
    for(i=0;i<breakpoint;++i){
        y[i]=(*pX)[i];
    }
    for(i=breakpoint;i<breakpoint+3;++i){
        y[i]=1;
    }

    for(int i = breakpoint + 3; i < n + 2; ++i)
    {
      y[i] = (*pX)[i - 2];
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
        //std::cin>> x[i];
        std::cin >> *(x + i);
    }
    std::cout<<"Resulting sequence "<<std::endl;
    for(i = 0; i < n; ++i){
      if(*(x + i)==0){
      zerosToOnes(&x,n,i);
      n += 2;
    }
  }

    for(i=0;i<n;++i){
        std::cout<< x[i]<< " ";
    }
    std::cout<<std::endl;
    delete[] x;
    return 0;
}
