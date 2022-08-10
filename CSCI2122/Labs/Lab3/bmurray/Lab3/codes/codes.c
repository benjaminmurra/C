#include <stdio.h>
#include "codes.h"


int encrypt(int a,int b, char c){
	int reverse=0;
	for(int i=0;i<8;i++){
		reverse= (reverse<<1)|(c&1);
		c=c>>1;
	}
	reverse= reverse<<a;
	reverse= reverse>>b;
	return reverse;
}
char decrypt(int a, int b, int c){
	int reverse=0;
	c= c<<b; 
	 c= c>>a;
	 for(int i=0;i<8;i++){
		 reverse= (reverse<<1)|(c&1);
		 c=c>>1;
	 }
	 char y= reverse;
	 return y;
}
