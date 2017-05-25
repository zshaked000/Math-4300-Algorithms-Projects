// pointersNew.cpp
// compile with
// c++ -o pNew pointersNew.cpp
// execute with
// ./pNew
#include <iostream>
int main(){
    int *pX;
    pX=new int;
    *pX=37;
    (*pX)+=17;
    std::cout<<*pX<<std::endl;
    delete pX;
    return 0;
}
