#include<iostream>
#include<cmath>


int factorial(int number) {
	int temp;

	if(number <= 1) return 1;

	temp = number * factorial(number - 1);
	return temp;
}

int sumOfDigits(int x){
  int powto10, i = 0;
  while(powto10 < x){
   powto10 =  pow(10,i); // base to the exponent
   ++i;
  }
  --i;
  int digit = 0;
  int sum = 0;
  int remain;
  while(i > 0){
    powto10 = pow(10,i - 1);
    remain = x%powto10;
    digit = (x - remain)/powto10;
    x = x - (digit*powto10);
    sum += digit;
    --i;
  }
  return sum;
}

int main() {
  std::cout << "enter the positive integer: ";
  int input;
  std::cin >> input;
  int sum = sumOfDigits(input);
  std::cout << "sum of digits: " << sum << std::endl;
  return 0;
}
