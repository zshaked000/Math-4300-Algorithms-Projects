//problem1.75.cpp
#include<iostream>
#include<cmath>


int factorial(int number) {
	int temp;

	if(number <= 1) return 1;

	temp = number * factorial(number - 1);
	return temp;
}

int sumOfDigitsCubed(int *x, int size){
	int sum = 0;
	for(int i = 0; i < size; ++i){
		 sum += pow(x[i],3);
	}
	return sum;
}

void findTheNumber(int x = 0){
  int powto10, i = 0;
  while(powto10 < x){
   powto10 =  pow(10,i); // base to the exponent
   ++i;
  }
  --i;
  int digit = 0;
  int sum = 0;
  int remain;
	int size = i;
	int *seq = new int[i];
  while(i > 0){
    powto10 = pow(10,i - 1);
    remain = x%powto10;
    digit = (x - remain)/powto10;
    x = x - (digit*powto10);
    seq[i] = digit;
  }
		if (x < 10000) {
			std::cout << "all good " << '\n';
			if(sumOfDigitsCubed(seq,size) == x){
				std::cout << "x: " << x << "\t sum: " << sumOfDigitsCubed(seq,size) <<'\n';
				delete[] seq;
			}
			findTheNumber(x++);
		}
}


int main() {
	findTheNumber(0);
  // int sum = sumOfDigits(input);
  // std::cout << "sum of digits: " << sum << std::endl;
  return 0;
}
