// multiplyIntegersBy5.cpp
// compile with
// c++ -o multBy5 multiplyIntegersBy5.cpp
// execute with
// ./multBy5
#include <iostream>
int main(){
    int n;
    std::cout<<"What is n? ";
    std::cin>>n;
    std::cout<<"Enter the sequence of "<<n<<" integers."<<std::endl;
    int* pX;
    pX=new int[n];
    int i;
    for(i=0;i<n;++i){
        std::cin>> *(pX+i);
    }
    std::cout<<"Each integer gets multiplied by 5. "<<std::endl;
    for(i=0;i<n;++i){
        std::cout<< 5 * (*(pX+i))<< " ";
    }
    std::cout<<std::endl;
    delete[] pX;
    return 0;
}
