#include<iostream>

using namespace std;

struct node{
int data;
node *next;
/*you cant have Node next; becuase node would contain itself
creating an infintie loop of nodes being created leading to an error
by Declaring node *next; as a pointer the compiler can now figure out how
much memory to allocate
*/
//constructor

node(int d , node  *n){
 data = d;
 next = n;}
};

using namespace std;

int main(){

node n1(1,NULL),n2(2,&n1),n3(3,&n2),n4(4,&n3);
node n = n4;
int i = 0;
while(n.next != NULL)
{
++i;
cout << "node " << i << endl;
cout <<  "data: " << n.data << endl;
cout << endl;
&n = n.next;
}
return 0;

}
