// arrangements.cpp
// compile with
// c++ -o arr01 arrangements.cpp
// execute with
// ./arr01

// PROBLEM:
// The input consists of a number numInv and a
// sequence of length numInv that represents the
// inventory of objects.
// List the all possible arrangments of these objects
// in a line.
// For example if numInv = 3 and if the sequence of
// inventory is 2, 2, 1
// then we have 2 objects 0; 2 objects 1, and 1 object 2
// Then the arrangements are
// 0 0 1 1 2
// 0 0 1 2 1
// 0 0 2 1 1
// 0 1 0 1 2
// ...
// 2 1 0 1 0
// 2 1 1 0 0


#include <iostream>
typedef long int myint;
/*
arg1: This function takes in the arrangements array which is filled with number of
each sequential integer i.e. array of size 3 with elements 1 2 3 will have
one "0" two "1"'s and three "2"'s
arg2: next it takes in the inventory which is the array containing the number of each
sequential integer to be put in the array above

arg3: next it takes in the size of the first array

arg4: next it takes in the number of objects which is number of we are going up to
i.e. 1 2 3 4 5 would be size 5 and the we write in the first array how many of
each of these elements to put in the array

arg5: where should we begin in the array 

*/
void getArrangements(int *cArr, int *inventory,
                    int nObj, int nInv, int currentObj){
    if(currentObj<nObj){
      for(int i=0;i<nInv;++i){
        if(inventory[i]>0){
          inventory[i]-=1;
          cArr[currentObj]=i;
          getArrangements(cArr,inventory,nObj, nInv, currentObj+1);
          inventory[i]+=1;
        }
      }
    }
    else{
      for(int i=0;i<nObj;++i){
        std::cout<<cArr[i]<<" ";
      }
      std::cout<<std::endl;

    }


}

 int main(){

    int *inventory, *arrangement;
    int numInv,numObjects;
    std::cout<<"How many elements are in the inventory? ";
    std::cin>>numInv;
    inventory=new int[numInv];
    std::cout<<"List the inventory. "<<std::endl;
    numObjects=0;
    for(int i=0;i<numInv;++i){
      std::cin>>inventory[i];
      numObjects+=inventory[i];
    }
    arrangement=new int[numObjects];
    getArrangements(arrangement,inventory,numObjects,numInv,0);
    delete[] inventory;
    delete[] arrangement;
    return 0;
}
