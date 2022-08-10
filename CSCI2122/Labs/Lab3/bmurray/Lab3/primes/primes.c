#include <stdio.h>
#include "primes.h"
#include <math.h>

void primes(long n) { 

	//if number is even print 2 and divide n by 2
	while (n%2 == 0){ 
		printf("%d ", 2); 
		n = n/2; 
	} 
	//check each number from 3 to the squareroot of n  
	for (int i = 3; i <= sqrt(n); i = i+2){ 
		while (n%i == 0) { 
			printf("%d ", i); 
			n = n/i; 
		} 
	}
       //print final number	
	if (n > 2){ 
		printf ("%ld \n", n); 
	}

	else{
		printf ("\n");
	}
}
