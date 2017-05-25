// is_prime.cpp
// compile with
// c++ -o is_prime is_prime.cpp -std=c++11
// execute with
// ./is_prime

// Problem: The user enters the positive numbers greater than
// 1. Once the user enters 0, or a negative number, the user will
// enter no more numbers. For each of the numbers supplied by
// the user, determine whether it is prime or not.



#include<set>
#include<iostream>
typedef long int myint;
myint isPrime(std::set<myint> &allPrimes, myint n){
    if(n<2){
        return -1;
    }
    std::set<myint>::iterator it;
    it= allPrimes.find(n);
    if(it!=allPrimes.end()){
        
        return 1;
    }
    it=allPrimes.begin();
    myint helper=*it;
    myint isComposite=0;
    while( (helper*helper<=n)&&(isComposite==0) &&(it!=allPrimes.end()) ){
        if (n%helper==0){
            isComposite=1;
        }
        ++it;
        if(it!=allPrimes.end()){
            helper=*it;
        }
    }
    if(isComposite==1){
        return 0;
    }
    helper+=2;
    myint isHelperAPrime;
    while( (helper*helper<=n) && (isComposite==0)){
        isHelperAPrime=isPrime(allPrimes,helper);
        if(isHelperAPrime==1){
            if(n%helper==0){
                isComposite=1;
            }
        }
        helper+=2;
    }
    if(isComposite==1){
        return 0;
    }
    allPrimes.insert(n);
    return 1;
    
}
int main(){
    myint userInput;
    std::set<myint> allPrimeNumbers;
    allPrimeNumbers.insert(2);allPrimeNumbers.insert(3);
    allPrimeNumbers.insert(5);
    userInput=2;
    while(userInput>0){
        std::cin>>userInput;
        if(userInput>0){
            std::cout<<"The number "<<userInput;
            if(isPrime(allPrimeNumbers,userInput)==1){
                std::cout <<" is prime.";
            }
            else{
                std::cout<<" is not prime.";
            }
            std::cout<<std::endl;
        }
    }
    return 0;
}
