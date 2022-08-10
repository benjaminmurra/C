#include <stdio.h>
#include "coins.h"

void calculateCoins(int amount){ 

	int leftover; // hold amount as it decreases
	int numdollars; // dollar amount 
	int numquarters; // quarters amount
	int numdimes; // dime amount
	int numnickels; // nickels amount
	int numpennies; // pennies amount
	leftover = amount;    

	//compute the dollar amount and leftover
	 numdollars=leftover / 100;
	 leftover=leftover % 100;
	//compute the dollar amount and leftover
	 numquarters = leftover / 25; 
	 leftover = leftover % 25;   

	 //compute dime amount and leftover
	 numdimes = leftover / 10;
	 leftover = leftover % 10;
	 //compute nickel amount and leftover
	  numnickels = leftover / 5;
	  leftover = leftover % 5;
	 // remainder is the number of pennies
	  numpennies = leftover;
	 // print the result
	  printf("%d dollars, %d quarters, %d dimes, %d nickels, %d pennies\n", numdollars, numquarters, numdimes, numnickels, numpennies);
}       

