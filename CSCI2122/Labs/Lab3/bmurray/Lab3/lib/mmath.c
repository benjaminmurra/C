#include <stdio.h>
#include "mmath.h"

// function to find factorial of given number 
long fact(int n) {
	long k = 1;
        for (int i = 1; i <= n; ++i) {
		k *= i;
       	}

	return k;
}

//function to find n choose k
long nchoosek(int n, int k){
	long result=1;

	for (int i = 1; i <= k; i++){
		result *= n - (k - i);
		result /= i;
	}
	return result;
}
//function to find if number is prime or not
int prime(long p){
	int primeCheck = 1;

	for (int i = 2; i <= p / 2; ++i) {

		if (p % i == 0) {
			primeCheck = 0;
			break;
		}
	}
	// if p is 1 or 0 return 0 as neither are prime numbers
	if (p == 1 || p == 0) {
		return 0; 
	}

	else {
		return primeCheck;
	}
}

//function to calcualte GCD of two ints
int gcd(int a, int b){
	int result;
	
	for(int i = 1; i <= a && i <= b; ++i) {

		//checks if i is is a common factor of a and b
		if (a % i == 0 && b % i==0)
			result = i;
	}

	return result;
}
//function to find least common denominator
int lcm(int a, int b) {
	int gcdIs, lcm;
	//call gcd function to get GCD of a and b
	gcdIs = gcd(a, b);

	lcm = (a * b) / gcdIs;

	return lcm;
}

char bitrevc(char a){
	//Convert character to int for accii value.
	
	int ascii = a;
	int rev = 0;
	char returnChar;

	//loop  8 times for each bit.
	for(int i=0;i<8;i++){
		rev = (rev << 1) | (a & 1);
		a = a >> 1;
	}
	       
	//Converting int back to char         
	returnChar=rev;
	    
	//return character after reverse
	return returnChar;
}
