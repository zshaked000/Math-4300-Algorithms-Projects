#include<iostream>
#include <cmath>
using namespace std;
int main(){
  cout << "enter n:  ";
  int n; cin >> n;
  int sum = 0;
  int input = 0;
for(int i = 0; i < n; ++i){
  cin >> input;
  sum = sum xor input;
}
cout << "nimsum: " << sum <<endl;
return 0;
}
