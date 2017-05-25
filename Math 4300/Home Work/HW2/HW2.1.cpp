// HW2.1.cpp
// compile with
// c++ -o HW2.1 HW2.1.cpp
// execute with
// ./HW2.1

#include <iostream>
class ListNode{
public:
    int content;
    ListNode *pointerToNext;
};
void freeTheMemory(ListNode *runner){
    if( runner!=NULL){
        freeTheMemory((*runner).pointerToNext);
        delete runner;
    }
}
int main(){
    int userInput;
    ListNode *head;
    std::cout<<"Insert the first element of the list: ";
    std::cin>>userInput;
    head=new ListNode;
    (*head).content=userInput;
    (*head).pointerToNext=NULL;
    ListNode *runner;
    runner=head;
    while(userInput!=-9){
        std::cout<<"Insert an element of the list (-9 for the end): ";
        std::cin>>userInput;
        if(userInput!=-9){
            // *runner is the last node in the list (tail)
            // (*runner).pointerToNext is currently NULL
            // We now allocate new memory for ListNode and make
            // (*runner).pointerToNext to contain the address
            // of this new ListNode
            (*runner).pointerToNext=new ListNode;

            // runner is no more pointing to the tail
            // The next line updates the runner to point
            // to the newly created tail
            runner=(*runner).pointerToNext;

            // We now set the content of the tail
            (*runner).content=userInput;
            // and make sure that the tail's pointer
            // to the the next is set to NULL
            (*runner).pointerToNext=NULL;
        }
    }
    std::cout << "enter number to be removed: " << std::endl;
    int remove;
    std::cin >> remove;
    std::cout<<"List printout: "<<std::endl;
    runner=head;
    while(runner!=NULL){
      if((*runner).content == remove){
        runner = (*runner).pointerToNext;
        continue;
      }
        std::cout<<(*runner).content<<" ";
        runner=(*runner).pointerToNext;
    }
    std::cout<<std::endl;

    // FREEING THE MEMORY
    freeTheMemory(head);
    return 0;
}
