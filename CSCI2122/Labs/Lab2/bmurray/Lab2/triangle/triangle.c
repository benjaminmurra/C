#include <stdio.h>
#include "triangle.h"
#include <math.h>
//print function
void printing(double a, double b, double c, double x, double y){  
	printf("\nopposite = %.2lf\nadjacent = %.2lf\nhypotenuse = %.2lf\nx = %.2lf\ny = %.2lf\n\n", a, b, c, x, y);    
}

//calculate opposite side using pythagorean theorem and print 
double findOppositePyth(double b, double c, double x, double y){
	double a=(pow(c,2)-pow(b,2));
	a=sqrt(a);

	printing(a, b, c, x, y); 
	return a;
}

//calculate adjacent side: using pythagorean theorem and print 
double  findAdjacentPyth(double a, double c, double x, double y){
	double b = (pow(c, 2)-pow(a, 2));
	b = sqrt(b);
	printing(a, b, c, x, y);

	return b;
}

//calculate hypotenuse using pythagorean theorem and print
double findHypotenusePyth(double a, double b, double x, double y){
	double c =(pow(a, 2) + pow(b, 2));
	c = sqrt(c);
	printing(a, b, c, x, y);

	return c; 
}

//calculate opposite side using trig and print
double  findOppositeTrig(double b, double c, double x, double y){
	double a = sin(x)*c;
	printing(a, b, c, x, y); 

	return a;
}

//calculate adjacent side using trig and print
double  findAdjacentTrig(double a, double c, double x, double y){
	double b = cos(x)*c;
	printing(a, b, c, x, y);

	return b;
}

//calculate hypotenuse using trig function and print
double findHypotenuseTrig(double a, double b, double x, double y){
	double c = b / cos(x);
	printing(a, b, c, x, y); 

	return c;

}
