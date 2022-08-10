#include <stdio.h>
#include "power.h"

//power rule for first degree
void powerRule1(int a, int b){

	printf("%d\n",a);
}

//power rule for second degree  

void powerRule2(int a, int b, int c){
	a = 2 * a;

	printf("%dx + %d\n",a, b);
}


//power rule for third degree  

void powerRule3(int a, int b, int c, int d){

	a = 3 * a;
	b = 2 * b;
	printf("%dx^2 + %dx + %d\n", a, b, c);
}

//power rule for forth degree  
void powerRule4(int a, int b, int c, int d, int e){
	a = 4 * a;
	b = 3 * b;
	c = 2 * c;

	printf("%dx^3 + %dx^2 + %dx + %d\n", a, b, c, d);
}
